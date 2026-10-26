// Function: FUN_004a29a0 @ 004a29a0
// Size (bytes): 146


void __fastcall FUN_004a29a0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (0 < (int)param_1[3]) {
    iVar2 = 0;
    do {
      *(undefined4 *)(param_1[4] + 100 + iVar2) = 0;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x78;
    } while (iVar1 < (int)param_1[3]);
  }
  iVar1 = param_1[4];
  param_1[3] = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004a2220();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar1 + -4);
  }
  param_1[4] = 0;
  if ((DAT_008afe88 != 0) && (param_1[5] != 0)) {
    FUN_00545150(param_1[5]);
  }
  param_1[5] = 0;
  return;
}


