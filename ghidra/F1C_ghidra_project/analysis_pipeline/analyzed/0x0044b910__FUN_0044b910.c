// Function: FUN_0044b910 @ 0044b910
// Size (bytes): 301


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044b910(int param_1,int *param_2)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  float local_10;
  float local_c;
  
  iVar5 = *param_2;
  local_10 = 3.4028235e+38;
  local_c = 3.4028235e+38;
  fVar3 = -3.4028235e+38;
  fVar1 = _DAT_0059ef30;
  if (0 < iVar5) {
    puVar4 = (undefined4 *)param_2[2];
    do {
      iVar7 = 3;
      puVar6 = puVar4;
      do {
        pfVar2 = (float *)*puVar6;
        if (*pfVar2 < local_10) {
          local_10 = *pfVar2;
        }
        if (fVar1 < *pfVar2) {
          fVar1 = *pfVar2;
        }
        if (pfVar2[3] < local_c) {
          local_c = pfVar2[3];
        }
        if (fVar3 < pfVar2[3]) {
          fVar3 = pfVar2[3];
        }
        puVar6 = puVar6 + 2;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      puVar4 = puVar4 + 8;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  fVar1 = (fVar1 - local_10) * (float)_DAT_0059ef48;
  fVar3 = (fVar3 - local_c) * (float)_DAT_0059ef48;
  *(double *)(param_1 + 8) = (double)((float)_DAT_0059e880 * fVar1 + local_10);
  *(double *)(param_1 + 0x18) = (double)(fVar3 * (float)_DAT_0059e880 + local_c);
  if (fVar1 == (float)_DAT_0059e430) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  else {
    *(double *)(param_1 + 0x10) = (double)((float)_DAT_0059e420 / fVar1);
  }
  if (fVar3 != (float)_DAT_0059e430) {
    *(double *)(param_1 + 0x20) = _DAT_0059e420 / (double)fVar3;
    return;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}


