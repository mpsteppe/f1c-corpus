// Function: FUN_0044ba40 @ 0044ba40
// Size (bytes): 288


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044ba40(int param_1)

{
  double dVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_3c;
  double local_30;
  double local_28;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (*(double *)(param_1 + 0x10) == _DAT_0059e430) {
      local_30 = 0.0;
    }
    else {
      local_30 = _DAT_0059e420 / *(double *)(param_1 + 0x10);
    }
    if (*(double *)(param_1 + 0x20) == _DAT_0059e430) {
      local_28 = 0.0;
    }
    else {
      local_28 = _DAT_0059e420 / *(double *)(param_1 + 0x20);
    }
    iVar4 = 0;
    puVar5 = (undefined4 *)(param_1 + 0x28);
    do {
      local_3c = 0;
      dVar1 = (double)iVar4 - _DAT_0059e880;
      dVar2 = (double)iVar4 + _DAT_0059e880;
      do {
        local_18 = (float)((float10)(dVar1 * local_30) + (float10)*(double *)(param_1 + 8));
        local_14 = (float)((float10)(dVar2 * local_30) + (float10)*(double *)(param_1 + 8));
        local_10 = ((float)local_3c - (float)_DAT_0059e880) * (float)local_28 +
                   (float)*(double *)(param_1 + 0x18);
        local_c = ((float)local_3c + (float)_DAT_0059e880) * (float)local_28 +
                  (float)*(double *)(param_1 + 0x18);
        uVar3 = FUN_0044a880(&local_18);
        local_3c = local_3c + 1;
        *puVar5 = uVar3;
        puVar5 = puVar5 + 1;
      } while (local_3c < 0x20);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
  }
  return;
}


