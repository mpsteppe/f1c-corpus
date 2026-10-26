// Function: FUN_0054a0a0 @ 0054a0a0
// Size (bytes): 186


undefined4 __thiscall FUN_0054a0a0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  uint uVar5;
  int local_4;
  
  uVar1 = *(uint *)(param_1 + 4) & 0xfffffff0;
  *(uint *)(param_1 + 4) = uVar1;
  local_4 = 0;
  pfVar3 = (float *)(param_2 + 0x104);
  while( true ) {
    uVar5 = 0;
    iVar2 = 0;
    pfVar4 = (float *)(param_1 + 0x24);
    do {
      if (pfVar3[1] < (-(pfVar3[-2] * pfVar4[-2]) - pfVar3[-1] * pfVar4[-1]) - *pfVar3 * *pfVar4) {
        uVar5 = uVar5 | 1 << ((byte)iVar2 & 0x1f);
      }
      iVar2 = iVar2 + 1;
      pfVar4 = pfVar4 + 3;
    } while (iVar2 < 8);
    if (uVar5 != 0) break;
    local_4 = local_4 + 1;
    pfVar3 = pfVar3 + 4;
    if (5 < local_4) {
      *(uint *)(param_1 + 4) = uVar1 | 1;
      return 0;
    }
  }
  if (uVar5 == 0xff) {
    *(uint *)(param_1 + 4) = uVar1 | 2;
    return 0;
  }
  *(uint *)(param_1 + 4) = uVar1 | 4;
  return 0;
}


