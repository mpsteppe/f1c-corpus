// Function: FUN_004c5d30 @ 004c5d30
// Size (bytes): 124


bool __thiscall FUN_004c5d30(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  bool bVar6;
  
  iVar1 = param_1[3];
  iVar4 = param_2[3];
  bVar6 = SBORROW4(iVar1,iVar4);
  iVar2 = iVar1 - iVar4;
  if (iVar1 == iVar4) {
    iVar1 = *param_1 * 0x18c + DAT_008ac490;
    iVar4 = *param_2 * 0x18c + DAT_008ac490;
    if ((iVar1 != 0) && (iVar4 != 0)) {
      iVar1 = FUN_00588410(iVar1 + 0x104,iVar4 + 0x104);
      return iVar1 < 0;
    }
    puVar5 = (undefined1 *)param_2[1];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar3 = (undefined1 *)param_1[1];
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    iVar2 = FUN_00588410(puVar3,puVar5);
    bVar6 = false;
  }
  return bVar6 != iVar2 < 0;
}


