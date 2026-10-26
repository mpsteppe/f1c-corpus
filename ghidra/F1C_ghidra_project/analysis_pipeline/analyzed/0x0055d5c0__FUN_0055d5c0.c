// Function: FUN_0055d5c0 @ 0055d5c0
// Size (bytes): 351


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0055d5c0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  char *pcVar6;
  float local_c;
  undefined1 local_8 [4];
  float local_4;
  
  if (param_2 != 0) {
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000;
    pcVar6 = *(char **)(DAT_008b8f28 + 0x120);
    iVar4 = 0;
    if (0 < *(int *)(DAT_008b8f28 + 0x11c)) {
      while (-1 < *pcVar6) {
        pcVar6 = *(char **)(pcVar6 + 0x6c);
        iVar4 = iVar4 + 1;
        if (*(int *)(DAT_008b8f28 + 0x11c) <= iVar4) {
          return;
        }
      }
      if ((*(byte *)(*(int *)(param_1 + 0x138) + 0x3c) & 0x10) == 0) {
        FUN_0054b950(&local_c,local_8,&local_4);
        pfVar5 = &local_c;
      }
      else {
        pfVar5 = (float *)(param_1 + 0xe8);
      }
      fVar1 = *(float *)(param_2 + 0x24) + *pfVar5;
      fVar3 = pfVar5[1] + *(float *)(param_2 + 0x28);
      local_4 = pfVar5[2] + *(float *)(param_2 + 0x2c);
      fVar2 = SQRT(fVar1 * fVar1 + fVar3 * fVar3 + local_4 * local_4);
      if (fVar2 != DAT_0059e440) {
        fVar2 = _DAT_0059e670 / fVar2;
        fVar1 = fVar2 * fVar1;
        fVar3 = fVar2 * fVar3;
        local_4 = fVar2 * local_4;
      }
      *(float *)(param_1 + 0x100) = fVar1 - *(float *)(pcVar6 + 0x44);
      *(float *)(param_1 + 0x104) = fVar3 - *(float *)(pcVar6 + 0x48);
      local_4 = local_4 - *(float *)(pcVar6 + 0x4c);
      *(float *)(param_1 + 0x108) = local_4;
      fVar1 = SQRT(local_4 * local_4 +
                   *(float *)(param_1 + 0x104) * *(float *)(param_1 + 0x104) +
                   *(float *)(param_1 + 0x100) * *(float *)(param_1 + 0x100));
      if (fVar1 != DAT_0059e440) {
        fVar1 = _DAT_0059e43c / fVar1;
        *(float *)(param_1 + 0x100) = fVar1 * *(float *)(param_1 + 0x100);
        *(float *)(param_1 + 0x104) = fVar1 * *(float *)(param_1 + 0x104);
        *(float *)(param_1 + 0x108) = fVar1 * *(float *)(param_1 + 0x108);
        return;
      }
    }
  }
  return;
}


