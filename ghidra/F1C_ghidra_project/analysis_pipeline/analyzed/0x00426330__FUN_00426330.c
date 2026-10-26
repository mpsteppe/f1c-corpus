// Function: FUN_00426330 @ 00426330
// Size (bytes): 185


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00426330(int param_1)

{
  int iVar1;
  
  if (*(float *)(param_1 + 0x3a10) <= DAT_0059e440) {
    iVar1 = *(int *)(param_1 + 0x39fc);
    if (*(int *)(param_1 + 0x4510) == 6) {
      if (iVar1 != -1) {
        FUN_004ef930(0xffffffff);
        return;
      }
    }
    else {
      if (*(int *)(param_1 + 0x3d6c) == 2) {
        FUN_004ef930(0);
        return;
      }
      if ((iVar1 != 0) && (iVar1 != -1)) {
        if (*(float *)(param_1 + 0x39a0) <= *(float *)(param_1 + 0x3a18)) {
          if (iVar1 < 2) {
            return;
          }
          FUN_004f62e6();
          return;
        }
        if (*(float *)(param_1 + 0x37cc) <= _DAT_0059e8cc) {
          return;
        }
        if (*(float *)(param_1 + 0x38c4) <= _DAT_0059e8cc) {
          return;
        }
      }
      if (*(int *)(param_1 + 0x39fc) < *(int *)(param_1 + 0x3a04)) {
        FUN_004ef930(*(int *)(param_1 + 0x39fc) + 1);
      }
    }
  }
  return;
}


