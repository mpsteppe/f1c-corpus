// Function: FUN_0057a610 @ 0057a610
// Size (bytes): 78


undefined4 FUN_0057a610(float *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  float10 fVar2;
  double local_8;
  
  fVar2 = (float10)FUN_00584f90();
  cVar1 = FUN_00583790(&local_8,param_2,param_3,(double)fVar2);
  if (cVar1 != '\0') {
    *param_1 = (float)local_8;
    return 1;
  }
  return 0;
}


