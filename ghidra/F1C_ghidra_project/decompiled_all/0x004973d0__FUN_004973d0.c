// Function: FUN_004973d0 @ 004973d0
// Strings:  [NoDropIcon0000.bmp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004973d0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  if (*(float *)(param_1 + 0xc4) <= _DAT_005ac994) {
    return;
  }
  if (*(int *)(param_1 + 0x1568) == 0) {
    return;
  }
  piVar2 = (int *)FUN_00495980();
  if (piVar2 != (int *)0x0) {
    puVar5 = *(undefined1 **)(param_1 + 0x1558);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    cVar1 = (**(code **)(*piVar2 + 0x80))(puVar5);
    if (cVar1 == '\x01') {
      iVar3 = *(int *)(param_1 + 0x1568);
      goto LAB_0049743f;
    }
  }
  iVar3 = FUN_00497ad0(s_NoDropIcon0000_bmp_005cca48,0);
LAB_0049743f:
  if (iVar3 != 0) {
    uVar11 = *(undefined4 *)(param_1 + 0x60);
    uVar15 = *(undefined4 *)(*(int *)(iVar3 + 0xc) + 0x20);
    iVar13 = *(int *)(*(int *)(iVar3 + 0xc) + 0x1c);
    uVar14 = 0;
    uVar12 = 0;
    iVar6 = *(int *)(param_1 + 0x5c) - iVar13;
    iVar7 = iVar6;
    uVar8 = uVar11;
    iVar9 = iVar13;
    uVar10 = uVar15;
    uVar4 = FUN_00495150(iVar6,uVar11,iVar13,uVar15,0,0);
    FUN_00494a30(*(undefined4 *)(iVar3 + 0xc),0,0,uVar4,iVar7,uVar8,iVar9,uVar10,uVar12,uVar14);
    FUN_00490920(iVar6,uVar11,iVar13,uVar15);
    FUN_004918d0(iVar6,uVar11,iVar13,uVar15);
  }
  return;
}


