from django.urls import path, include
from . import views

app_name = 'appointment'
urlpatterns = [
    path('select-doctor', views.doctor_list, name='doc-list'),\
    path('appointment-form', views.appointment_form, name='appointment-form'),
    path('appointment-book', views.appointment_book, name='appointment-book'),
    path('appointment-list', views.appointment_list, name='appointment-list'),
    path('cancel-appointment', views.cancel_appointment, name='cancel-appointment'),
    path('patient-completed-appointment', views.patient_completed_appointment, name='patient-completed-appointment'),
    path('doctor/pending-appointments', views.pending_appointments, {'status': False}, name='pending-appointment'), #* Pass extra option to function as dictionary
    path('doctor/completed-appointments', views.pending_appointments, {'status': True}, name='completed-appointment'),#* More info : https://django-book.readthedocs.io/en/latest/chapter08.html#passing-extra-options-to-view-functions
    path('doctor/view-appointment', views.view_appointment, name='view-appointment'),
    path('doctor/result', views.result, name='result'),
    path('doctor/view-past-history',views.past_history,name='past-history'),
    path('view-past-prescription',views.past_prescription,name='past-prescription')
]