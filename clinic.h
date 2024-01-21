
#ifndef CLINIC_H
#define CLINIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patientData
{
  char name[50];
  char phoneNumber[12];
  int age;
  int id;
} patientData_t;

typedef struct patient
{
  patientData_t *data;
  struct patient *next;
} patient_t;

void create_patient(void);
void edit_patient_data(void);
void delete_patient(void);
void print_patient_data(void);
void print_all_patients(void);

#endif