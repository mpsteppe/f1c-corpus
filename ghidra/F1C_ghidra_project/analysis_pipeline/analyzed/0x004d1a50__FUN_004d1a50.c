// Function: FUN_004d1a50 @ 004d1a50
// Size (bytes): 118


void __thiscall FUN_004d1a50(int param_1,uint *param_2)

{
  int extraout_EDX;
  int extraout_EDX_00;
  uint uVar1;
  
  if (((*param_2 & 0xfc0000) == 0x280000) && (0 < *(int *)(param_1 + 0x10c))) {
    do {
      FUN_004d0f00(0);
    } while (extraout_EDX + 1 < *(int *)(param_1 + 0x10c));
  }
  uVar1 = *param_2 >> 9 & 0x1ff;
  if (uVar1 != 0) {
    param_2 = param_2 + 2;
    do {
      FUN_004d0f00((ushort)*param_2 & 0x3f);
      param_2 = (uint *)(extraout_EDX_00 + 2);
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return;
}


