// Function: FUN_0056f818 @ 0056f818
// Size (bytes): 638


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0056f818(int *param_1,double *param_2)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  short local_bc [84];
  int *local_14;
  int local_10;
  int local_a;
  bool local_5;
  
  iVar3 = 1;
  piVar2 = (int *)0x0;
  local_bc[0] = 2;
  local_bc[1] = 2;
  local_bc[2] = 1;
  local_bc[3] = 0xb;
  local_bc[4] = 4;
  local_bc[5] = 0xe;
  local_bc[6] = 0;
  local_bc[7] = 2;
  local_bc[8] = 1;
  local_bc[9] = 0xb;
  local_bc[10] = 4;
  local_bc[0xb] = 0x11;
  local_bc[0xc] = 1;
  local_bc[0xd] = 0xb;
  local_bc[0xe] = 4;
  local_bc[0xf] = 0xe;
  local_bc[0x10] = 1;
  local_bc[0x11] = 1;
  local_bc[0x12] = 1;
  local_bc[0x13] = 0xe;
  local_bc[0x14] = 4;
  local_bc[0x15] = 9;
  local_bc[0x16] = 0;
  local_bc[0x17] = 1;
  local_bc[0x18] = 1;
  local_bc[0x19] = 0xe;
  local_bc[0x1a] = 4;
  local_bc[0x1b] = 0xb;
  local_bc[0x1c] = 1;
  local_bc[0x1d] = 0xe;
  local_bc[0x1e] = 4;
  local_bc[0x1f] = 9;
  local_bc[0x20] = 0;
  local_bc[0x21] = 0xb;
  local_bc[0x22] = 4;
  local_bc[0x23] = 0x1a;
  local_bc[0x24] = 4;
  local_bc[0x25] = 0xe;
  local_bc[0x26] = 0;
  local_bc[0x27] = 0xe;
  local_bc[0x28] = 4;
  local_bc[0x29] = 0x18;
  local_bc[0x2a] = 4;
  local_bc[0x2b] = 9;
  local_bc[0x2c] = 1;
  local_bc[0x2d] = 2;
  local_bc[0x2e] = 1;
  local_bc[0x2f] = 0xb;
  local_bc[0x30] = 4;
  local_bc[0x31] = 4;
  local_bc[0x32] = 0;
  local_bc[0x33] = 2;
  local_bc[0x34] = 1;
  local_bc[0x35] = 0xb;
  local_bc[0x36] = 4;
  local_bc[0x37] = 7;
  local_bc[0x38] = 1;
  local_bc[0x39] = 0xb;
  local_bc[0x3a] = 4;
  local_bc[0x3b] = 4;
  local_bc[0x3c] = 1;
  local_bc[0x3d] = 1;
  local_bc[0x3e] = 1;
  local_bc[0x3f] = 0xe;
  local_bc[0x40] = 5;
  local_bc[0x41] = 1;
  local_bc[0x42] = 1;
  local_bc[0x43] = 0xe;
  local_bc[0x44] = 4;
  local_bc[0x45] = 1;
  local_bc[0x46] = 1;
  local_bc[0x47] = 0xe;
  local_bc[0x48] = 5;
  local_bc[0x49] = 0xb;
  local_bc[0x4a] = 4;
  local_bc[0x4b] = 0x10;
  local_bc[0x4c] = 4;
  local_bc[0x4d] = 4;
  local_bc[0x4e] = 0;
  local_bc[0x4f] = 0xe;
  local_bc[0x50] = 4;
  local_bc[0x51] = 0xe;
  local_bc[0x52] = 0xc2;
  local_a = 0;
  local_10 = 0;
  local_5 = true;
  if (param_2 == (double *)0x28) {
    local_14 = param_1;
    piVar2 = param_1;
    do {
      if (iVar3 < 0x28) {
        param_2 = (double *)(*local_14 + iVar3 * 8);
        param_1 = (int *)iVar3;
        do {
          piVar2 = (int *)(uint)(byte)(local_5 ^ *param_2 != _DAT_0059e430);
          if (piVar2 == (int *)0x0) {
            local_a = local_a + 1;
          }
          else {
            if (0x52 < local_10) goto LAB_0056fa80;
            psVar1 = local_bc + local_10;
            piVar2 = (int *)CONCAT22((short)((uint)local_10 >> 0x10),*psVar1);
            local_10 = local_10 + 1;
            if ((short)local_a != *psVar1) goto LAB_0056fa80;
            local_a = 0;
            piVar2 = (int *)CONCAT31((int3)((uint)piVar2 >> 8),local_5 == false);
            local_5 = local_5 == false;
          }
          param_1 = (int *)((int)param_1 + 1);
          param_2 = param_2 + 1;
        } while ((int)param_1 < 0x28);
      }
      local_14 = local_14 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x29);
    if (local_10 == 0x52) {
      return (uint)((short)local_a == 0xc2);
    }
  }
LAB_0056fa80:
  return (uint)piVar2 & 0xffffff00;
}


