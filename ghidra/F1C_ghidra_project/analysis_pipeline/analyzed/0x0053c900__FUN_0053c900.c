// Function: FUN_0053c900 @ 0053c900
// Size (bytes): 192


void FUN_0053c900(char *param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  byte local_100 [256];
  
  if (*param_1 != '\0') {
    iVar7 = -(int)param_1;
    do {
      cVar1 = *param_1;
      param_1[(int)(local_100 + iVar7)] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_100);
    iVar7 = 0;
    if (0 < DAT_008b8e30) {
      pbVar5 = &DAT_008b5a3c;
      do {
        pbVar3 = local_100;
        pbVar6 = pbVar5;
        do {
          bVar2 = *pbVar3;
          bVar8 = bVar2 < *pbVar6;
          if (bVar2 != *pbVar6) {
LAB_0053c97a:
            iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_0053c97f;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar3[1];
          bVar8 = bVar2 < pbVar6[1];
          if (bVar2 != pbVar6[1]) goto LAB_0053c97a;
          pbVar3 = pbVar3 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar2 != 0);
        iVar4 = 0;
LAB_0053c97f:
        if (iVar4 == 0) {
          (&DAT_008b5a38)[iVar7 * 0x21] = (&DAT_008b5a38)[iVar7 * 0x21] | 0x400;
          break;
        }
        iVar7 = iVar7 + 1;
        pbVar5 = pbVar5 + 0x84;
      } while (iVar7 < DAT_008b8e30);
    }
    FUN_0053ca00();
  }
  return;
}


