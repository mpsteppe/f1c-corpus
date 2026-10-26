// Function: FUN_00424c80 @ 00424c80
// Size (bytes): 65


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00424c80(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  *(float *)(param_1 + 0x4448) =
       (*(float *)(&DAT_008aae74 + uVar1 * 4) * _DAT_0059e868 + _DAT_0059e868) -
       (float)DAT_007d01a0 * _DAT_0059e444 * _DAT_0059e84c;
  return;
}


