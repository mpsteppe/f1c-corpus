// Function: FUN_004c6150 @ 004c6150
// Strings:  [Filter Properties]


undefined4 __thiscall FUN_004c6150(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined1 local_100;
  undefined4 local_ff;
  
  if ((*param_2 != 0) && (0 < param_3)) {
    piVar6 = *(int **)(param_1 + 8);
    *(int **)(param_1 + 0x10) = piVar6;
    if ((piVar6 != (int *)0x0) && (piVar6 = (int *)*piVar6, piVar6 != (int *)0x0)) {
LAB_004c6190:
      iVar5 = *piVar6 * 0x18c + DAT_008ac490;
      if (iVar5 != 0) {
        local_100 = DAT_005ea438;
        puVar2 = &local_ff;
        for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar2 = 0;
          puVar2 = puVar2 + 1;
        }
        *(undefined2 *)puVar2 = 0;
        *(undefined1 *)((int)puVar2 + 2) = 0;
        iVar5 = FUN_004c58a0(&local_100,0x100,s_Filter_Properties_005d31ec,iVar5 + 0x104);
        if ((iVar5 == 0) && (iVar5 = 0, 0 < param_3)) {
          do {
            iVar4 = FUN_00566810();
            if (iVar4 != 0) {
              piVar7 = *(int **)(param_1 + 8);
              piVar3 = (int *)0x0;
              if (piVar7 != (int *)0x0) goto LAB_004c6250;
              goto LAB_004c62b4;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < param_3);
        }
      }
      if (*(int *)(param_1 + 0x10) != 0) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 4);
      }
      puVar2 = *(undefined4 **)(param_1 + 0x10);
      goto LAB_004c6223;
    }
  }
LAB_004c6231:
  return *(undefined4 *)(param_1 + 0x14);
LAB_004c6250:
  if ((int *)*piVar7 != piVar6) goto code_r0x004c6254;
  if (piVar7 == *(int **)(param_1 + 0x10)) {
    *(int *)(param_1 + 0x10) = piVar7[1];
  }
  if (piVar3 == (int *)0x0) {
    *(int *)(param_1 + 8) = piVar7[1];
  }
  else {
    piVar3[1] = piVar7[1];
  }
  if (*(int **)(param_1 + 0xc) == piVar7) {
    *(int **)(param_1 + 0xc) = piVar3;
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  if (((char)piVar7[2] != '\0') && (iVar5 = *piVar7, iVar5 != 0)) {
    FUN_00414370();
    FUN_00587bcf(iVar5);
  }
  FUN_00587bcf(piVar7);
LAB_004c62b4:
  puVar2 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 0x10) = puVar2;
  goto LAB_004c6223;
code_r0x004c6254:
  piVar1 = piVar7 + 1;
  piVar3 = piVar7;
  piVar7 = (int *)*piVar1;
  if ((int *)*piVar1 == (int *)0x0) goto code_r0x004c625d;
  goto LAB_004c6250;
code_r0x004c625d:
  puVar2 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 0x10) = puVar2;
LAB_004c6223:
  if ((puVar2 == (undefined4 *)0x0) || (piVar6 = (int *)*puVar2, piVar6 == (int *)0x0))
  goto LAB_004c6231;
  goto LAB_004c6190;
}


