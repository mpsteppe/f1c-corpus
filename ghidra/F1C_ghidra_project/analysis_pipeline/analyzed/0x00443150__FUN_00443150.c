// Function: FUN_00443150 @ 00443150
// Size (bytes): 408


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00443150(int param_1,char *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  int iVar3;
  char *pcVar4;
  double *pdVar5;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  if (*param_2 != '\0') {
    pcVar4 = param_2 + 0x4c;
    pdVar5 = &local_20;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined4 *)pdVar5 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pdVar5 = (double *)((int)pdVar5 + 4);
    }
    iVar3 = *(int *)(param_1 + 0x15f0);
    FUN_00435e00(&local_20,&local_50);
    local_38 = (local_40 * *(double *)(iVar3 + 0x84) - local_48 * *(double *)(iVar3 + 0x8c)) +
               *(double *)(iVar3 + 100);
    local_30 = (local_50 * *(double *)(iVar3 + 0x8c) - local_40 * *(double *)(iVar3 + 0x7c)) +
               *(double *)(iVar3 + 0x6c);
    local_28 = (local_48 * *(double *)(iVar3 + 0x7c) - local_50 * *(double *)(iVar3 + 0x84)) +
               *(double *)(iVar3 + 0x74);
    FUN_004388d0(&local_38,&local_20);
    local_10 = local_10 - param_3[2];
    if (local_10 < _DAT_0059e430) {
      local_10 = local_10 * local_10;
      dVar1 = (local_20 - *param_3) * (local_20 - *param_3) + local_10;
      dVar2 = _DAT_0059e420;
      if (_DAT_0059e430 < dVar1) {
        dVar1 = local_10 / dVar1;
        dVar1 = dVar1 * dVar1;
        dVar2 = _DAT_0059e420 - (_DAT_0059e420 - dVar1 * dVar1) * *(double *)(param_2 + 0x44);
      }
      dVar1 = dVar2 * *(double *)(param_2 + 0x34) * local_10;
      local_10 = *(double *)(param_2 + 0x3c) * local_10;
      local_20 = *(double *)(iVar3 + 0x1c) * _DAT_0059e430 +
                 dVar1 * *(double *)(iVar3 + 0x24) + local_10 * *(double *)(iVar3 + 0x2c);
      local_18 = *(double *)(iVar3 + 0x34) * _DAT_0059e430 +
                 dVar1 * *(double *)(iVar3 + 0x3c) + local_10 * *(double *)(iVar3 + 0x44);
      local_10 = *(double *)(iVar3 + 0x4c) * _DAT_0059e430 +
                 dVar1 * *(double *)(iVar3 + 0x54) + local_10 * *(double *)(iVar3 + 0x5c);
      FUN_00569ad0(&local_50,&local_20);
      return;
    }
  }
  return;
}


