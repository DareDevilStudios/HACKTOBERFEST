from hospital.models import Department
from appointment.models import Appointment

def get_departments(request):
    departments = Department.objects.all()
    return {'departments': departments}


def get_time_slots(request):
    time_slot = Appointment.TIME_SLOT
    return {"time_slot": time_slot}