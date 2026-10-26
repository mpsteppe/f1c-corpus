// Function: FUN_004db170 @ 004db170
// Size (bytes): 495


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004db170(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  bool bVar10;
  float10 fVar11;
  int local_88;
  char local_80 [127];
  undefined1 local_1;
  
  if (_DAT_005ea4e8 <= DAT_0059e440) {
    return 1;
  }
  FUN_00408490();
  uVar3 = __ftol();
  iVar7 = 0x80;
  uVar4 = __ftol();
  pbVar5 = *(byte **)(param_1 + 0x10);
  if (pbVar5 == (byte *)0x0) {
    pbVar5 = &DAT_005ea438;
  }
  pbVar8 = &DAT_005ea438;
  do {
    bVar1 = *pbVar5;
    bVar10 = bVar1 < *pbVar8;
    if (bVar1 != *pbVar8) {
LAB_004db20b:
      iVar6 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      goto LAB_004db210;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar10 = bVar1 < pbVar8[1];
    if (bVar1 != pbVar8[1]) goto LAB_004db20b;
    pbVar5 = pbVar5 + 2;
    pbVar8 = pbVar8 + 2;
  } while (bVar1 != 0);
  iVar6 = 0;
LAB_004db210:
  if (iVar6 != 0) {
    pcVar9 = *(char **)(param_1 + 0x10);
    if (pcVar9 == (char *)0x0) {
      pcVar9 = &DAT_005ea438;
    }
    iVar6 = FUN_00423a00(pcVar9,&DAT_005ec4cc);
    if (iVar6 != 0) {
      if (pcVar9 == (char *)0x0) {
        DAT_005ec4cc = 0;
      }
      else {
        iVar6 = (int)&DAT_005ec4cc - (int)pcVar9;
        do {
          cVar2 = *pcVar9;
          pcVar9[iVar6] = cVar2;
          pcVar9 = pcVar9 + 1;
        } while (cVar2 != '\0');
      }
    }
    _strncpy(local_80,&DAT_005ec4cc,0x7f);
    local_1 = 0;
    FUN_004d7e40(local_80,100,uVar3,0xffffff,0,0,0x3f800000,0x3f800000);
  }
  cVar2 = FUN_004b9a00();
  if ((cVar2 != '\0') && (_DAT_005ea4e8 == _DAT_0059e43c)) {
    fVar11 = (float10)FUN_004b9a10();
    FUN_0058815f(local_80,&DAT_005ccef0,(int)DAT_005d4aec);
    local_88 = 0;
    do {
      if ((float)local_88 * _DAT_0059e87c < (float)fVar11 ==
          ((float)local_88 * _DAT_0059e87c == (float)fVar11)) {
        uVar3 = 0xffffff;
      }
      else {
        uVar3 = 0xff0000;
      }
      FUN_004d7e40(local_80,iVar7,uVar4,uVar3,0,3,0x3f800000,0x3f800000);
      iVar7 = iVar7 + 0x19;
      local_88 = local_88 + 1;
    } while (local_88 < 0x29);
  }
  return 0;
}


