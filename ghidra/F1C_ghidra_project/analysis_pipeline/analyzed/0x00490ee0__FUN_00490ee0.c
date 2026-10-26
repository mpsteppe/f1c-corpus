// Function: FUN_00490ee0 @ 00490ee0
// Size (bytes): 483


uint FUN_00490ee0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  char cVar2;
  short *psVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *local_10;
  int *local_c;
  int *local_8;
  int local_4;
  
  psVar3 = (short *)FUN_00490940(param_4,param_5);
  piVar5 = (int *)*param_1;
  param_1[2] = (int)piVar5;
  if ((piVar5 != (int *)0x0) && (iVar7 = *piVar5, iVar7 != 0)) {
    do {
      cVar2 = FUN_00491680((int)*psVar3,(int)psVar3[1],(int)psVar3[2],(int)psVar3[3]);
      if (cVar2 == '\0') {
        if (param_1[2] == 0) break;
        piVar5 = *(int **)(param_1[2] + 4);
        param_1[2] = (int)piVar5;
      }
      else {
        for (iVar4 = FUN_00491350((int)*psVar3,(int)psVar3[1],(int)psVar3[2],(int)psVar3[3]);
            iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
          piVar5 = operator_new(0xc);
          if (piVar5 == (int *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            *piVar5 = iVar4;
            piVar5[1] = 0;
            *(undefined1 *)(piVar5 + 2) = 0;
          }
          if (*param_1 == 0) {
            *param_1 = (int)piVar5;
            param_1[2] = (int)piVar5;
          }
          else {
            *(int **)(param_1[1] + 4) = piVar5;
          }
          param_1[1] = (int)piVar5;
          param_1[3] = param_1[3] + 1;
        }
        piVar5 = (int *)0x0;
        piVar9 = (int *)*param_1;
        if ((int *)*param_1 == (int *)0x0) {
LAB_00490ffe:
          FUN_00490aa0();
          piVar5 = (int *)param_1[2];
        }
        else {
          do {
            if (*piVar9 == iVar7) {
              if (piVar9 == (int *)param_1[2]) {
                param_1[2] = piVar9[1];
              }
              if (piVar5 == (int *)0x0) {
                *param_1 = piVar9[1];
              }
              else {
                piVar5[1] = piVar9[1];
              }
              if ((int *)param_1[1] == piVar9) {
                param_1[1] = (int)piVar5;
              }
              param_1[3] = param_1[3] + -1;
              FUN_00491e10(1);
              goto LAB_00490ffe;
            }
            piVar1 = piVar9 + 1;
            piVar5 = piVar9;
            piVar9 = (int *)*piVar1;
          } while ((int *)*piVar1 != (int *)0x0);
          FUN_00490aa0();
          piVar5 = (int *)param_1[2];
        }
      }
      if ((piVar5 == (int *)0x0) || (iVar7 = *piVar5, iVar7 == 0)) break;
    } while( true );
  }
  local_10 = (int *)0x0;
  local_c = (int *)0x0;
  local_8 = (int *)0x0;
  local_4 = 0;
  if (psVar3 != (short *)0x0) {
    pvVar6 = operator_new(0xc);
    if (pvVar6 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_004bac20(psVar3,0);
    }
    piVar9 = piVar5;
    piVar1 = piVar5;
    if (local_10 != (int *)0x0) {
      local_c[1] = (int)piVar5;
      piVar9 = local_10;
      piVar1 = local_8;
    }
    local_8 = piVar1;
    local_10 = piVar9;
    local_4 = local_4 + 1;
    local_c = piVar5;
  }
  FUN_00490d00(&local_10,param_1);
  local_8 = local_10;
  if (local_10 != (int *)0x0) {
    iVar7 = *local_10;
    while (iVar7 != 0) {
      FUN_00434030(iVar7,0);
      iVar7 = FUN_00581780();
    }
  }
  uVar8 = FUN_00491db0();
  return uVar8 & 0xffffff00;
}


