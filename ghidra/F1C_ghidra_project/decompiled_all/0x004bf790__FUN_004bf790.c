// Function: FUN_004bf790 @ 004bf790
// Strings:  [%s NOT: NotAI]


int __thiscall FUN_004bf790(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  undefined4 *puVar14;
  float10 fVar15;
  int local_208;
  undefined1 local_200 [512];
  
  local_208 = 0;
  FUN_004bf730();
  FUN_0058815f(local_200,s__s_NOT__NotAI_005d266c,param_4);
  FUN_004c4d50(local_200);
  if (param_2 < 0xb) {
    iVar2 = FUN_004bfa00(param_2,param_3);
    if (iVar2 == param_2) {
      return param_2;
    }
    FUN_004bf730();
  }
  iVar3 = FUN_005871f0();
  iVar2 = _rand();
  iVar2 = iVar2 << 1;
  if (0 < iVar3) {
    if (0 < param_2) {
      do {
        iVar2 = iVar2 % iVar3;
        puVar4 = (undefined4 *)FUN_004c5070(iVar2);
        puVar5 = (undefined1 *)*puVar4;
        if (puVar5 == (undefined1 *)0x0) {
          puVar5 = &DAT_005ea438;
        }
        iVar6 = FUN_00588410(puVar5,param_3);
        if ((iVar6 != 0) || (iVar3 < 2)) {
          puVar7 = operator_new(8);
          puVar14 = (undefined4 *)0x0;
          if (puVar7 != (undefined4 *)0x0) {
            puVar7[1] = 0;
            *puVar7 = 0xffffffff;
            puVar14 = puVar7;
          }
          uVar8 = FUN_004c50e0(iVar2);
          *puVar14 = uVar8;
          fVar15 = (float10)FUN_004bf6a0(puVar4 + 0x2f);
          puVar14[1] = (float)fVar15;
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            *puVar4 = puVar14;
            puVar4[1] = 0;
            *(undefined1 *)(puVar4 + 2) = 1;
          }
          if (*param_1 == 0) {
            *param_1 = (int)puVar4;
            param_1[2] = (int)puVar4;
          }
          else {
            *(undefined4 **)(param_1[1] + 4) = puVar4;
          }
          param_1[1] = (int)puVar4;
          local_208 = local_208 + 1;
          param_1[3] = param_1[3] + 1;
        }
        iVar2 = iVar2 + 1;
      } while (local_208 < param_2);
    }
    piVar12 = (int *)*param_1;
    iVar2 = 0;
    piVar10 = piVar12;
    if (piVar12 != (int *)0x0) {
      do {
        piVar10 = (int *)piVar10[1];
        iVar2 = iVar2 + 1;
      } while (piVar10 != (int *)0x0);
      if (1 < iVar2) {
        iVar2 = iVar2 / 2 + -1;
        piVar10 = piVar12;
        if (0 < iVar2) {
          do {
            iVar2 = iVar2 + -1;
            piVar10 = (int *)piVar10[1];
          } while (iVar2 != 0);
        }
        iVar2 = piVar10[1];
        piVar10[1] = 0;
        piVar9 = (int *)FUN_004c2e20(piVar12);
        piVar10 = (int *)FUN_004c2e20(iVar2);
        piVar12 = piVar10;
        if ((piVar9 != (int *)0x0) && (piVar12 = piVar9, piVar10 != (int *)0x0)) {
          if (*(float *)(*piVar10 + 4) <= *(float *)(*piVar9 + 4)) {
            piVar1 = (int *)piVar10[1];
            piVar13 = piVar9;
            piVar9 = piVar10;
          }
          else {
            piVar1 = piVar10;
            piVar13 = (int *)piVar9[1];
            piVar10 = piVar9;
          }
          while (piVar12 = piVar9, piVar13 != (int *)0x0) {
            if (piVar1 == (int *)0x0) {
              if (piVar13 == (int *)0x0) goto LAB_004bf9bf;
              piVar10[1] = (int)piVar13;
              goto LAB_004bf9cc;
            }
            if (*(float *)(*piVar1 + 4) <= *(float *)(*piVar13 + 4)) {
              piVar12 = (int *)piVar1[1];
              piVar11 = piVar1;
            }
            else {
              piVar11 = piVar13;
              piVar12 = piVar1;
              piVar13 = (int *)piVar13[1];
            }
            piVar10[1] = (int)piVar11;
            piVar1 = piVar12;
            piVar10 = piVar11;
          }
          if (piVar1 == (int *)0x0) {
LAB_004bf9bf:
            piVar10[1] = 0;
          }
          else {
            piVar10[1] = (int)piVar1;
          }
        }
      }
    }
LAB_004bf9cc:
    *param_1 = (int)piVar12;
    piVar10 = piVar12;
    if (piVar12 != (int *)0x0) {
      piVar9 = (int *)piVar12[1];
      while (piVar1 = piVar9, piVar1 != (int *)0x0) {
        piVar10 = piVar1;
        piVar9 = (int *)piVar1[1];
      }
    }
    param_1[1] = (int)piVar10;
    param_1[2] = (int)piVar12;
  }
  return local_208;
}


