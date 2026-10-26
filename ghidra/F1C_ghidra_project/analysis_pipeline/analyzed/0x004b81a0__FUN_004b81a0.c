// Function: FUN_004b81a0 @ 004b81a0
// Size (bytes): 445


undefined4 __thiscall FUN_004b81a0(int param_1,char *param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  char *pcVar11;
  char local_50 [80];
  
  FUN_004b8360();
  if (param_2 != (char *)0x0) {
    iVar9 = -1;
    pcVar11 = param_2;
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      cVar2 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar2 != '\0');
    if (iVar9 == -2) goto LAB_004b81e5;
  }
  FUN_0058815f(local_50,&DAT_005c3280,*(int *)(param_1 + 0x6cc) + 1);
  param_2 = local_50;
LAB_004b81e5:
  puVar5 = operator_new(0xc);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = *(undefined4 *)(param_1 + 0xf38);
    puVar5[1] = 0;
    puVar5[2] = 0xffffffff;
    FUN_00566650(param_2);
  }
  piVar1 = (int *)(param_1 + 0x6c0);
  if (puVar5 != (undefined4 *)0x0) {
    puVar6 = operator_new(0x10);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = puVar5;
      puVar6[1] = 0;
      puVar6[2] = 0;
      *(undefined1 *)(puVar6 + 3) = 1;
    }
    if (*piVar1 == 0) {
      *piVar1 = (int)puVar6;
      *(undefined4 **)(param_1 + 0x6c8) = puVar6;
    }
    else {
      *(undefined4 **)(*(int *)(param_1 + 0x6c4) + 4) = puVar6;
      puVar6[2] = *(undefined4 *)(param_1 + 0x6c4);
    }
    *(undefined4 **)(param_1 + 0x6c4) = puVar6;
    *(int *)(param_1 + 0x6cc) = *(int *)(param_1 + 0x6cc) + 1;
  }
  puVar5 = (undefined4 *)*piVar1;
  iVar9 = 0;
  puVar6 = puVar5;
  if (puVar5 != (undefined4 *)0x0) {
    do {
      puVar6 = (undefined4 *)puVar6[1];
      iVar9 = iVar9 + 1;
    } while (puVar6 != (undefined4 *)0x0);
    if (1 < iVar9) {
      iVar9 = iVar9 / 2 + -1;
      puVar6 = puVar5;
      if (0 < iVar9) {
        do {
          iVar9 = iVar9 + -1;
          puVar6 = (undefined4 *)puVar6[1];
        } while (iVar9 != 0);
      }
      uVar3 = puVar6[1];
      puVar6[1] = 0;
      puVar7 = (undefined4 *)FUN_004bb2e0(puVar5);
      puVar6 = (undefined4 *)FUN_004bb2e0(uVar3);
      puVar5 = puVar6;
      if ((puVar7 != (undefined4 *)0x0) && (puVar5 = puVar7, puVar6 != (undefined4 *)0x0)) {
        if (*(float *)*puVar6 <= *(float *)*puVar7) {
          puVar4 = (undefined4 *)puVar6[1];
          puVar10 = puVar7;
          puVar7 = puVar6;
        }
        else {
          puVar4 = puVar6;
          puVar10 = (undefined4 *)puVar7[1];
          puVar6 = puVar7;
        }
        while (puVar5 = puVar7, puVar10 != (undefined4 *)0x0) {
          if (puVar4 == (undefined4 *)0x0) {
            if (puVar10 == (undefined4 *)0x0) goto LAB_004b8315;
            puVar6[1] = puVar10;
            goto LAB_004b8322;
          }
          if (*(float *)*puVar4 <= *(float *)*puVar10) {
            puVar5 = (undefined4 *)puVar4[1];
            puVar8 = puVar4;
          }
          else {
            puVar8 = puVar10;
            puVar5 = puVar4;
            puVar10 = (undefined4 *)puVar10[1];
          }
          puVar6[1] = puVar8;
          puVar4 = puVar5;
          puVar6 = puVar8;
        }
        if (puVar4 == (undefined4 *)0x0) {
LAB_004b8315:
          puVar6[1] = 0;
        }
        else {
          puVar6[1] = puVar4;
        }
      }
    }
  }
LAB_004b8322:
  *piVar1 = (int)puVar5;
  if (puVar5 != (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
    puVar7 = (undefined4 *)puVar5[1];
    while (puVar4 = puVar7, puVar4 != (undefined4 *)0x0) {
      puVar5[2] = puVar6;
      puVar6 = puVar5;
      puVar5 = puVar4;
      puVar7 = (undefined4 *)puVar4[1];
    }
    puVar5[2] = puVar6;
  }
  *(undefined4 **)(param_1 + 0x6c4) = puVar5;
  *(int *)(param_1 + 0x6c8) = *piVar1;
  *(undefined1 *)(param_1 + 0x6d0) = 1;
  return 1;
}


