// Function: FUN_00490b90 @ 00490b90
// Size (bytes): 359


void __fastcall FUN_00490b90(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if (0 < *param_1) {
    iVar6 = 0;
    do {
      FUN_004910d0(param_1[2] + iVar6);
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0x10;
    } while (iVar7 < *param_1);
  }
  piVar1 = param_1 + 3;
  FUN_004910d0(piVar1);
  piVar2 = param_1 + 7;
  FUN_004910d0(piVar2);
  piVar5 = param_1 + 0xb;
  FUN_004910d0(piVar5);
  iVar7 = param_1[2];
  if (iVar7 != 0) {
    iVar6 = *(int *)(iVar7 + -4);
    if (-1 < iVar6 + -1) {
      do {
        FUN_00491db0();
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    FUN_00587bcf(iVar7 + -4);
  }
  FUN_004b0170();
  piVar4 = (int *)*piVar5;
  while (piVar4 != (int *)0x0) {
    piVar3 = (int *)piVar4[1];
    if (((char)piVar4[2] != '\0') && (*piVar4 != 0)) {
      FUN_00491e60(1);
    }
    FUN_00587bcf(piVar4);
    piVar4 = piVar3;
  }
  *piVar5 = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  piVar5 = (int *)*piVar2;
  while (piVar5 != (int *)0x0) {
    piVar4 = (int *)piVar5[1];
    if (((char)piVar5[2] != '\0') && (*piVar5 != 0)) {
      FUN_00491e60(1);
    }
    FUN_00587bcf(piVar5);
    piVar5 = piVar4;
  }
  *piVar2 = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  piVar2 = (int *)*piVar1;
  while (piVar2 != (int *)0x0) {
    piVar5 = (int *)piVar2[1];
    if (((char)piVar2[2] != '\0') && (iVar7 = *piVar2, iVar7 != 0)) {
      FUN_004b0170();
      FUN_00587bcf(iVar7);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar5;
  }
  *piVar1 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}


