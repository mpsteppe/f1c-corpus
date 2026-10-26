// Function: FUN_004b26d0 @ 004b26d0
// Size (bytes): 125


void FUN_004b26d0(float *param_1)

{
  char cVar1;
  short sVar2;
  
  cVar1 = __ftol();
  *param_1 = (float)(int)cVar1;
  sVar2 = __ftol();
  param_1[1] = (float)(int)sVar2;
  cVar1 = __ftol();
  param_1[2] = (float)(int)cVar1;
  return;
}


