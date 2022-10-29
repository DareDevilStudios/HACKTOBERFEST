from django.contrib import admin
from appointment.models import Appointment, Prescription, Report

#* Info on search fields in admin: https://projectsplaza.com/how-to-create-search-field-in-django-admin/
class AppointmentAdminModel(admin.ModelAdmin):
    #* More info on use of __username: https://blndxp.wordpress.com/2017/04/11/django-amdin-related-field-got-invalid-lookup-icontains/
    search_fields = ('patient__username', 'doctor__username', 'doctor__docprofile__department__name') 
    list_display = ('patient', 'doctor', 'date', 'start_time', 'status')
    list_filter = ('status', 'date',)


class PrescriptionAdminModel(admin.ModelAdmin):
    search_fields = ('appointment__patient__username', 'appointment__doctor__username')
    list_display = ('__str__', 'id',)


class ReportAdminModel(admin.ModelAdmin):
    search_fields = ('appointment__patient__username', 'appointment__doctor__username')
    list_display = ('__str__', 'id')
#TODO - add search field for prescription
admin.site.register(Appointment, AppointmentAdminModel)
admin.site.register(Prescription, PrescriptionAdminModel)
admin.site.register(Report, ReportAdminModel)