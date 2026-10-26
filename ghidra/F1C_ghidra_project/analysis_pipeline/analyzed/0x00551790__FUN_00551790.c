// Function: FUN_00551790 @ 00551790
// Size (bytes): 108


void __thiscall FUN_00551790(int param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  bool bVar6;
  
  iVar2 = *(int *)(param_1 + 0x13c);
  do {
    if (iVar2 == 0) {
      return;
    }
    pbVar3 = (byte *)(*(int *)(iVar2 + 0x1c) + 0x1c);
    pbVar5 = param_2;
    do {
      bVar1 = *pbVar5;
      bVar6 = bVar1 < *pbVar3;
      if (bVar1 != *pbVar3) {
LAB_005517d4:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_005517d9;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar6 = bVar1 < pbVar3[1];
      if (bVar1 != pbVar3[1]) goto LAB_005517d4;
      pbVar5 = pbVar5 + 2;
      pbVar3 = pbVar3 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_005517d9:
    if (iVar4 == 0) {
      *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) & 0xfffdffff;
      FUN_00551480();
    }
    iVar2 = *(int *)(iVar2 + 0x24);
  } while( true );
}


