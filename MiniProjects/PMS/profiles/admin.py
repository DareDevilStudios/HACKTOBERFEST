from django.contrib import admin
from .models import *

#* Info on search fields in admin: https://projectsplaza.com/how-to-create-search-field-in-django-admin/
class PatientProfileAdminModel(admin.ModelAdmin):
    search_fields = ('user__username', ) #* More info on use of __username: https://blndxp.wordpress.com/2017/04/11/django-amdin-related-field-got-invalid-lookup-icontains/
    list_display = ('user', 'profile_pic', 'blood_group')
    list_filter = ('blood_group',)


class DoctorProfileAdminModel(admin.ModelAdmin):
    search_fields = ('user__username', )
    list_display = ('user', 'profile_pic', 'qualification', 'department')
    list_filter = ('department',)
admin.site.register(PatientProfile, PatientProfileAdminModel)
admin.site.register(DoctorProfile, DoctorProfileAdminModel)
