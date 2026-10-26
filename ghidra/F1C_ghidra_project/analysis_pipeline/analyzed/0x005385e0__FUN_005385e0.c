// Function: FUN_005385e0 @ 005385e0
// Size (bytes): 213


void __fastcall FUN_005385e0(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  iVar7 = *(int *)(param_1 + 0x1446);
  iVar3 = *(int *)(param_1 + 0xb52 + param_3 * 4);
  iVar6 = param_3 * 2;
  bVar8 = SBORROW4(iVar6,iVar7);
  iVar5 = iVar6 - iVar7;
  if (iVar7 < iVar6) {
    *(int *)(param_1 + 0xb52 + param_3 * 4) = iVar3;
    return;
  }
  do {
    iVar7 = iVar6;
    if (bVar8 != iVar5 < 0) {
      iVar5 = *(int *)(param_1 + 0xb56 + iVar6 * 4);
      iVar4 = *(int *)(param_1 + 0xb52 + iVar6 * 4);
      uVar1 = *(ushort *)(param_2 + iVar5 * 4);
      uVar2 = *(ushort *)(param_2 + iVar4 * 4);
      if ((uVar1 < uVar2) ||
         ((uVar1 == uVar2 &&
          (*(byte *)(iVar5 + 0x144e + param_1) <= *(byte *)(param_1 + 0x144e + iVar4))))) {
        iVar7 = iVar6 + 1;
      }
    }
    iVar5 = *(int *)(param_1 + 0xb52 + iVar7 * 4);
    uVar1 = *(ushort *)(param_2 + iVar3 * 4);
    uVar2 = *(ushort *)(param_2 + iVar5 * 4);
    if (uVar1 < uVar2) break;
    if ((uVar1 == uVar2) &&
       (*(byte *)(param_1 + 0x144e + iVar3) <= *(byte *)(iVar5 + 0x144e + param_1))) {
      *(int *)(param_1 + 0xb52 + param_3 * 4) = iVar3;
      return;
    }
    iVar6 = iVar7 * 2;
    *(int *)(param_1 + 0xb52 + param_3 * 4) = iVar5;
    iVar4 = *(int *)(param_1 + 0x1446);
    bVar8 = SBORROW4(iVar6,iVar4);
    iVar5 = iVar6 - iVar4;
    param_3 = iVar7;
  } while (iVar6 <= iVar4);
  *(int *)(param_1 + 0xb52 + param_3 * 4) = iVar3;
  return;
}


