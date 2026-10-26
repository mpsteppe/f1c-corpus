// Function: FUN_004c5de0 @ 004c5de0
// Size (bytes): 109


void __fastcall FUN_004c5de0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_004c62c0();
  piVar3 = (int *)param_1[2];
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      if (*(int *)(iVar2 + 4) != 0) {
        FUN_00587bcf(*(int *)(iVar2 + 4));
      }
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
  }
  return;
}


