from datetime import date
from django.db import models
from accounts.models import User
from hospital.models import Department

class PatientProfile(models.Model):

    BLOOD_GROUPS = [
        ('O-', 'O-'),
        ('O+', 'O+'),
        ('A-', 'A-'),
        ('A+', 'A+'),
        ('B-', 'B-'),
        ('B+', 'B+'),
        ('AB-', 'AB-'),
        ('AB+', 'AB+'),
    ]

    class Meta:
        db_table = 'patient_profile'


    user = models.OneToOneField(
        User, on_delete=models.CASCADE, #profile deleted then patient deleted since one to one field
        primary_key=True, limit_choices_to={'user_type': 'P'}, 
        related_name='patprofile', #* related_name is used to give alternate name to the reverse relationship
        )
    profile_pic = models.ImageField(upload_to='images/profiles/patients', null=True, blank=True) #TODO Change directory to /images/patient/username
    dob = models.DateField(blank=True, null=True) #TODO -remove blank=True, null=True
    blood_group = models.CharField(max_length=3, choices=BLOOD_GROUPS)
    allergies = models.TextField(blank=True, null=True)

    def __str__(self) -> str:
        return f"{self.user.username}'s profile"

    def get_age(self):
        birthdate = self.dob
        today = date.today()
        age = today.year - birthdate.year - ((today.month, today.day) < (birthdate.month, birthdate.day))
        return age


class DoctorProfile(models.Model):
    class Meta:
        db_table = 'doctor_profile'


    user = models.OneToOneField(
        User, on_delete=models.CASCADE, 
        primary_key=True, limit_choices_to={'user_type': 'D'}, 
        related_name='docprofile', #* related_name is used to give alternate name to the reverse relationship
        )
    profile_pic = models.ImageField(upload_to='images/profiles/doctors') #TODO Change directory to /images/doctor/username
    qualification = models.CharField(max_length=100, blank=True, null=True)
    department = models.ForeignKey(Department, on_delete=models.CASCADE)


    def __str__(self) -> str:
        return f"{self.user.username}'s profile"

