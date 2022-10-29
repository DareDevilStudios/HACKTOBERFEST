from django.db import models

class Department(models.Model):
    class Meta:
        db_table = 'department'
    
    name = models.CharField(max_length=100)
    
    def __str__(self) -> str:
        return self.name

class Medicine(models.Model):
    class Meta:
        db_table = 'medicine'
        
    name = models.CharField(max_length=100)
    price = models.FloatField(blank=True, null=True)
    # quantity = models.IntegerField(blank=True, null=True) #TODO - implement stock management
    
    def __str__(self) -> str:
        return self.name