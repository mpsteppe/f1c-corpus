// Function: FUN_0044c470 @ 0044c470
// Size (bytes): 78


void __fastcall FUN_0044c470(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    FUN_00587bcf(param_1[1] + -4);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  piVar2 = param_1 + 10;
  for (iVar1 = 0x400; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  return;
}


