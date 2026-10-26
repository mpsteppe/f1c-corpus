// Function: FUN_0055d320 @ 0055d320
// Size (bytes): 208


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0055d320(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 == 1) {
    uVar2 = 2;
    *(float *)(param_1 + 8) = (float)param_3 * _DAT_0059e460 * *(float *)(param_1 + 0x14);
    *(float *)(param_1 + 0xc) = (float)param_4 * _DAT_0059e460 * *(float *)(param_1 + 0x14);
    *(float *)(param_1 + 0x10) = (float)param_5 * _DAT_0059e460 * *(float *)(param_1 + 0x14);
LAB_0055d3cf:
    uVar1 = *(undefined4 *)(param_1 + 4);
  }
  else {
    if (param_2 != 2) {
      if (param_2 != 3) goto LAB_0055d3de;
      uVar2 = 4;
      *(float *)(param_1 + 0x28) = (float)param_3 * _DAT_0059e460 * *(float *)(param_1 + 0x34);
      *(float *)(param_1 + 0x2c) = (float)param_4 * _DAT_0059e460 * *(float *)(param_1 + 0x34);
      *(float *)(param_1 + 0x30) = (float)param_5 * _DAT_0059e460 * *(float *)(param_1 + 0x34);
      goto LAB_0055d3cf;
    }
    uVar1 = *(undefined4 *)(param_1 + 4);
    uVar2 = 3;
    *(float *)(param_1 + 0x18) = (float)param_3 * _DAT_0059e460 * *(float *)(param_1 + 0x24);
    *(float *)(param_1 + 0x1c) = (float)param_4 * _DAT_0059e460 * *(float *)(param_1 + 0x24);
    *(float *)(param_1 + 0x20) = (float)param_5 * _DAT_0059e460 * *(float *)(param_1 + 0x24);
  }
  FUN_005416a0(param_1,uVar1,uVar2);
LAB_0055d3de:
  *(uint *)(DAT_008b8f28 + 0xec) = *(uint *)(DAT_008b8f28 + 0xec) | 0x800;
  return;
}


