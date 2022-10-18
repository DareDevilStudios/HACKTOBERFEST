var encryptor = require('file-encryptor');
var key = 'trikoo';
const { google } = require('googleapis')
require("dotenv").config();
const bcrypt = require('bcrypt');
const Joi = require('joi');
const mongoose = require('mongoose');
const express = require('express');
const path = require('path');
const fs = require('fs');
const upload = require('express-fileupload');
const { array } = require('joi');
const http = require('http');
const app = express();
const bodyparser = require('body-parser');

require('./prod')(app);


mongoose.connect(process.env.DATABASE,{
    useNewUrlParser: true,
    useUnifiedTopology: true,
})
.then(() => console.log('Connected to MongoDB'))
.catch(err => console.log('Error connecting to MongoDB', err))

const CLIENT_ID = '831866956829-67qibfdkdksbhdn5ojl9tkvlrf10mhfm.apps.googleusercontent.com';
const CLIENT_SECRET = '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';
const REDIRECT_URI = 'https://developers.google.com/oauthplayground';

const REFERESH_TOKEN = '1//04C7LvPl4e1qhCgYIARAAGAQSNwF-L9Ir27Ke-YFvUuhST8f2kKk4p9J9tvY83NBgwegd2IA4-MmuIt_pUrkg5LiVKDH414rbADs';

const oauth2Client = new google.auth.OAuth2(
    CLIENT_ID,
    CLIENT_SECRET,
    REDIRECT_URI
);

oauth2Client.setCredentials({refresh_token: REFERESH_TOKEN})

const drive = google.drive({
    version: 'v3',
    auth: oauth2Client
})


const librain_reg = new mongoose.Schema({
    Register_number: Number,
    Username: String,
    email: { type: String },
    password: String,
    category: { type: String, default: "student" },
    librain_points: { type: Number, default: 0 }
});

const upload_schema = new mongoose.Schema({
    url: String, 
    path: String, 
    name: String,
    branch: String,
    sem: String,
    scheme: String,
    subject: String,
    material: String,
    upvote: {type:Number, default: 0},
    report: {type:Number, default: 0},
    report_msg:{type:String, default:""}
});

const upload_subject = new mongoose.Schema({
    _id: String,
    subject: Array, 
    branch: String, 
    sem: String,
    scheme: String
});


const Member = mongoose.model('Member', librain_reg);
const File = mongoose.model('File', upload_schema);
const Subject = mongoose.model('Subject', upload_subject);

app.use(bodyparser.json());
app.use(bodyparser.urlencoded({ extended: true }))
app.use(express.json());
app.use(upload());

app.use(express.static('public'))
app.use('/css', express.static(__dirname + '/public/css'))
app.use('/js', express.static(__dirname + '/public/js'))
app.use('/assets', express.static(__dirname + '/public/assets'))

// set

app.set('views', './views')
app.set('view engine', 'ejs');

// Routes

app.get('/', (req, res) => {
    res.render('login', { msg: "" });
})



app.get('/admin', async(req, res) => {

    await File.deleteMany({report:{ $gte:10}})
    
    const files = await File.find({report:{$gt : 0}});
    console.log(files);

    res.render('admin',{files})
})

app.get('/register', (req, res) => {
    res.render('register', { msg: "" });
})

app.get('/home', (req, res) => {
    res.render('home');
})

app.get('/branch', (req, res) => {
    res.render('branch')
})

app.get('/branch/:branch', (req, res) => { 
    res.render('sem_copy')
})

app.get('/branch/:branch/:sem/', (req, res) => {
    res.render('scheme');
})

app.get('/branch/:branch/:sem/:scheme/',async(req, res) => {

    let trikoo = await Subject.findOne({branch:req.params.branch, sem:req.params.sem, scheme:req.params.scheme});
    console.log(typeof req.params.sem)
    console.log(trikoo.subject);
    res.render('subject',{subjects:trikoo.subject});

})


app.get('/branch/:branch/:sem/:scheme/:subject/', (req, res) => {
    res.render('materials');
})

