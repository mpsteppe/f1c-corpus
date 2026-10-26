// Function: FUN_00548890 @ 00548890
// Size (bytes): 263


byte * __thiscall FUN_00548890(int param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  byte local_200 [256];
  byte local_100 [256];
  
  iVar5 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_100 + iVar5)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_100);
  pbVar3 = *(byte **)(param_1 + 0x24);
joined_r0x005488c7:
  if (pbVar3 == (byte *)0x0) {
    return (byte *)0x0;
  }
  if ((*(uint *)(pbVar3 + 0x9c) & 0x200) == 0) {
    pbVar4 = local_100;
    pbVar7 = pbVar3;
    do {
      bVar2 = *pbVar7;
      bVar8 = bVar2 < *pbVar4;
      if (bVar2 != *pbVar4) goto LAB_00548964;
      if (bVar2 == 0) break;
      bVar2 = pbVar7[1];
      bVar8 = bVar2 < pbVar4[1];
      if (bVar2 != pbVar4[1]) goto LAB_00548964;
      pbVar7 = pbVar7 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
  }
  else {
    pbVar4 = pbVar3;
    do {
      bVar2 = *pbVar4;
      pbVar4[(int)(local_200 + -(int)pbVar3)] = bVar2;
      pbVar4 = pbVar4 + 1;
    } while (bVar2 != 0);
    uVar6 = 0xffffffff;
    pbVar4 = local_200;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      bVar2 = *pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (bVar2 != 0);
    local_200[~uVar6 - 5] = 0;
    pbVar7 = local_100;
    pbVar4 = local_200;
    do {
      bVar2 = *pbVar4;
      bVar8 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) goto LAB_00548964;
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar8 = bVar2 < pbVar7[1];
      if (bVar2 != pbVar7[1]) goto LAB_00548964;
      pbVar4 = pbVar4 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
  }
  goto LAB_00548969;
LAB_00548964:
  iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
LAB_00548969:
  if (iVar5 == 0) {
    return pbVar3;
  }
  pbVar3 = *(byte **)(pbVar3 + 0xc0);
  goto joined_r0x005488c7;
}


