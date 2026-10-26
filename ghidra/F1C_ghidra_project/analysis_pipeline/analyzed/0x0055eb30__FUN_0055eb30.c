// Function: FUN_0055eb30 @ 0055eb30
// Size (bytes): 104


void __fastcall FUN_0055eb30(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  ushort uVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  ushort uVar18;
  
  iVar7 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    iVar6 = 0;
    iVar5 = 0;
    do {
      uVar1 = *(undefined4 *)(iVar6 + 0x18 + *(int *)(param_1 + 0x20));
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18 + iVar5);
      uVar10 = (undefined1)((ulonglong)DAT_008b6c20 >> 0x18);
      sVar3 = CONCAT11(uVar10,(char)((uint)uVar1 >> 0x18));
      uVar9 = (undefined1)((ulonglong)DAT_008b6c20 >> 0x10);
      uVar8 = (undefined1)((ulonglong)DAT_008b6c20 >> 8);
      sVar4 = CONCAT11(uVar10,(char)((uint)uVar2 >> 0x18));
      uVar11 = (CONCAT11((char)DAT_008b6c20,(char)uVar2) + (short)DAT_008b8e40) *
               CONCAT11((char)DAT_008b6c20,(char)uVar1);
      uVar13 = (CONCAT11(uVar8,(char)((uint)uVar2 >> 8)) + (short)((ulonglong)DAT_008b8e40 >> 0x10))
               * CONCAT11(uVar8,(char)((uint)uVar1 >> 8));
      uVar15 = ((short)(CONCAT35(CONCAT21(sVar4,uVar9),CONCAT14((char)((uint)uVar2 >> 0x10),uVar2))
                       >> 0x20) + (short)((ulonglong)DAT_008b8e40 >> 0x20)) *
               (short)(CONCAT35(CONCAT21(sVar3,uVar9),CONCAT14((char)((uint)uVar1 >> 0x10),uVar1))
                      >> 0x20);
      uVar17 = (sVar4 + (short)((ulonglong)DAT_008b8e40 >> 0x30)) * sVar3;
      uVar12 = uVar11 >> 8;
      uVar14 = uVar13 >> 8;
      uVar16 = uVar15 >> 8;
      uVar18 = uVar17 >> 8;
      *(uint *)(iVar6 + 0x18 + *(int *)(param_1 + 0x20)) =
           CONCAT13((uVar18 != 0) * (uVar18 < 0x100) * (char)(uVar17 >> 8) - (0xff < uVar18),
                    CONCAT12((uVar16 != 0) * (uVar16 < 0x100) * (char)(uVar15 >> 8) -
                             (0xff < uVar16),
                             CONCAT11((uVar14 != 0) * (uVar14 < 0x100) * (char)(uVar13 >> 8) -
                                      (0xff < uVar14),
                                      (uVar12 != 0) * (uVar12 < 0x100) * (char)(uVar11 >> 8) -
                                      (0xff < uVar12))));
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x30;
      iVar6 = iVar6 + 0x40;
    } while (iVar7 < *(int *)(param_1 + 8));
  }
  return;
}


