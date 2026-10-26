// Function: FUN_00448300 @ 00448300
// Size (bytes): 33


void __fastcall FUN_00448300(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  *(float *)(param_1 + 0x14) = *(float *)(&DAT_008aae74 + uVar1 * 4) * *(float *)(param_1 + 8);
  return;
}


