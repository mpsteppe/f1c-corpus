// Function: FUN_00537d10 @ 00537d10
// Size (bytes): 300


uint __fastcall FUN_00537d10(uint param_1,byte *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  byte *pbVar19;
  
  uVar3 = param_1 & 0xffff;
  param_1 = param_1 >> 0x10;
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  while (param_3 != 0) {
    uVar1 = param_3;
    if (0x15af < param_3) {
      uVar1 = 0x15b0;
    }
    param_3 = param_3 - uVar1;
    if (0xf < (int)uVar1) {
      uVar2 = uVar1 >> 4;
      uVar1 = uVar1 + uVar2 * -0x10;
      pbVar19 = param_2;
      do {
        param_2 = pbVar19 + 0x10;
        iVar4 = uVar3 + *pbVar19;
        iVar5 = iVar4 + (uint)pbVar19[1];
        iVar6 = iVar5 + (uint)pbVar19[2];
        iVar7 = iVar6 + (uint)pbVar19[3];
        iVar8 = iVar7 + (uint)pbVar19[4];
        iVar9 = iVar8 + (uint)pbVar19[5];
        iVar10 = iVar9 + (uint)pbVar19[6];
        iVar11 = iVar10 + (uint)pbVar19[7];
        iVar12 = iVar11 + (uint)pbVar19[8];
        iVar13 = iVar12 + (uint)pbVar19[9];
        iVar14 = iVar13 + (uint)pbVar19[10];
        iVar15 = iVar14 + (uint)pbVar19[0xb];
        iVar16 = iVar15 + (uint)pbVar19[0xc];
        iVar17 = iVar16 + (uint)pbVar19[0xd];
        iVar18 = iVar17 + (uint)pbVar19[0xe];
        uVar3 = iVar18 + (uint)pbVar19[0xf];
        param_1 = param_1 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12
                  + iVar13 + iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + uVar3;
        uVar2 = uVar2 - 1;
        pbVar19 = param_2;
      } while (uVar2 != 0);
    }
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      uVar3 = uVar3 + *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + uVar3;
    }
    uVar3 = uVar3 % 0xfff1;
    param_1 = param_1 % 0xfff1;
  }
  return param_1 << 0x10 | uVar3;
}


