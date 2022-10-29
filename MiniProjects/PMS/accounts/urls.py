from django.urls import path, include
from django.contrib.auth import views as auth_views
from . import views
from django.contrib.auth import get_user_model

app_name = 'accounts' #* Add app_name for namespace

urlpatterns = [
    path('', views.home, name='home'),
    path('login', views.LoginFormView.as_view(
            template_name='login.html', 
            next_page='accounts:home',), 
            name='login'),
    path('logout', views.LogoutFormView.as_view(next_page='accounts:home'), name='logout'),
    path('sign-up', views.register, name='register'),
    path("password_reset", views.password_reset_request, name="password_reset")
]