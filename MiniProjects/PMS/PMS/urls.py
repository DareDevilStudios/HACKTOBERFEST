from django.contrib import admin
from django.urls import path, include
from django.conf import settings
from django.conf.urls.static import static
from django.contrib.auth import views as auth_views

#* For info on URL namespace, see: https://docs.djangoproject.com/en/4.0/topics/http/urls/#id5
urlpatterns = [
    path('__debug__/', include('debug_toolbar.urls')),
    path('admin/', admin.site.urls),
    path('', include('accounts.urls', namespace='accounts')),
    path('', include('profiles.urls', namespace='profiles')),
    path('', include('appointment.urls', namespace='appointment')),
    path('password_reset/done/', auth_views.PasswordResetDoneView.as_view(template_name='password/password_reset_done.html'), name='password_reset_done'),
    path('reset/<uidb64>/<token>/', auth_views.PasswordResetConfirmView.as_view(template_name="password/password_reset_confirm.html"), name='password_reset_confirm'),
    path('reset/done/', auth_views.PasswordResetCompleteView.as_view(template_name='password/password_reset_complete.html'), name='password_reset_complete'),
]#+ static(settings.STATIC_URL, document_root=settings.STATIC_ROOT) #?May need this for static files
#* For info on static files, see: https://testdriven.io/blog/django-static-files/
urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
