#include "clinic.h"

int main()
{

  while (1)
  {
    printf("\n Clinic Management System\n");
    printf(" please enter number between 1 and 6\n\n 1- create patient record into the clinic\n 2- edit patient record's data\n 3- delete patient record from the clinic (cancel the reservation)\n 4- print patient record\n 5- print all patients records in the clinic\n 6- close the system of clinic\n");
    int choise = 0;
    scanf("%d", &choise);

    switch (choise)
    {
    case 1:
      create_patient();
      break;
    case 2:
      edit_patient_data();
      break;
    case 3:
      delete_patient();
      break;
    case 4:
      print_patient_data();
      break;
    case 5:
      print_all_patients();
      break;
    case 6:
      system("pause");
      return 0;
    default:
      printf("please enter number between 1 and 6.\n");
      break;
    }
  }
}