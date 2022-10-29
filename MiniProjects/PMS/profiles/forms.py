from django import forms
from .models import *

#? If date input type ever breaks: https://stackoverflow.com/questions/3367091/whats-the-cleanest-simplest-to-get-running-datepicker-in-django
class DateInput(forms.DateInput):
    input_type = 'date'

class PatientProfileUpdateForm(forms.ModelForm):
    class Meta:
        model = PatientProfile
        fields = ('profile_pic', 'dob', 'blood_group', 'allergies')

        widgets = {
            'dob': DateInput(),
        }


class DoctorProfileUpdateForm(forms.ModelForm):
    class Meta:
        model = DoctorProfile
        fields = ('profile_pic', 'qualification', 'department')
        
