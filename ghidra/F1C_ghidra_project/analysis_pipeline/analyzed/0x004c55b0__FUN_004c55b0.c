// Function: FUN_004c55b0 @ 004c55b0
// Size (bytes): 211


void FUN_004c55b0(char *param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  bool bVar9;
  byte local_a0 [80];
  byte local_50 [80];
  
  iVar6 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_50 + iVar6)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_50);
  iVar6 = 0;
  if (DAT_008ac488 < 1) {
    return;
  }
  iVar8 = 0;
  do {
    pcVar3 = (char *)(iVar8 + 0x104 + DAT_008ac490);
    iVar5 = -(int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)(local_a0 + iVar5)] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_a0);
    pbVar7 = local_a0;
    pbVar4 = local_50;
    do {
      bVar2 = *pbVar4;
      bVar9 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) {
LAB_004c564a:
        iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        goto LAB_004c564f;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar4[1];
      bVar9 = bVar2 < pbVar7[1];
      if (bVar2 != pbVar7[1]) goto LAB_004c564a;
      pbVar4 = pbVar4 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar2 != 0);
    iVar5 = 0;
LAB_004c564f:
    if (iVar5 == 0) {
      DAT_008ac48c = iVar6;
      return;
    }
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 0x18c;
    if (DAT_008ac488 <= iVar6) {
      return;
    }
  } while( true );
}


