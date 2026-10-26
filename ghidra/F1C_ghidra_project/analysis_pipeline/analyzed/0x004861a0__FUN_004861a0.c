// Function: FUN_004861a0 @ 004861a0
// Size (bytes): 151


void FUN_004861a0(int param_1,int param_2)

{
  int local_8;
  int local_4;
  
  if ((char)param_1 != '\0') {
    FUN_00499ee0(&param_1,&local_8);
    if ((0 < param_1) && (0 < local_8)) {
      FUN_0049aa70(param_1,local_8);
    }
  }
  if ((char)param_2 != '\0') {
    FUN_00499f00(&param_1,&local_4,&local_8,&param_2);
    if ((((param_1 != 0) || (local_4 != 0)) || (local_8 != 0)) || (param_2 != 0)) {
      FUN_0049aa10(param_1,local_4,local_8,param_2);
    }
  }
  return;
}


