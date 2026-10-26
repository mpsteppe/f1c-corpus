// Function: FUN_0053c6f0 @ 0053c6f0
// Size (bytes): 261


void FUN_0053c6f0(char *param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  byte local_100 [256];
  
  if ((*param_1 != '\0') && (DAT_008b8e30 < 0x20)) {
    iVar6 = -(int)param_1;
    do {
      cVar1 = *param_1;
      param_1[(int)(local_100 + iVar6)] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_100);
    iVar6 = 0;
    if (0 < DAT_008b8e30) {
      pbVar8 = &DAT_008b5a3c;
      do {
        pbVar3 = local_100;
        pbVar7 = pbVar8;
        do {
          bVar2 = *pbVar3;
          bVar9 = bVar2 < *pbVar7;
          if (bVar2 != *pbVar7) {
LAB_0053c774:
            iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
            goto LAB_0053c779;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar3[1];
          bVar9 = bVar2 < pbVar7[1];
          if (bVar2 != pbVar7[1]) goto LAB_0053c774;
          pbVar3 = pbVar3 + 2;
          pbVar7 = pbVar7 + 2;
        } while (bVar2 != 0);
        iVar4 = 0;
LAB_0053c779:
        if (iVar4 == 0) {
          return;
        }
        iVar6 = iVar6 + 1;
        pbVar8 = pbVar8 + 0x84;
      } while (iVar6 < DAT_008b8e30);
      if (0 < DAT_008b8e30) {
        puVar5 = &DAT_008b5a38 + DAT_008b8e30 * 0x21;
        iVar6 = DAT_008b8e30;
        do {
          puVar5 = puVar5 + -0x21;
          FUN_0053c6b0(puVar5);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
    iVar6 = 0;
    do {
      bVar2 = local_100[iVar6];
      (&DAT_008b5a3c)[iVar6] = bVar2;
      iVar6 = iVar6 + 1;
    } while (bVar2 != 0);
    DAT_008b5a38 = DAT_008b5a38 | 0x4000;
    DAT_008b8e30 = DAT_008b8e30 + 1;
  }
  return;
}


