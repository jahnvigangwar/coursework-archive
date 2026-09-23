from django.contrib import admin
from django.urls import path
from home import views

admin.site.site_header = "Jahnvi's Django APP Admin"
admin.site.site_title = "Jahnvi's Django APP Admin Portal"
admin.site.index_title = "Welcome to Jahnvi's Django APP Portal"

urlpatterns = [
    path('', views.index, name='index'),
    path('about', views.about, name='about'),
    path('services', views.services, name='services'),
    path('contact', views.contact, name='contact'),
]
