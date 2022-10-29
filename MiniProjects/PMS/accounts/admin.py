from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from .models import User

#* For more info on inserting fields in admin page, see:
#*  https://stackoverflow.com/questions/48011275/custom-user-model-fields-abstractuser-not-showing-in-django-admin
fields = list(UserAdmin.fieldsets)
fields.insert(2, ('Other Info', {'fields': ('user_type', 'gender', 'phone')}))
UserAdmin.fieldsets = tuple(fields)


class UserAdminModel(UserAdmin):
    UserAdmin.list_display += ('user_type', )
    UserAdmin.list_filter += ('user_type',)
admin.site.register(User, UserAdminModel) 