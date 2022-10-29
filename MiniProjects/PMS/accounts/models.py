from django.db import models
from django.contrib.auth.models import AbstractUser
from phonenumber_field.modelfields import PhoneNumberField


class User(AbstractUser):
    DOCTOR = 'D'
    PATIENT = 'P'

    USER_TYPES = [
        (DOCTOR, 'Doctor'),
        (PATIENT, 'Patient'),
    ]

    MALE = 'M'
    FEMALE = 'F'
    OTHER = 'O'
    PREFER_NOT_TO_SAY = 'N'
    GENDER = [
        (MALE, 'Male'),
        (FEMALE, 'Female'),
        (OTHER, 'Other'),
        (PREFER_NOT_TO_SAY, 'Prefer not to say')
    ]

    class Meta:
        db_table = 'user'
    
    user_type = models.CharField(choices=USER_TYPES, max_length=1, default=PATIENT)
    gender = models.CharField(choices=GENDER,  max_length=1, default=PREFER_NOT_TO_SAY)
    phone = PhoneNumberField(null=True, blank=True) 


    def is_doctor(self):
        if self.user_type == 'D':
            return True

        return False

    def is_patient(self):
        if self.user_type == 'P':
            return True

        return False

    def get_gender(self):
        match self.gender:
            case self.MALE:
                return 'Male'
            case self.FEMALE:
                return 'Female'
            case self.OTHER:
                return 'Other'
            case self.PREFER_NOT_TO_SAY:
                return 'Prefer not to say'