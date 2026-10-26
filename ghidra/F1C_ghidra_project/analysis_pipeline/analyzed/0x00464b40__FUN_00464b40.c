// Function: FUN_00464b40 @ 00464b40
// Size (bytes): 100


void __thiscall FUN_00464b40(int param_1,uint *param_2)

{
  uint uVar1;
  int extraout_EDX;
  
  if ((*(float *)(param_1 + 0x71) < (float)param_2[1]) ||
     (((*(byte *)(param_1 + 0x70) ^ *(byte *)((int)param_2 + 3)) & 7) != 0)) {
    uVar1 = *param_2 >> 0x12 & 0x3f;
    if (uVar1 == 0) {
      FUN_004b3a90(param_2);
    }
    else if (uVar1 == 7) {
      FUN_004b2dd0(param_1 + 0x6d,param_2[1]);
    }
    do {
      FUN_004649f0(0);
    } while (extraout_EDX + 1 < 0x68);
  }
  return;
}


