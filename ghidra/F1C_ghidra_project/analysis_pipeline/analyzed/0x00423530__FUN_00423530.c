// Function: FUN_00423530 @ 00423530
// Size (bytes): 436


undefined4 __thiscall FUN_00423530(int *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  int *piVar3;
  undefined1 *puVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  bool bVar8;
  int *local_4;
  
  if ((param_2 != (byte *)0x0) && (param_3 != (byte *)0x0)) {
    iVar5 = -1;
    pbVar2 = param_2;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
    } while (bVar1 != 0);
    if (iVar5 != -2) {
      iVar5 = -1;
      pbVar2 = param_3;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar1 = *pbVar2;
        pbVar2 = pbVar2 + 1;
      } while (bVar1 != 0);
      pbVar2 = param_2;
      pbVar6 = param_3;
      if (iVar5 != -2) {
        do {
          bVar1 = *pbVar2;
          bVar8 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_004235a6:
            iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
            goto LAB_004235ad;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar8 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_004235a6;
          pbVar2 = pbVar2 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar5 = 0;
LAB_004235ad:
        if (iVar5 != 0) {
          iVar5 = *param_1;
          if (iVar5 <= param_1[1]) {
            iVar7 = iVar5 + 0x80;
            *param_1 = iVar7;
            piVar3 = operator_new(iVar7 * 0x10 + 4);
            if (piVar3 == (int *)0x0) {
              local_4 = (int *)0x0;
            }
            else {
              local_4 = piVar3 + 1;
              *piVar3 = iVar7;
              if (-1 < iVar5 + 0x7f) {
                iVar5 = iVar5 + 0x80;
                piVar3 = local_4;
                do {
                  *piVar3 = 0;
                  piVar3[1] = -1;
                  piVar3[2] = 0;
                  piVar3[3] = -1;
                  piVar3 = piVar3 + 4;
                  iVar5 = iVar5 + -1;
                } while (iVar5 != 0);
              }
            }
            iVar5 = 0;
            if (0 < param_1[1]) {
              iVar7 = 0;
              do {
                puVar4 = *(undefined1 **)(param_1[2] + iVar7);
                if (puVar4 == (undefined1 *)0x0) {
                  puVar4 = &DAT_005ea438;
                }
                FUN_00566650(puVar4);
                puVar4 = *(undefined1 **)(param_1[2] + 8 + iVar7);
                if (puVar4 == (undefined1 *)0x0) {
                  puVar4 = &DAT_005ea438;
                }
                FUN_00566650(puVar4);
                iVar5 = iVar5 + 1;
                iVar7 = iVar7 + 0x10;
              } while (iVar5 < param_1[1]);
            }
            iVar5 = param_1[2];
            if (iVar5 != 0) {
              iVar7 = *(int *)(iVar5 + -4);
              if (-1 < iVar7 + -1) {
                do {
                  FUN_00414370();
                  FUN_00414370();
                  iVar7 = iVar7 + -1;
                } while (iVar7 != 0);
              }
              FUN_00587bcf(iVar5 + -4);
            }
            param_1[2] = (int)local_4;
          }
          param_1[1] = param_1[1] + 1;
          FUN_00566650(param_2);
          FUN_00566650(param_3);
          return 0;
        }
      }
    }
  }
  return 0xffffffff;
}


