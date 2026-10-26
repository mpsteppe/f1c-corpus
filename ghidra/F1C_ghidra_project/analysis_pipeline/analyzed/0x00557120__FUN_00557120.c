// Function: FUN_00557120 @ 00557120
// Size (bytes): 287


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00557120(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  FUN_004b0170();
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x14c)) {
    iVar2 = 0;
    do {
      if (*(int *)(iVar2 + 0x10 + *(int *)(param_1 + 0x150)) != 0) {
        FUN_005503a0();
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 < *(int *)(param_1 + 0x14c));
  }
  for (iVar1 = *(int *)(param_1 + 0x15c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x34)) {
    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0xfffffff7;
  }
  if ((*(uint *)(param_1 + 0xec) & 0x800) != 0) {
    FUN_00545850();
    if ((*(uint *)(param_1 + 0xec) & 0x600000) != 0) {
      FUN_005570c0(*(undefined4 *)(param_1 + 0xf8));
    }
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xffbff7ff;
  }
  _DAT_008cef70 = 0;
  if (DAT_008b8df0 == 0) {
    FUN_005550a0();
  }
  if (0 < *(int *)(param_1 + 0x16c)) {
    FUN_00548dd0();
  }
  for (iVar1 = *(int *)(param_1 + 0xf8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1b8)) {
    FUN_00556e70(param_1);
  }
  if (DAT_008b8df0 == 0) {
    FUN_005550c0();
  }
  fVar3 = (float10)FUN_00556730(0xffffffff);
  *(float *)(param_1 + 0xf0) = (float)fVar3;
  FUN_00550310((float)fVar3);
  FUN_00556900(*(undefined4 *)(param_1 + 0xf0));
  return;
}


