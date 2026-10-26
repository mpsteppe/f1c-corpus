// Function: FUN_0056d2d0 @ 0056d2d0
// Size (bytes): 263


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0056d2d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  int iVar5;
  double *pdVar6;
  double *pdVar7;
  undefined4 *puVar8;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_8;
  
  FUN_00435e00(*(int *)(param_1 + 8),*(int *)(param_1 + 8) + 0x18);
  FUN_00435e00(*(int *)(param_1 + 0x10),*(int *)(param_1 + 0x10) + 0x18);
  iVar5 = *(int *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 8);
  local_8 = *(double *)(iVar5 + 0x28) + *(double *)(iVar1 + 0x14);
  iVar3 = *(int *)(param_1 + 4);
  local_40 = *(double *)(iVar2 + 0x20) + *(double *)(iVar3 + 0xc);
  local_38 = *(double *)(iVar2 + 0x28) + *(double *)(iVar3 + 0x14);
  local_30 = (*(double *)(iVar3 + 4) + *(double *)(iVar2 + 0x18)) -
             (*(double *)(iVar5 + 0x18) + *(double *)(iVar1 + 4));
  local_28 = local_40 - (*(double *)(iVar5 + 0x20) + *(double *)(iVar1 + 0xc));
  local_20 = local_38 - local_8;
  pdVar6 = &local_30;
  pdVar7 = &local_48;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pdVar7 = *(undefined4 *)pdVar6;
    pdVar6 = (double *)((int)pdVar6 + 4);
    pdVar7 = (double *)((int)pdVar7 + 4);
  }
  dVar4 = _DAT_0059e420 / SQRT(local_30 * local_30 + local_28 * local_28 + local_20 * local_20);
  local_48 = local_30 * dVar4;
  local_40 = local_40 * dVar4;
  local_38 = local_38 * dVar4;
  pdVar6 = &local_48;
  puVar8 = (undefined4 *)(iVar2 + 0x40);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *(undefined4 *)pdVar6;
    pdVar6 = (double *)((int)pdVar6 + 4);
    puVar8 = puVar8 + 1;
  }
  pdVar6 = &local_48;
  puVar8 = (undefined4 *)(*(int *)(param_1 + 0x10) + 0x40);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *(undefined4 *)pdVar6;
    pdVar6 = (double *)((int)pdVar6 + 4);
    puVar8 = puVar8 + 1;
  }
  return;
}