function toTitleCase(str) {
    return str.replace(
      /\w\S*/g,
      function(txt) {
        return txt.charAt(0).toUpperCase() + txt.substr(1).toLowerCase();
      }
    );
  }

app.get('/branch/:branch/:sem/:scheme/:subject/:material', async (req, res) => {

    var url_mod = "/branch/"+ req.params.branch +"/"+ req.params.sem+"/"+ req.params.scheme+"/"+ req.params.subject+"/"+ req.params.material+"/"
    console.log(JSON.stringify(url_mod));

    const reportfiles = await File.find({report: {$gte : 10}})
    console.log(reportfiles)

    if(reportfiles)
    {
        for (const file of reportfiles)
        {
            var path_ = file.path.split("/")
            
            await drive.files.delete({
                fileId:path_[5]
            })
        }
    }

    const files_del = await File.deleteMany({report:{$gte:10}})
    console.log(files_del);

    // if(req.params.sem == "1")
    // {
    //     const files = await File.find({sem:"1", scheme:['2015','2019'], subject:req.params.subject, material:req.params.material}).sort({ upvote: -1 }).exec();
    //     res.render('textbook', {files, header: toTitleCase(req.params.material),url_modd : url_mod});
    // }
    // else if(req.params.sem == "2")
    // {
    //     const files = await File.find({sem:"2", scheme:['2015','2019'], subject:req.params.subject, material:req.params.material}).sort({ upvote: -1 }).exec();
    //     res.render('textbook', {files, header: toTitleCase(req.params.material),url_modd : url_mod});
    // }
    // else
    // {
        const files = await File.find({material:req.params.material}).sort({ upvote: -1 }).exec();
        res.render('textbook', {files, header: toTitleCase(req.params.material),url_modd : url_mod})
    // }
    // {
    //     const files = await File.find({branch: req.params.branch, sem:req.params.sem, scheme:['2015','2019'], subject:req.params.subject, material:req.params.material}).sort({ upvote: -1 }).exec();
    //     res.render('textbook', {files, header: toTitleCase(req.params.material),url_modd : url_mod});
    // }
    
    // const files = await File.find({branch: req.params.branch, sem:req.params.sem, scheme:['2015','2019'], subject:req.params.subject, material:req.params.material}).sort({ upvote: -1 }).exec();
    // const files = await File.find({url : url_mod}).sort({ upvote: -1 }).exec();


    // res.render('textbook', {files, header: toTitleCase(req.params.material), id__ : files._id});
    // res.render('textbook', {files, header: toTitleCase(req.params.material),url_modd : url_mod});
})

app.get('/branch/:branch/:sem/:scheme/:subject/:material/report/:id__/', async (req, res) => {

    var url_mod = "/branch/"+ req.params.branch +"/"+ req.params.sem+"/"+ req.params.scheme+"/"+ req.params.subject+"/"+ req.params.material+"/"
    console.log(req.params.id__);
    res.render('report',{id : req.params.id__,url_:url_mod,spec_id : req.params.id__});

})

app.post('/delete/', async (req, res)=>{
    var id = req.body.hid;
    const file = await File.findOne({_id:id})
    var path_ = file.path.split("/")
    console.log(path_)
    
    const response_ = await drive.files.delete({
        fileId:path_[5]
    })
    
    const files = await File.deleteOne({_id:id})
    console.log(files);

    res.redirect('/admin')
})

app.post('/ignore/', async (req, res)=>{
    var id = req.body.hid;
    const files = await File.findOne({_id:id})

    files.report = 0;
    files.report_msg = "";
    console.log(files);

    await files.save();

    res.redirect('/admin')
})

app.post('/', async (req, res) => {

    let result = await Member.findOne({ Register_number: req.body.Register_number });
    console.log(result);
    if (!result) return res.render('login', { msg: "invalid register number or password" });

    const compare = await bcrypt.compare(req.body.password, result.password);
    if (!compare) return res.render('login', { msg: "invalid register number or password" });

    if(result.category == 'admin')
    {
        return res.redirect('/admin')
    }
    else
    {
        return res.render('home')
    }

})

