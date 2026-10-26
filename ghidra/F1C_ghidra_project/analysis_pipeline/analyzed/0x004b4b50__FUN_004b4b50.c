// Function: FUN_004b4b50 @ 004b4b50
// Size (bytes): 693


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_004b4b50(char *param_1,undefined4 param_2,float *param_3)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  short sVar11;
  int iVar12;
  float local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  local_18 = 0;
  if (*param_1 != '\0') {
    piVar10 = (int *)(param_1 + 0x70);
    iVar12 = 4;
    do {
      iVar6 = FUN_004bab20(*piVar10);
      *piVar10 = iVar6;
      iVar9 = iVar6;
      if (iVar6 != 0) {
        iVar5 = *(int *)(iVar6 + 4);
        while (iVar3 = iVar5, iVar3 != 0) {
          iVar9 = iVar3;
          iVar5 = *(int *)(iVar3 + 4);
        }
      }
      piVar10[1] = iVar9;
      piVar10[2] = iVar6;
      piVar10 = piVar10 + 4;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    *param_1 = '\0';
  }
  iVar12 = 0;
  piVar10 = (int *)(param_1 + 0x7c);
  do {
    if (0 < *piVar10) break;
    iVar12 = iVar12 + 1;
    piVar10 = piVar10 + 4;
  } while (iVar12 < 4);
  if (iVar12 == 4) {
    return 0;
  }
  piVar10 = (int *)(param_1 + 0x70);
  local_1c = 1e+38;
  iVar12 = 4;
  piVar8 = piVar10;
  do {
    piVar1 = (int *)*piVar8;
    piVar8[2] = (int)piVar1;
    if (((piVar1 != (int *)0x0) && (iVar9 = *piVar1, iVar9 != 0)) &&
       (*(float *)(iVar9 + 4) < local_1c)) {
      local_1c = *(float *)(iVar9 + 4);
    }
    piVar8 = piVar8 + 4;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  local_10 = (int *)0x0;
  local_c = (int *)0x0;
  sVar11 = 0;
  local_14 = 4;
  do {
    piVar8 = (int *)*piVar10;
    piVar10[2] = (int)piVar8;
    if ((piVar8 != (int *)0x0) && (iVar12 = *piVar8, iVar12 != 0)) {
      while ((fVar2 = local_1c - *(float *)(iVar12 + 4), -_DAT_005acd0c < fVar2 &&
             (fVar2 < _DAT_005acd0c))) {
        piVar1 = (int *)*piVar10;
        piVar8 = (int *)0x0;
        while (piVar4 = piVar1, piVar4 != (int *)0x0) {
          if (*piVar4 == iVar12) {
            if (piVar4 == (int *)piVar10[2]) {
              piVar10[2] = piVar4[1];
            }
            if (piVar8 == (int *)0x0) {
              *piVar10 = piVar4[1];
            }
            else {
              piVar8[1] = piVar4[1];
            }
            if ((int *)piVar10[1] == piVar4) {
              piVar10[1] = (int)piVar8;
            }
            piVar10[3] = piVar10[3] + -1;
            FUN_00582290();
            FUN_00587bcf(piVar4);
            break;
          }
          piVar8 = piVar4;
          piVar1 = (int *)piVar4[1];
        }
        pvVar7 = operator_new(0xc);
        if (pvVar7 == (void *)0x0) {
          piVar8 = (int *)0x0;
        }
        else {
          piVar8 = (int *)FUN_004bac20(iVar12,0);
        }
        piVar1 = piVar8;
        if (local_10 != (int *)0x0) {
          local_c[1] = (int)piVar8;
          piVar1 = local_10;
        }
        local_10 = piVar1;
        piVar1 = (int *)*piVar10;
        sVar11 = sVar11 + 1;
        piVar10[2] = (int)piVar1;
        local_c = piVar8;
        if ((piVar1 == (int *)0x0) || (iVar12 = *piVar1, iVar12 == 0)) break;
      }
    }
    piVar10 = piVar10 + 4;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  *param_3 = local_1c;
  *(short *)(param_3 + 2) = sVar11;
  FUN_004b4470(param_2);
  if (local_10 != (int *)0x0) {
    iVar12 = *local_10;
    local_8 = local_10;
    while (iVar12 != 0) {
      if (iVar12 != 0) {
        piVar10 = (int *)0x0;
        for (piVar8 = local_10; piVar8 != (int *)0x0; piVar8 = (int *)piVar8[1]) {
          if (*piVar8 == iVar12) {
            if (piVar8 == local_8) {
              local_8 = (int *)piVar8[1];
            }
            piVar1 = (int *)piVar8[1];
            if (piVar10 != (int *)0x0) {
              piVar10[1] = piVar8[1];
              piVar1 = local_10;
            }
            local_10 = piVar1;
            if (local_c == piVar8) {
              local_c = piVar10;
            }
            FUN_004646f0(1);
            break;
          }
          piVar10 = piVar8;
        }
      }
      FUN_004b42e0(param_2,*param_3,iVar12);
      local_18 = local_18 + 1;
      FUN_004bb490(iVar12,0);
      iVar12 = FUN_004ba790();
    }
  }
  FUN_0049af30();
  return local_18;
}


