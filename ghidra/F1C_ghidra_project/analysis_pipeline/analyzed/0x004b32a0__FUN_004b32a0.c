// Function: FUN_004b32a0 @ 004b32a0
// Size (bytes): 266


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b32a0(int *param_1,int param_2,undefined4 param_3)

{
  float10 fVar1;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = 0.0;
  local_14 = 0.0;
  local_10 = 0.0;
  FUN_004b2480(&local_18);
  FUN_004b25d0(&local_18);
  FUN_004b2750(&local_18);
  local_18 = (float)(*param_1 << 8) * _DAT_0059e780;
  local_14 = (float)(int)((*(ushort *)((int)param_1 + 2) & 0xff00) + param_1[1] * 0x10000) *
             _DAT_0059e780;
  local_10 = (float)(int)(((uint)param_1[1] >> 8 & 0xffff00) +
                         (uint)*(byte *)(param_1 + 2) * 0x1000000) * _DAT_0059e780;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_004b2310(&local_18,&local_c);
  fVar1 = (float10)FUN_004b2bf0();
  FUN_004b29b0((float)fVar1);
  fVar1 = (float10)FUN_004b2c50();
  FUN_004b2930((float)fVar1);
  *(undefined4 *)(param_2 + 4) = param_3;
  return;
}


