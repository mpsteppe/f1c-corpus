// Function: FUN_0056ee40 @ 0056ee40
// Size (bytes): 467


void __fastcall FUN_0056ee40(int param_1)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  if (0 < *(int *)(param_1 + 8)) {
    iVar9 = 0;
    iVar8 = 0;
    do {
      pdVar1 = (double *)
               (*(int *)(param_1 + 0x2c) +
               *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 8 + iVar9) + 0x30) * 8);
      local_38 = *pdVar1;
      iVar10 = *(int *)(param_1 + 0xc) + iVar9;
      local_30 = pdVar1[1];
      local_28 = pdVar1[2];
      FUN_00569ad0(*(int *)(iVar10 + 8) + 0x18,&local_38);
      FUN_00569b70(*(int *)(iVar10 + 0x10) + 0x18,&local_38);
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x30;
    } while (iVar8 < *(int *)(param_1 + 8));
  }
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    iVar9 = 0;
    do {
      iVar10 = *(int *)(*(int *)(param_1 + 0x14) + 8 + iVar9);
      dVar2 = *(double *)(*(int *)(param_1 + 0x2c) + *(int *)(iVar10 + 0x7c) * 8);
      iVar7 = *(int *)(param_1 + 0x14) + iVar9;
      dVar3 = *(double *)(*(int *)(param_1 + 0x2c) + 8 + *(int *)(iVar10 + 0x7c) * 8);
      iVar9 = iVar9 + 0x30;
      dVar4 = *(double *)(iVar10 + 0x68);
      dVar5 = *(double *)(iVar10 + 0x50);
      iVar6 = *(int *)(iVar7 + 4);
      local_10 = dVar2 * *(double *)(iVar10 + 0x58) + dVar3 * *(double *)(iVar10 + 0x70);
      *(double *)(iVar6 + 0x14c) =
           dVar2 * *(double *)(iVar10 + 0x48) + dVar3 * *(double *)(iVar10 + 0x60) +
           *(double *)(iVar6 + 0x14c);
      *(double *)(iVar6 + 0x154) = dVar2 * dVar5 + dVar3 * dVar4 + *(double *)(iVar6 + 0x154);
      *(double *)(iVar6 + 0x15c) = local_10 + *(double *)(iVar6 + 0x15c);
      iVar10 = *(int *)(iVar7 + 0x10);
      local_20 = dVar2 * *(double *)(iVar10 + 0x48) + dVar3 * *(double *)(iVar10 + 0x60);
      local_18 = dVar2 * *(double *)(iVar10 + 0x50) + dVar3 * *(double *)(iVar10 + 0x68);
      dVar4 = *(double *)(iVar10 + 0x70);
      dVar5 = *(double *)(iVar10 + 0x58);
      iVar10 = *(int *)(iVar7 + 0xc);
      iVar8 = iVar8 + 1;
      *(double *)(iVar10 + 0x14c) = *(double *)(iVar10 + 0x14c) - local_20;
      *(double *)(iVar10 + 0x154) = *(double *)(iVar10 + 0x154) - local_18;
      *(double *)(iVar10 + 0x15c) = *(double *)(iVar10 + 0x15c) - (dVar2 * dVar5 + dVar3 * dVar4);
    } while (iVar8 < *(int *)(param_1 + 0x10));
  }
  iVar8 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    iVar9 = 0;
    do {
      iVar10 = *(int *)(param_1 + 0x1c);
      iVar6 = *(int *)(iVar10 + 8 + iVar9);
      local_28 = *(double *)(*(int *)(param_1 + 0x2c) + *(int *)(iVar6 + 0x30) * 8);
      local_38 = local_28 * *(double *)(iVar6 + 0x40);
      local_30 = local_28 * *(double *)(iVar6 + 0x48);
      local_28 = local_28 * *(double *)(iVar6 + 0x50);
      FUN_00569ad0(iVar6 + 0x18,&local_38);
      FUN_00569b70(*(int *)(iVar10 + iVar9 + 0x10) + 0x18,&local_38);
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0x48;
    } while (iVar8 < *(int *)(param_1 + 0x18));
  }
  return;
}


