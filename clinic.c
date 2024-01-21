
#include "clinic.h"

// patient_t client;
int patientCount = 0;
patient_t *Clinic = NULL;

void create_patient(void)
{
  // create Patient and PatientData node
  patient_t *newPatient = calloc(1, sizeof(patient_t));
  patientData_t *newPatientData = calloc(1, sizeof(patientData_t));
  newPatient->data = newPatientData;
  newPatient->next = NULL;

  // variables to get data from user ( clinic employee )
  char name[50] = "\0", phoneNumber[12] = "\0";
  int patient_age = 0;
  int patient_id = 0;

  // scanf("%s %s %d %f", name, phoneNumber, &patient_age, &patient_id);
  // fflush(stdin);
  while ((getchar()) != '\n')
    ;
  printf("Enter Patient Name: ");
  gets(name);
  // scanf("%[^\n]%*c", name);
  fflush(stdin);
  printf("Enter Patient phone number : ");
  scanf("%s", phoneNumber);
  fflush(stdin);
  printf("Enter The patient age : ");
  scanf("%d", &patient_age);
  printf("Enter The patient id : ");
  scanf("%d", &patient_id);

  strcpy(newPatientData->name, name);
  strcpy(newPatientData->phoneNumber, phoneNumber);
  newPatientData->age = patient_age;
  newPatientData->id = patient_id;

  if (NULL == Clinic)
  {
    // Clinic is empty
    Clinic = newPatient;
  }
  else
  {
    // Clinic is not empty and we add the client at the end of Clinic list
    patient_t *iterator = Clinic;
    while (iterator->next != NULL)
    {
      iterator = iterator->next;
    }
    iterator->next = newPatient;
  }
  patientCount++;
  printf(" patient record created successfully \n");
}

void edit_patient_data(void)
{
  patient_t *iterator = Clinic;

  int patient_id = 0;
  int i = 0;
  printf("Enter The patient id : ");
  scanf("%d", &patient_id);

  while (iterator != NULL)
  {
    i++;
    if (patient_id == iterator->data->id)
    {
      printf("patient %d : %s %s %d %d\n", i, iterator->data->name, iterator->data->phoneNumber, iterator->data->age, iterator->data->id);
      break;
    }

    iterator = iterator->next;
  }

  if (NULL == iterator)
  {
    printf(" Can't found this patient in clinic.\n");
  }
  else
  {
    // patient founded and pointed with iterator variable
    char name[50] = "\0", phoneNumber[12] = "\0";
    int age = 0;
    // getting new data section
    // fflush(stdin);
    while ((getchar()) != '\n') // clear buffer
      ;
    printf("Enter updated patient Name: ");
    gets(name);
    fflush(stdin);
    printf("Enter updated phone number: ");
    scanf("%s", phoneNumber);
    fflush(stdin);
    printf("Enter The updated age : ");
    scanf("%d", &age);

    // edit patient data in clinic List
    strcpy(iterator->data->name, name);
    strcpy(iterator->data->phoneNumber, phoneNumber);
    iterator->data->age = age;

    //

    printf("patient record is updated to\n");
    printf("patient %d : %s %s %d %d\n", i, iterator->data->name, iterator->data->phoneNumber, iterator->data->age, iterator->data->id);
  }
  printf(" patient record is updated.\n");
}

void delete_patient(void)
{
  patient_t *iterator = Clinic;
  // get the patient id that will deleted from user.
  int patient_id = 0;
  int i = 0;
  printf("Enter The patient id : ");
  scanf("%d", &patient_id);

  // if patient stored in head of list
  if (iterator->data->id == patient_id)
  {
    printf("patient %d : %s %s %d %d\n", (i + 1), iterator->data->name, iterator->data->phoneNumber, iterator->data->age, iterator->data->id);
    Clinic = iterator->next;
    patientCount--;
    printf(" patient record is deleted\n");
  }
  else
  {
    // make iterator point to the previous node (patient) of the node which will deleted.
    while (NULL != iterator)
    {
      i++;
      if (patient_id == iterator->next->data->id)
      {
        printf("patient %d : %s %s %d %d\n", (i + 1), iterator->next->data->name, iterator->next->data->phoneNumber, iterator->next->data->age, iterator->next->data->id);
        break;
      }

      iterator = iterator->next;
    }

    if (iterator == NULL)
    {
      printf(" Can't found this patient in clinic.\n");
    }
    else
    {
      // patient founded and pointed with iterator->next
      iterator->next = iterator->next->next;
      patientCount--;
      printf(" patient record is deleted\n");
    }
  }
}

void print_patient_data(void)
{
  patient_t *iterator = Clinic;

  int patient_id = 0;
  int i = 0;
  printf("Enter The patient id : ");
  scanf("%d", &patient_id);

  while (iterator != NULL)
  {
    i++;
    if (patient_id == iterator->data->id)
    {
      printf("patient %d : %s %s %d %d\n", i, iterator->data->name, iterator->data->phoneNumber, iterator->data->age, iterator->data->id);
      break;
    }

    iterator = iterator->next;
  }

  if (iterator == NULL)
  {
    printf(" Can't found this patient in clinic.\n");
  }
}

void print_all_patients(void)
{
  if (Clinic == NULL)
  {
    // Clinic is empty
    printf("Clinic has %d patients\n", patientCount);
  }
  else
  {
    patient_t *iterator = Clinic;
    int i = 1;
    printf("Clinic has %d patients\n", patientCount);
    printf("=============================================\n");
    printf("%-13s | %-50s | %-12s | %-3s | %s \n", "patient number", "name", "phone Number", "age", "id");
    printf("=============================================\n");
    while (iterator != NULL)
    {
      printf("patient %06d | %-50s | %-12s | %d | %d \n", i++, iterator->data->name, iterator->data->phoneNumber, iterator->data->age, iterator->data->id);
      iterator = iterator->next;
    }
  }

  printf("=============================================\n");
}