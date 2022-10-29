from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.contrib.auth.decorators import login_required
from django.contrib import messages
from accounts.models import User
from .models import *
from .forms import *

@login_required(login_url='accounts:login')
def profile(request):
    user = request.user
    if user.is_doctor():
        return redirect('profiles:doctor-profile')


    if PatientProfile.objects.filter(user=user).exists():
        profile = PatientProfile.objects.get(user=user)
    else:
        profile = PatientProfile(user=user)

    if request.method == 'POST':
        form = PatientProfileUpdateForm(request.POST, instance=profile, files=request.FILES) #* files is used to upload files
        if form.is_valid():
            form.save()
            messages.add_message(request, messages.INFO, 'Profile updated successfully')
            return redirect('accounts:home')
    else:
        form = PatientProfileUpdateForm(instance=profile)
    return render(request, 'profile.html', {'form': form})


@login_required(login_url='accounts:login')
def doctor_profile(request):
    user = request.user
    if user.is_patient():
        return redirect('profiles:profile')


    if DoctorProfile.objects.filter(user=user).exists():
        profile = DoctorProfile.objects.get(user=user)
    else:
        profile = DoctorProfile(user=user)

    if request.method == 'POST':
        form = DoctorProfileUpdateForm(request.POST, instance=profile, files=request.FILES) #* files is used to upload files
        if form.is_valid():
            form.save()
            messages.add_message(request, messages.INFO, 'Profile updated successfully')
            return redirect('accounts:home')
    else:
        form = DoctorProfileUpdateForm(instance=profile)
    return render(request, 'profile.html', {'form': form})
