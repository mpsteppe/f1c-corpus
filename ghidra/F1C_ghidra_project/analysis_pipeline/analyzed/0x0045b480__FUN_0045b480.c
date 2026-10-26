// Function: FUN_0045b480 @ 0045b480
// Size (bytes): 116


uint __thiscall FUN_0045b480(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  bool bVar7;
  
  iVar6 = 0;
  pbVar2 = (byte *)(param_1 + 0x3c);
  pbVar5 = param_2;
  pbVar4 = pbVar2;
LAB_0045b496:
  do {
    bVar1 = *pbVar2;
    bVar7 = bVar1 < *pbVar5;
    if (bVar1 == *pbVar5) {
      if (bVar1 != 0) {
        bVar1 = pbVar2[1];
        bVar7 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_0045b4ba;
        pbVar2 = pbVar2 + 2;
        pbVar5 = pbVar5 + 2;
        if (bVar1 != 0) goto LAB_0045b496;
      }
      uVar3 = 0;
    }
    else {
LAB_0045b4ba:
      uVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
    }
    if (uVar3 == 0) {
      *(undefined4 *)(iVar6 * 0x5c + 0x90 + param_1) = DAT_0059f07c;
      return 1;
    }
    iVar6 = iVar6 + 1;
    pbVar2 = pbVar4 + 0x5c;
    pbVar5 = param_2;
    pbVar4 = pbVar2;
    if (7 < iVar6) {
      return uVar3 & 0xffffff00;
    }
  } while( true );
}


