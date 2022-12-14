# Generated by Django 4.1 on 2022-08-26 20:57

import appointment.models
from django.db import migrations, models
import functools


class Migration(migrations.Migration):

    dependencies = [
        ('appointment', '0010_remove_appointment_ct_remove_appointment_diagnosis_and_more'),
    ]

    operations = [
        migrations.AlterField(
            model_name='report',
            name='ct',
            field=models.FileField(blank=True, null=True, upload_to=functools.partial(appointment.models.path_and_rename, *('files/ct', 'ct'), **{})),
        ),
        migrations.AlterField(
            model_name='report',
            name='test_report',
            field=models.FileField(blank=True, null=True, upload_to=functools.partial(appointment.models.path_and_rename, *('files/report', 'report'), **{})),
        ),
        migrations.AlterField(
            model_name='report',
            name='xray',
            field=models.FileField(blank=True, null=True, upload_to=functools.partial(appointment.models.path_and_rename, *('files/xray', 'xray'), **{})),
        ),
    ]
