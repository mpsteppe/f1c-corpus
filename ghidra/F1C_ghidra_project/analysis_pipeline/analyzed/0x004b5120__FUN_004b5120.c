// Function: FUN_004b5120 @ 004b5120
// Size (bytes): 179


uint __thiscall FUN_004b5120(int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  pbVar2 = (byte *)(param_2 + 0x4714);
  uVar3 = 0xffffffff;
  pbVar4 = pbVar2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
  } while (bVar1 != 0);
  for (pbVar4 = pbVar2 + (~uVar3 - 1); pbVar2 < pbVar4; pbVar4 = pbVar4 + -1) {
    if (*pbVar4 == 0x5c) {
      pbVar4 = pbVar4 + 1;
      break;
    }
  }
  pbVar2 = (byte *)(param_1 + 0x41);
  do {
    bVar1 = *pbVar2;
    bVar5 = bVar1 < *pbVar4;
    if (bVar1 != *pbVar4) {
LAB_004b5178:
      uVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_004b517d;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar5 = bVar1 < pbVar4[1];
    if (bVar1 != pbVar4[1]) goto LAB_004b5178;
    pbVar2 = pbVar2 + 2;
    pbVar4 = pbVar4 + 2;
  } while (bVar1 != 0);
  uVar3 = 0;
LAB_004b517d:
  if (uVar3 == 0) {
    pbVar4 = (byte *)(param_2 + 0x4620);
    pbVar2 = (byte *)(param_1 + 1);
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_004b51b8:
        uVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_004b51bd;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_004b51b8;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    uVar3 = 0;
LAB_004b51bd:
    if (uVar3 == 0) {
      return 1;
    }
  }
  return uVar3 & 0xffffff00;
}


