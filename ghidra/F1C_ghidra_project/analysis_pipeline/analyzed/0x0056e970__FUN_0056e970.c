// Function: FUN_0056e970 @ 0056e970
// Size (bytes): 342


void __fastcall FUN_0056e970(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1[1];
  *param_1 = 0;
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + -4);
    if (-1 < iVar3 + -1) {
      do {
        thunk_FUN_00568f20();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00587bcf(iVar2 + -4);
    param_1[1] = 0;
  }
  iVar2 = param_1[3];
  param_1[2] = 0;
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + -4);
    iVar4 = iVar3 * 0x30 + iVar2;
    if (-1 < iVar3 + -1) {
      do {
        piVar1 = (int *)(iVar4 + -0x30);
        iVar4 = iVar4 + -0x30;
        if (*piVar1 != 0) {
          FUN_00587bcf(*piVar1);
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00587bcf(iVar2 + -4);
    param_1[3] = 0;
  }
  iVar2 = param_1[5];
  param_1[4] = 0;
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + -4);
    iVar4 = iVar3 * 0x30 + iVar2;
    if (-1 < iVar3 + -1) {
      do {
        piVar1 = (int *)(iVar4 + -0x30);
        iVar4 = iVar4 + -0x30;
        if (*piVar1 != 0) {
          FUN_00587bcf(*piVar1);
        }
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    FUN_00587bcf(iVar2 + -4);
    param_1[5] = 0;
  }
  iVar2 = param_1[7];
  param_1[6] = 0;
  if (iVar2 != 0) {
    iVar4 = *(int *)(iVar2 + -4);
    iVar3 = iVar2 + iVar4 * 0x48;
    if (-1 < iVar4 + -1) {
      do {
        piVar1 = (int *)(iVar3 + -0x48);
        iVar3 = iVar3 + -0x48;
        if (*piVar1 != 0) {
          FUN_00587bcf(*piVar1);
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    FUN_00587bcf(iVar2 + -4);
    param_1[7] = 0;
  }
  if (param_1[9] != 0) {
    FUN_00587bcf(param_1[9]);
    if (param_1[10] != 0) {
      FUN_00587bcf(param_1[10]);
    }
    if (param_1[0xb] != 0) {
      FUN_00587bcf(param_1[0xb]);
    }
  }
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  FUN_0056cf10();
  return;
}


