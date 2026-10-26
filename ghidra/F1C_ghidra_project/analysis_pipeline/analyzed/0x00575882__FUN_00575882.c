// Function: FUN_00575882 @ 00575882
// Size (bytes): 827


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00575882(int *param_1,double *param_2)

{
  short *psVar1;
  uint uVar2;
  short local_f0 [108];
  uint local_18;
  int *local_14;
  int local_10;
  int local_a;
  bool local_5;
  
  uVar2 = 0;
  local_f0[0] = 9;
  local_f0[1] = 4;
  local_f0[2] = 2;
  local_f0[3] = 2;
  local_f0[4] = 0;
  local_f0[5] = 0xb;
  local_f0[6] = 7;
  local_f0[7] = 4;
  local_f0[8] = 2;
  local_f0[9] = 2;
  local_f0[10] = 0;
  local_f0[0xb] = 0xb;
  local_f0[0xc] = 6;
  local_f0[0xd] = 4;
  local_f0[0xe] = 2;
  local_f0[0xf] = 2;
  local_f0[0x10] = 0;
  local_f0[0x11] = 0xb;
  local_f0[0x12] = 5;
  local_f0[0x13] = 4;
  local_f0[0x14] = 2;
  local_f0[0x15] = 2;
  local_f0[0x16] = 0;
  local_f0[0x17] = 0xb;
  local_f0[0x18] = 4;
  local_f0[0x19] = 4;
  local_f0[0x1a] = 2;
  local_f0[0x1b] = 2;
  local_f0[0x1c] = 0;
  local_f0[0x1d] = 0xb;
  local_f0[0x1e] = 3;
  local_f0[0x1f] = 4;
  local_f0[0x20] = 2;
  local_f0[0x21] = 2;
  local_f0[0x22] = 0;
  local_f0[0x23] = 0xb;
  local_f0[0x24] = 2;
  local_f0[0x25] = 4;
  local_f0[0x26] = 2;
  local_f0[0x27] = 2;
  local_f0[0x28] = 0;
  local_f0[0x29] = 0xb;
  local_f0[0x2a] = 1;
  local_f0[0x2b] = 4;
  local_f0[0x2c] = 2;
  local_f0[0x2d] = 2;
  local_f0[0x2e] = 0;
  local_f0[0x2f] = 0xb;
  local_f0[0x30] = 0;
  local_f0[0x31] = 4;
  local_f0[0x32] = 2;
  local_f0[0x33] = 2;
  local_f0[0x34] = 0;
  local_f0[0x35] = 0x10;
  local_f0[0x36] = 2;
  local_f0[0x37] = 2;
  local_f0[0x38] = 0;
  local_f0[0x39] = 0xb;
  local_f0[0x3a] = 3;
  local_f0[0x3b] = 8;
  local_f0[0x3c] = 4;
  local_f0[0x3d] = 4;
  local_f0[0x3e] = 2;
  local_f0[0x3f] = 8;
  local_f0[0x40] = 4;
  local_f0[0x41] = 4;
  local_f0[0x42] = 1;
  local_f0[0x43] = 8;
  local_f0[0x44] = 4;
  local_f0[0x45] = 4;
  local_f0[0x46] = 0;
  local_f0[0x47] = 8;
  local_f0[0x48] = 4;
  local_f0[0x49] = 0xd;
  local_f0[0x4a] = 4;
  local_f0[0x4b] = 4;
  local_f0[0x4c] = 1;
  local_f0[0x4d] = 2;
  local_f0[0x4e] = 0;
  local_f0[0x4f] = 1;
  local_f0[0x50] = 10;
  local_f0[0x51] = 2;
  local_f0[0x52] = 0;
  local_f0[0x53] = 1;
  local_f0[0x54] = 9;
  local_f0[0x55] = 2;
  local_f0[0x56] = 0;
  local_f0[0x57] = 1;
  local_f0[0x58] = 0xb;
  local_f0[0x59] = 0;
  local_f0[0x5a] = 1;
  local_f0[0x5b] = 4;
  local_f0[0x5c] = 5;
  local_f0[0x5d] = 0;
  local_f0[0x5e] = 1;
  local_f0[0x5f] = 4;
  local_f0[0x60] = 4;
  local_f0[0x61] = 0;
  local_f0[0x62] = 1;
  local_f0[99] = 4;
  local_f0[100] = 4;
  local_f0[0x65] = 1;
  local_f0[0x66] = 10;
  local_f0[0x67] = 4;
  local_f0[0x68] = 4;
  local_f0[0x69] = 4;
  local_f0[0x6a] = 0x31;
  local_a = 0;
  local_10 = 0;
  local_5 = true;
  if (param_2 == (double *)0x22) {
    local_18 = 1;
    local_14 = param_1;
    do {
      if ((int)local_18 < 0x22) {
        param_2 = (double *)(*local_14 + local_18 * 8);
        param_1 = (int *)local_18;
        do {
          uVar2 = (uint)(byte)(local_5 ^ *param_2 != _DAT_0059e430);
          if (uVar2 == 0) {
            local_a = local_a + 1;
          }
          else {
            if (0x6a < local_10) goto LAB_00575ba9;
            psVar1 = local_f0 + local_10;
            uVar2 = CONCAT22((short)((uint)local_10 >> 0x10),*psVar1);
            local_10 = local_10 + 1;
            if ((short)local_a != *psVar1) goto LAB_00575ba9;
            local_a = 0;
            local_5 = local_5 == false;
          }
          param_1 = (int *)((int)param_1 + 1);
          param_2 = param_2 + 1;
        } while ((int)param_1 < 0x22);
      }
      local_14 = local_14 + 1;
      uVar2 = local_18 + 1;
      local_18 = uVar2;
    } while ((int)uVar2 < 0x23);
    if (local_10 == 0x6a) {
      return (uint)((short)local_a == 0x31);
    }
  }
LAB_00575ba9:
  return uVar2 & 0xffffff00;
}


