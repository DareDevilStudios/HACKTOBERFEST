import os
from functools import partial
from django.db import models, connection
from accounts.models import User
from hospital.models import Medicine

#* More info on upload_to function: https://docs.djangoproject.com/en/4.1/ref/models/fields/#django.db.models.FileField.upload_to
#* Rename uploaded report file: https://stackoverflow.com/questions/15140942/django-imagefield-change-file-name-on-upload

def path_and_rename(instance, filename, upload_to, field_name):
    ext = filename.split('.')[-1]
    
    department = instance.appointment.doctor.docprofile.department.name
#     '''
#             SELECT DISTINCT
#                 department.name
#             FROM appointment
#             JOIN doctor_profile
#             ON doctor_profile.user_id = %s
#             JOIN department
#             ON department.id = doctor_profile.department_id
# ''', [app_id]
    filename = f'{instance.appointment.patient.username}_{instance.appointment.date}_{department}_{field_name}.{ext}'
    return os.path.join(upload_to, filename)

class Appointment(models.Model):
    TIME_SLOT = [
    (1, '9:00-10:00'),
    (2, '10:00-11:00'),
    (3, '11:00-12:00'),
    (4, '13:00-14:00'),
    ]

    doctor = models.ForeignKey(User,on_delete=models.CASCADE, limit_choices_to={'user_type': 'D'}, related_name='doctor')
    patient = models.ForeignKey(User,on_delete=models.CASCADE, limit_choices_to={'user_type': 'P'})
    date =  models.DateField()
    start_time = models.TimeField(null=True)
    end_time = models.TimeField(null=True)
    reason = models.TextField()
    status = models.BooleanField(default=False)

    class Meta:
        db_table = 'appointment'
        constraints = [
            models.UniqueConstraint(fields=['patient', 'doctor', 'date'], name='unique_booking')
        ]
        ordering = ['date', 'start_time']

    def __str__(self):
        return f"{self.doctor.get_full_name()}'s appointment with {self.patient.username} on {self.date}"


class Report(models.Model):
    class Meta:
        db_table = 'report'
        ordering = ['appointment__date', 'appointment__start_time']

    appointment = models.OneToOneField(Appointment, on_delete=models.CASCADE)
    test_report = models.FileField(null=True, blank=True, upload_to=partial(path_and_rename, upload_to='files/report', field_name='report'))
    xray = models.FileField(null=True, blank=True, upload_to=partial(path_and_rename, upload_to='files/xray', field_name='xray'))
    ct = models.FileField(null=True, blank=True, upload_to=partial(path_and_rename, upload_to='files/ct', field_name='ct'))
    diagnosis = models.TextField()

    def __str__(self):
        return f"{self.appointment.patient.username}'s report on {self.appointment.date}"


class Prescription(models.Model):
    class Meta:
        db_table = 'prescription'
        ordering = ['appointment__date', 'appointment__start_time']

    appointment = models.OneToOneField(Appointment, on_delete=models.CASCADE)
    medicine = models.ManyToManyField(Medicine) #* More on m2m relationship: https://www.revsys.com/tidbits/tips-using-djangos-manytomanyfield/, 
    #* https://docs.djangoproject.com/en/4.0/topics/db/models/#relationships-many-to-many
    #* https://dzone.com/articles/how-to-handle-a-many-to-many-relationship-in-datab

    # quantity = models.IntegerField() #? Dont know how to get quantity for each medicine
    #* Info on quanity: https://docs.djangoproject.com/en/4.0/topics/db/models/#extra-fields-on-many-to-many-relationships
    instructions = models.TextField()

    def __str__(self):
        return f"{self.appointment.patient.username}'s prescription on {self.appointment.date}"