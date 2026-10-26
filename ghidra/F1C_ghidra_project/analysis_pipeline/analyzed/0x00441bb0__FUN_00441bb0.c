// Function: FUN_00441bb0 @ 00441bb0
// Size (bytes): 423


void __fastcall FUN_00441bb0(int param_1)

{
  int iVar1;
  double dVar2;
  int iVar3;
  double *pdVar4;
  double *pdVar5;
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
  
  iVar3 = *(int *)(param_1 + 0x15f0);
  FUN_00435e00(param_1 + 0x1bc,&local_68);
  iVar1 = *(int *)(param_1 + 0x1d4);
  local_10 = local_58 + *(double *)(iVar3 + 0x14);
  dVar2 = *(double *)(iVar1 + 0xac) * *(double *)(param_1 + 0x1d8);
  local_28 = SQRT(dVar2 * *(double *)(iVar1 + 0xac)) * *(double *)(param_1 + 0x1e0);
  local_38 = (((local_58 * *(double *)(iVar3 + 0x84) - local_60 * *(double *)(iVar3 + 0x8c)) +
              *(double *)(iVar3 + 100)) - *(double *)(iVar1 + 100)) * local_28;
  local_30 = (((local_68 * *(double *)(iVar3 + 0x8c) - local_58 * *(double *)(iVar3 + 0x7c)) +
              *(double *)(iVar3 + 0x6c)) - *(double *)(iVar1 + 0x6c)) * local_28;
  local_28 = (((local_60 * *(double *)(iVar3 + 0x7c) - local_68 * *(double *)(iVar3 + 0x84)) +
              *(double *)(iVar3 + 0x74)) - *(double *)(iVar1 + 0x74)) * local_28;
  local_20 = ((local_68 + *(double *)(iVar3 + 4)) - *(double *)(iVar1 + 4)) * dVar2;
  local_18 = ((local_60 + *(double *)(iVar3 + 0xc)) - *(double *)(iVar1 + 0xc)) * dVar2;
  local_50 = local_20 + local_38;
  local_48 = local_30 + local_18;
  local_40 = local_28 + (local_10 - *(double *)(iVar1 + 0x14)) * dVar2;
  pdVar4 = &local_50;
  pdVar5 = &local_20;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined4 *)pdVar5 = *(undefined4 *)pdVar4;
    pdVar4 = (double *)((int)pdVar4 + 4);
    pdVar5 = (double *)((int)pdVar5 + 4);
  }
  *(double *)(iVar1 + 0x134) = local_50 + *(double *)(iVar1 + 0x134);
  *(double *)(iVar1 + 0x13c) = local_18 + *(double *)(iVar1 + 0x13c);
  *(double *)(iVar1 + 0x144) = local_10 + *(double *)(iVar1 + 0x144);
  FUN_00569b70(&local_68,&local_20);
  return;
}


