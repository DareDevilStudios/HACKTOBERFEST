# Generated by Django 4.1 on 2022-08-28 06:44

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('appointment', '0012_alter_prescription_options_alter_report_options_and_more'),
    ]

    operations = [
        migrations.AlterField(
            model_name='report',
            name='appointment',
            field=models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, related_name='appointment', to='appointment.appointment'),
        ),
    ]