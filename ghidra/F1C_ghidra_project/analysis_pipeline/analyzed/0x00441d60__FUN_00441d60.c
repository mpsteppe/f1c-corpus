// Function: FUN_00441d60 @ 00441d60
// Size (bytes): 408


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00441d60(int param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_0056eb90();
  FUN_004423b0();
  FUN_00442c90();
  FUN_004432f0();
  if (*(double *)(param_1 + 0x19c) == _DAT_0059e430) {
    FUN_00441ad0();
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x15ac)) {
    iVar5 = 0;
    do {
      iVar2 = *(int *)(param_1 + 0x15b0);
      dVar1 = *(double *)(iVar2 + 0xac + iVar5);
      iVar3 = iVar2 + iVar5;
      *(undefined4 *)(iVar3 + 0x134) = *(undefined4 *)(iVar2 + 0x134 + iVar5);
      dVar1 = dVar1 * _DAT_0059ed50;
      *(undefined4 *)(iVar3 + 0x138) = *(undefined4 *)(iVar3 + 0x138);
      *(undefined4 *)(iVar3 + 0x144) = *(undefined4 *)(iVar3 + 0x144);
      *(undefined4 *)(iVar3 + 0x148) = *(undefined4 *)(iVar3 + 0x148);
      *(double *)(iVar3 + 0x13c) = dVar1 + *(double *)(iVar3 + 0x13c);
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x244;
    } while (iVar4 < *(int *)(param_1 + 0x15ac));
  }
  FUN_00441bb0();
  FUN_004359a0(*(undefined4 *)(param_1 + 0x15f0),*(undefined4 *)(param_1 + 0x60),
               *(undefined4 *)(param_1 + 100));
  iVar4 = *(int *)(param_1 + 0x15f0);
  *(double *)(iVar4 + 0x134) = *(double *)(iVar4 + 0x134) + *(double *)(param_1 + 0xec);
  *(double *)(iVar4 + 0x13c) = *(double *)(param_1 + 0xf4) + *(double *)(iVar4 + 0x13c);
  *(double *)(iVar4 + 0x144) = *(double *)(param_1 + 0xfc) + *(double *)(iVar4 + 0x144);
  iVar4 = *(int *)(param_1 + 0x15f0);
  *(double *)(iVar4 + 0x14c) = *(double *)(iVar4 + 0x14c) + *(double *)(param_1 + 0x104);
  *(double *)(iVar4 + 0x154) = *(double *)(param_1 + 0x10c) + *(double *)(iVar4 + 0x154);
  *(double *)(iVar4 + 0x15c) = *(double *)(param_1 + 0x114) + *(double *)(iVar4 + 0x15c);
  iVar4 = *(int *)(param_1 + 0x15f0);
  *(double *)(iVar4 + 0x134) = *(double *)(iVar4 + 0x134) + *(double *)(param_1 + 0x1f04);
  *(double *)(iVar4 + 0x13c) = *(double *)(param_1 + 0x1f0c) + *(double *)(iVar4 + 0x13c);
  *(double *)(iVar4 + 0x144) = *(double *)(param_1 + 0x1f14) + *(double *)(iVar4 + 0x144);
  iVar4 = *(int *)(param_1 + 0x15f0);
  *(double *)(iVar4 + 0x14c) = *(double *)(iVar4 + 0x14c) + *(double *)(param_1 + 0x1f1c);
  *(double *)(iVar4 + 0x154) = *(double *)(param_1 + 0x1f24) + *(double *)(iVar4 + 0x154);
  *(double *)(iVar4 + 0x15c) = *(double *)(param_1 + 0x1f2c) + *(double *)(iVar4 + 0x15c);
  return;
}


