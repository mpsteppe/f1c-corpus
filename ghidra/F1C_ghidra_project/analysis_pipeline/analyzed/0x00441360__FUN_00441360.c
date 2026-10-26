// Function: FUN_00441360 @ 00441360
// Size (bytes): 235


void __fastcall FUN_00441360(int param_1)

{
  double *pdVar1;
  double *pdVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  FUN_004412f0();
  FUN_0056f060();
  iVar8 = *(int *)(param_1 + 0x15ac);
  if (0 < iVar8) {
    iVar7 = 0;
    iVar9 = 0;
    do {
      iVar6 = *(int *)(param_1 + 0x162c);
      pdVar1 = (double *)(iVar6 + iVar9);
      pdVar2 = (double *)(*(int *)(param_1 + 0x15b0) + 0x134 + iVar7);
      iVar5 = *(int *)(param_1 + 0x15b0) + iVar7;
      dVar3 = *(double *)(iVar6 + 8 + iVar9);
      iVar6 = iVar6 + iVar9;
      iVar7 = iVar7 + 0x244;
      dVar4 = *(double *)(iVar6 + 0x10);
      iVar9 = iVar9 + 0x30;
      iVar8 = iVar8 + -1;
      *(double *)(iVar5 + 0x134) = (*pdVar1 - *pdVar2) + *(double *)(iVar5 + 0x134);
      *(double *)(iVar5 + 0x13c) = (dVar3 - *(double *)(iVar5 + 0x13c)) + *(double *)(iVar5 + 0x13c)
      ;
      *(double *)(iVar5 + 0x144) = (dVar4 - *(double *)(iVar5 + 0x144)) + *(double *)(iVar5 + 0x144)
      ;
      dVar3 = *(double *)(iVar6 + 0x20);
      dVar4 = *(double *)(iVar6 + 0x28);
      *(double *)(iVar5 + 0x14c) =
           (*(double *)(iVar6 + 0x18) - *(double *)(iVar5 + 0x14c)) + *(double *)(iVar5 + 0x14c);
      *(double *)(iVar5 + 0x154) = (dVar3 - *(double *)(iVar5 + 0x154)) + *(double *)(iVar5 + 0x154)
      ;
      *(double *)(iVar5 + 0x15c) = (dVar4 - *(double *)(iVar5 + 0x15c)) + *(double *)(iVar5 + 0x15c)
      ;
    } while (iVar8 != 0);
  }
  return;
}


