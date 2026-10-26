// Function: FUN_00490d00 @ 00490d00
// Size (bytes): 468


void FUN_00490d00(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  short *psVar9;
  
  puVar1 = (undefined4 *)*param_2;
  param_2[2] = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    psVar9 = (short *)*puVar1;
    while (psVar9 != (short *)0x0) {
      piVar2 = (int *)*param_1;
      param_1[2] = (int)piVar2;
      if (piVar2 != (int *)0x0) {
        iVar8 = *piVar2;
        while (iVar8 != 0) {
          cVar5 = FUN_004915a0((int)*psVar9,(int)psVar9[1],(int)psVar9[2],(int)psVar9[3]);
          if (cVar5 == '\0') {
            cVar5 = FUN_00491680((int)*psVar9,(int)psVar9[1],(int)psVar9[2],(int)psVar9[3]);
            if (cVar5 != '\0') {
              iVar6 = FUN_00491350((int)*psVar9,(int)psVar9[1],(int)psVar9[2],(int)psVar9[3]);
              piVar4 = (int *)*param_1;
              piVar2 = (int *)0x0;
              while (piVar3 = piVar4, piVar3 != (int *)0x0) {
                if (*piVar3 == iVar8) {
                  if (piVar3 == (int *)param_1[2]) {
                    param_1[2] = piVar3[1];
                  }
                  if (piVar2 == (int *)0x0) {
                    *param_1 = piVar3[1];
                  }
                  else {
                    piVar2[1] = piVar3[1];
                  }
                  if ((int *)param_1[1] == piVar3) {
                    param_1[1] = (int)piVar2;
                  }
                  param_1[3] = param_1[3] + -1;
                  FUN_00491e10(1);
                  break;
                }
                piVar2 = piVar3;
                piVar4 = (int *)piVar3[1];
              }
              for (; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0xc)) {
                pvVar7 = operator_new(0xc);
                if (pvVar7 == (void *)0x0) {
                  iVar8 = 0;
                }
                else {
                  iVar8 = FUN_004bac20(iVar6,0);
                }
                if (*param_1 == 0) {
                  *param_1 = iVar8;
                  param_1[2] = iVar8;
                }
                else {
                  *(int *)(param_1[1] + 4) = iVar8;
                }
                param_1[1] = iVar8;
                iVar8 = param_1[3];
                param_1[3] = iVar8 + 1;
                if (iVar8 + 1 == 1) {
                  FUN_004ba780();
                }
              }
              goto LAB_00490e95;
            }
            iVar8 = FUN_00581780();
          }
          else {
            piVar4 = (int *)*param_1;
            piVar2 = (int *)0x0;
            while (piVar3 = piVar4, piVar3 != (int *)0x0) {
              if (*piVar3 == iVar8) {
                if (piVar3 == (int *)param_1[2]) {
                  param_1[2] = piVar3[1];
                }
                if (piVar2 == (int *)0x0) {
                  *param_1 = piVar3[1];
                }
                else {
                  piVar2[1] = piVar3[1];
                }
                if ((int *)param_1[1] == piVar3) {
                  param_1[1] = (int)piVar2;
                }
                param_1[3] = param_1[3] + -1;
                FUN_00491e40();
                FUN_00587bcf(piVar3);
                break;
              }
              piVar2 = piVar3;
              piVar4 = (int *)piVar3[1];
            }
LAB_00490e95:
            FUN_00490aa0();
            if ((int *)param_1[2] == (int *)0x0) break;
            iVar8 = *(int *)param_1[2];
          }
        }
      }
      psVar9 = (short *)FUN_00581780();
    }
  }
  return;
}


