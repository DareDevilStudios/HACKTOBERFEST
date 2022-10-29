# from django.contrib.auth import get_user_model #? May be needed
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from .models import User
from django import forms


class UserCreateForm(UserCreationForm):
    class Meta:
        fields = ("username", "first_name", "last_name", "email", "password1", "password2", "user_type", "gender", "phone")

        model = User #? Might be or might not be needed. 
        #! IF NOT NEEDED BECAUSE AUTH_USER_MODEL SET IN SETTINGS.PY

        widgets = {
            'user_type': forms.RadioSelect,
            'gender': forms.RadioSelect,
        }

