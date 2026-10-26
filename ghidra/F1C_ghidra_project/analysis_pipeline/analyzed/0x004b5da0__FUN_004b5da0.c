// Function: FUN_004b5da0 @ 004b5da0
// Size (bytes): 136


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b5da0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_004b68c0();
  if (iVar1 == 0) {
    FUN_004b6940(param_3);
    iVar1 = FUN_004b68c0();
  }
  iVar3 = 0;
  if (0 < iVar1) {
    while( true ) {
      iVar2 = *(int *)(param_1 + 0x9b8) - iVar3;
      if (iVar2 < 0) {
        iVar2 = iVar2 + *(int *)(param_1 + 0x9b4);
      }
      iVar2 = FUN_004b6920(iVar2);
      if (*(float *)(iVar2 + 0x6c) <= *(float *)(param_2 + 4)) break;
      iVar3 = iVar3 + 1;
      if (iVar1 <= iVar3) {
        return;
      }
    }
    if (*(float *)(param_2 + 4) - *(float *)(iVar2 + 0x6c) < _DAT_0059e8a4) {
      FUN_004b48e0(param_2,param_3);
    }
  }
  return;
}


