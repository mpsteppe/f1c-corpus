// Function: FUN_00441f00 @ 00441f00
// Size (bytes): 339


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00441f00(int param_1,float param_2,float param_3,float param_4,float param_5)

{
  int iVar1;
  int iVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  double *pdVar6;
  undefined4 *puVar7;
  double local_38;
  double local_30;
  double local_28;
  double local_10;
  
  if ((((param_2 == DAT_0059e440) && (param_3 == DAT_0059e440)) && (param_4 == DAT_0059e440)) &&
     (param_5 == DAT_0059e440)) {
    *(undefined1 *)(param_1 + 0x1724) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 0x1724) = 1;
  iVar5 = 0;
  do {
    iVar1 = param_1 + iVar5 * 0x18;
    iVar2 = *(int *)(param_1 + 0x15f0);
    local_10 = *(double *)(iVar2 + 0x4c) * *(double *)(iVar1 + 0x1660) +
               *(double *)(iVar2 + 0x54) * *(double *)(iVar1 + 0x1668) +
               *(double *)(iVar2 + 0x5c) * *(double *)(iVar1 + 0x1670);
    local_38 = *(double *)(iVar2 + 0x1c) * *(double *)(iVar1 + 0x1660) +
               *(double *)(iVar2 + 0x24) * *(double *)(iVar1 + 0x1668) +
               *(double *)(iVar2 + 0x2c) * *(double *)(iVar1 + 0x1670) + *(double *)(iVar2 + 4);
    local_28 = local_10 + *(double *)(iVar2 + 0x14);
    iVar4 = iVar5 * 8;
    if (iVar5 == 0) {
      dVar3 = (double)param_2;
    }
    else if (iVar5 == 1) {
      dVar3 = (double)param_3;
    }
    else if (iVar5 == 2) {
      dVar3 = (double)param_4;
    }
    else {
      dVar3 = (double)param_5;
    }
    iVar5 = iVar5 + 1;
    local_30 = *(double *)(param_1 + 0x15f4) * _DAT_0059ed58 +
               dVar3 + ((*(double *)(iVar2 + 0x34) * *(double *)(iVar1 + 0x1660) +
                         *(double *)(iVar2 + 0x3c) * *(double *)(iVar1 + 0x1668) +
                         *(double *)(iVar2 + 0x44) * *(double *)(iVar1 + 0x1670) +
                        *(double *)(iVar2 + 0xc)) - *(double *)(param_1 + 0x16f0 + iVar4)) +
               *(double *)(param_1 + 0x1720 + iVar5 * 8);
    pdVar6 = &local_38;
    puVar7 = (undefined4 *)(iVar1 + 0x1748);
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *(undefined4 *)pdVar6;
      pdVar6 = (double *)((int)pdVar6 + 4);
      puVar7 = puVar7 + 1;
    }
  } while (iVar5 < 4);
  return;
}


