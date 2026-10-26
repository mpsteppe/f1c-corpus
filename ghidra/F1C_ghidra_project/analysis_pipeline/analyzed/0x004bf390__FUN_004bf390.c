// Function: FUN_004bf390 @ 004bf390
// Size (bytes): 352


void FUN_004bf390(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar7 = param_1;
  iVar6 = DAT_007c56a4;
  iVar5 = DAT_005c329c;
  iVar1 = *(int *)(param_1 + 0x4060);
  iVar9 = 0;
  bVar4 = false;
  param_1 = 1;
  if (0 < DAT_005c329c) {
    do {
      iVar8 = 0;
      if (0 < iVar5) {
        do {
          iVar2 = (&DAT_007c54f0)[iVar8];
          iVar3 = *(int *)(iVar2 + 0x4060);
          if (iVar3 != param_1) goto LAB_004bf4cc;
          if (iVar2 == iVar7) {
LAB_004bf4c3:
            param_1 = iVar5 + 1;
            iVar8 = iVar5;
          }
          else {
            if (bVar4) {
              if ((iVar9 == iVar2) ||
                 (FUN_004bc2f0(iVar3 + 1), iVar8 = iVar5, iVar9 = iVar2,
                 iVar1 != *(int *)(iVar2 + 0x4060))) goto LAB_004bf4cc;
              goto LAB_004bf4c3;
            }
            if (iVar6 == 7) {
              if ((*(int *)(iVar2 + 0x403c) < *(int *)(iVar7 + 0x403c)) ||
                 ((iVar8 = iVar5, *(int *)(iVar2 + 0x403c) == *(int *)(iVar7 + 0x403c) &&
                  (*(float *)(iVar7 + 0x4098) < *(float *)(iVar2 + 0x4098))))) {
LAB_004bf46a:
                bVar4 = true;
                if (*(int *)(iVar7 + 0x4060) + -1 == iVar3) {
                  param_1 = iVar5 + 1;
                }
                FUN_004bc2f0(iVar3);
                FUN_004bc2f0(*(int *)(iVar2 + 0x4060) + 1);
                iVar8 = iVar5;
                iVar9 = iVar2;
              }
            }
            else if ((*(float *)(iVar7 + 0x409c) < *(float *)(iVar2 + 0x409c)) ||
                    (iVar8 = iVar5, *(float *)(iVar2 + 0x409c) < DAT_0059e440)) goto LAB_004bf46a;
          }
LAB_004bf4cc:
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar5);
      }
      param_1 = param_1 + 1;
    } while (param_1 <= iVar5);
  }
  return;
}