app.post('/upload', async (req, res) => {
    if (!req.files)
        return res.end("Upload failed");

    // u_rl = JSON.stringify(req.get('Referrer'))

    var url_mod = req.body.hid
    console.log(url_mod)

    u__rl = url_mod.split("/")
    console.log(u__rl)

    
    const file = req.files.file;
    // file.tempFilePath = './public/upload/'
    const out = path.resolve(`./public/uploads/${file.name}`);
    //const filePath = path.join(__dirname, 'file.name');
    //const drive_url = "https://drive.google.com/drive/folders/1SUbz89BS_gIm_V5sNn8KfXg2OfDvm3Wa?usp=sharing"
    //const drive_url = "https://drive.google.com/drive/my-drive"
    fs.writeFileSync(out, file.data);

    console.log(file.name)
    console.log(out)
    console.log(file)

    const response = await drive.files.create({
        requestBody: {
            name: file.name,
            mimeType: file.mimetype,
        },
        media: {
            mimeType: file.mimetype,
            body: fs.createReadStream(out)
        }
    })

    console.log(response);
    
    const fileId = response.data.id;
    console.log(fileId);

    await drive.permissions.create({
        fileId: fileId,
        requestBody: {
            role:'reader',
            type:'anyone'
        }
    })

    const result = await drive.files.get({
        fileId: fileId,
        fields:'webViewLink , webContentLink',
    })
    console.log(result.data)




    const uploaded = new File({
        path: result.data.webViewLink,
        name: file.name,
        url: url_mod,
        branch: u__rl[2],
        sem: u__rl[3],
        scheme: u__rl[4],
        subject: u__rl[5],
        material: u__rl[6]
    });

    await uploaded.save();

    
    // res.write("<script>navigation.back()</script>");
    res.redirect(url_mod);
    // res.write("<script>window.location.href = window.location.href</script>");
    
    fs.unlinkSync(out)
})

app.post('/upvote', async (req, res)=>{
    var url_mod = req.body.hid;
    var id__ = req.body._idget;
    console.log(id__);

    var result = await File.findOne({_id : id__})
    // console.log(result);

    result.upvote+=1;

    await result.save();

    // console.log(result);

    res.redirect(url_mod);
})

app.post('/report', async (req, res) => {
    
    var re_msg = req.body.r_msg;
    var url = req.body.hid_url;
    // console.log(re_msg);
    var id = req.body.hid;
    var result = await File.findOne({_id : id})
    result.report_msg = re_msg;
    result.report+=1;
    // console.log(result);

    await result.save();

    res.redirect(url);
   
})

app.post('/register', (req, res) => {

    var Register_number = parseInt(req.body.Register_number);
    var Username = req.body.Username;
    var email = req.body.email;
    var password = req.body.password;

    async function register_member() {
        const member = new Member({
            Register_number: Register_number,
            Username: Username,
            email: email,
            password: password
        })

        const { error } = validateMember(member);
        const error_pass = error.details[0].message;
        if (error_pass != '"$__" is not allowed') {
            console.log(error_pass);
            if (error) return res.render('register', { msg: error_pass });
        }
        // return res.json ({ status: 'error', error: 'invalid Username'})
        // return res.status(400).send(error.details[0].message);
        const salt = await bcrypt.genSalt(10);
        console.log(salt);
        const hashed = await bcrypt.hash(member.password, salt);
        member.password = hashed;
        console.log(hashed);

        const result = await member.save();
        console.log(result);
        return res.redirect('/');
    }

    register_member();
})

function validateMember(member) {
    
    const schema = Joi.object({

        Register_number: Joi.number()
            .greater(3)
            .required(),

        Username: Joi.string()
            .alphanum()
            .min(3)
            .max(30)
            .required(),

        email: Joi.string()
            .email({ minDomainSegments: 2, tlds: { allow: ['com', 'net','in'] } }),

        password: Joi.string()
            .min(3)
            .max(10),

    })
    return schema.validate(member);

}

//Listen 

const port = process.env.PORT || 3000;

const server = http.createServer(app);

app.listen(port, () => {
    console.log(`listening on port: ${port}`);
})