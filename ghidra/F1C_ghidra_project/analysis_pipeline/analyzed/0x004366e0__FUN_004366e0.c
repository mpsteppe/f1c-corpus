// Function: FUN_004366e0 @ 004366e0
// Size (bytes): 386


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004366e0(int param_1,int param_2,double *param_3,double *param_4)

{
  double dVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  double *pdVar5;
  int local_74 [3];
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  iVar4 = 0;
  pdVar2 = &local_68;
  pdVar5 = &local_68;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pdVar5 = 0;
    pdVar5 = (double *)((int)pdVar5 + 4);
  }
  do {
    local_74[iVar4] = (int)pdVar2;
    iVar4 = iVar4 + 1;
    pdVar2 = pdVar2 + 4;
  } while (iVar4 < 3);
  if (0 < param_2) {
    pdVar2 = (double *)(param_1 + 0x10);
    do {
      param_2 = param_2 + -1;
      local_68 = pdVar2[-2] * pdVar2[-2] + local_68;
      local_60 = *pdVar2 * pdVar2[-2] + local_60;
      local_58 = local_58 + pdVar2[-2];
      local_50 = pdVar2[-1] * pdVar2[-2] + local_50;
      local_48 = *pdVar2 * pdVar2[-2] + local_48;
      local_40 = *pdVar2 * *pdVar2 + local_40;
      local_38 = *pdVar2 + local_38;
      local_30 = *pdVar2 * pdVar2[-1] + local_30;
      local_28 = local_28 + pdVar2[-2];
      local_20 = *pdVar2 + local_20;
      local_18 = local_18 + _DAT_0059e420;
      local_10 = pdVar2[-1] + local_10;
      pdVar2 = (double *)((int)pdVar2 + 0x1c);
    } while (param_2 != 0);
  }
  iVar3 = FUN_005677b0();
  if (iVar3 == 0) {
    dVar1 = _DAT_0059e420 / SQRT(local_50 * local_50 + local_30 * local_30 + _DAT_0059e420);
    *param_3 = -(local_50 * dVar1);
    param_3[1] = dVar1;
    param_3[2] = -(local_30 * dVar1);
    *param_4 = dVar1 * local_10;
    return;
  }
  *(undefined4 *)param_3 = 0;
  *(undefined4 *)((int)param_3 + 4) = 0;
  *(undefined4 *)(param_3 + 1) = 0;
  *(undefined4 *)((int)param_3 + 0xc) = 0x3ff00000;
  *(undefined4 *)(param_3 + 2) = 0;
  *(undefined4 *)((int)param_3 + 0x14) = 0;
  *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)((int)param_4 + 4) = *(undefined4 *)(param_1 + 0xc);
  return;
}


