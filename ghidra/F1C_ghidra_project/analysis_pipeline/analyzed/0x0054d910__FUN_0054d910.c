// Function: FUN_0054d910 @ 0054d910
// Size (bytes): 220


undefined4 __thiscall FUN_0054d910(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  uint uVar5;
  int local_4;
  
  uVar1 = *(uint *)(param_1 + 0x14) & 0xfffffff8;
  *(uint *)(param_1 + 0x14) = uVar1;
  local_4 = 0;
  if (0 < *(int *)(param_1 + 0xfc)) {
    pfVar3 = (float *)(param_2 + 0x104);
    do {
      uVar5 = 0;
      iVar2 = 0;
      pfVar4 = (float *)(param_3 + 8);
      do {
        if (pfVar3[1] < (-(pfVar3[-2] * pfVar4[-2]) - pfVar3[-1] * pfVar4[-1]) - *pfVar3 * *pfVar4)
        {
          uVar5 = uVar5 | 1 << ((byte)iVar2 & 0x1f);
        }
        iVar2 = iVar2 + 1;
        pfVar4 = pfVar4 + 3;
      } while (iVar2 < 8);
      if (uVar5 != 0) {
        if (uVar5 == 0xff) {
          *(uint *)(param_1 + 0x14) = uVar1 | 2;
          return 0;
        }
        *(uint *)(param_1 + 0x14) = uVar1 | 4;
        return 0;
      }
      local_4 = local_4 + 1;
      pfVar3 = pfVar3 + 4;
    } while (local_4 < *(int *)(param_1 + 0xfc));
  }
  *(uint *)(param_1 + 0x14) = uVar1 | 1;
  return 0;
}


