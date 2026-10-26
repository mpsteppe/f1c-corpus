// Function: FUN_0046ba20 @ 0046ba20
// Size (bytes): 497


void FUN_0046ba20(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined1 local_50;
  undefined4 local_4f;
  undefined4 local_4b;
  undefined4 local_47;
  undefined2 local_43;
  undefined1 local_41;
  undefined1 local_40;
  undefined4 local_3f;
  
  iVar5 = DAT_005c329c;
  local_40 = DAT_005ea438;
  puVar9 = &local_3f;
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(undefined2 *)puVar9 = 0;
  *(undefined1 *)((int)puVar9 + 2) = 0;
  if (param_1 != 0) {
LAB_0046bb31:
    FUN_00489cb0();
    iVar2 = 0;
    iVar5 = 0;
    iVar6 = DAT_005c329c;
    do {
      iVar8 = 0;
      if (iVar6 < 1) {
        return;
      }
      iVar5 = iVar5 + 1;
      while (*(int *)((&DAT_007c54f0)[iVar8] + 0x4060) != iVar5) {
        iVar8 = iVar8 + 1;
        if (iVar6 <= iVar8) {
          return;
        }
      }
      if (*(int *)((&DAT_007c54f0)[iVar8] + 13000) != -1) {
        FUN_0046b5f0(iVar8,&DAT_007cd718,&local_40);
        local_4f = 0;
        local_4b = 0;
        local_47 = 0;
        local_43 = 0;
        local_41 = 0;
        local_50 = DAT_005ea438;
        FUN_0058815f(&local_50,&DAT_005c3280,*(undefined4 *)((&DAT_007c54f0)[iVar8] + 0x4894));
        FUN_00489600(&DAT_007cd718,0,0,&local_50,0);
        FUN_00489c10(iVar2,&local_40);
        iVar2 = iVar2 + 1;
        iVar6 = DAT_005c329c;
      }
    } while (iVar5 < 0x68);
    return;
  }
  iVar6 = 0;
  do {
    iVar2 = 0;
    if (0 < DAT_005c329c) {
      do {
        if (*(int *)((&DAT_007c54f0)[iVar2] + 0x4060) + -1 == iVar6) break;
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_005c329c);
    }
    if ((iVar2 < iVar5) && (*(int *)((&DAT_007c54f0)[iVar2] + 13000) != -1)) {
      FUN_0046b5f0(iVar2,&DAT_007cd718,&local_40);
      pbVar3 = (byte *)FUN_00489a10(iVar6);
      uVar4 = FUN_00489c60(iVar6);
      if (pbVar3 == (byte *)0x0) goto LAB_0046bb31;
      pbVar7 = (byte *)&DAT_007cd718;
      do {
        bVar1 = *pbVar3;
        bVar10 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_0046baf4:
          iVar2 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0046baf9;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar10 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_0046baf4;
        pbVar3 = pbVar3 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_0046baf9:
      if (iVar2 != 0) goto LAB_0046bb31;
      iVar2 = FUN_00588410(&local_40,uVar4);
    }
    else {
      iVar2 = FUN_00489a10(iVar6);
    }
    if (iVar2 != 0) goto LAB_0046bb31;
    iVar6 = iVar6 + 1;
    if (0x67 < iVar6) {
      return;
    }
  } while( true );
}


