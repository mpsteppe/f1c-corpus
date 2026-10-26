// Function: FUN_00586170 @ 00586170
// Size (bytes): 105


void __fastcall FUN_00586170(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  BOOL BVar4;
  
  if ((*(char *)(param_1 + 6) != '\0') && (BVar4 = CloseHandle((HANDLE)param_1[4]), BVar4 != 0)) {
    param_1[4] = 0;
  }
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
      FUN_005867b0();
      FUN_00587bcf(iVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


