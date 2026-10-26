// Function: FUN_00433d60 @ 00433d60
// Size (bytes): 243


void __thiscall FUN_00433d60(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar4 = *(int **)(param_1 + 0x1c);
  *(int **)(param_1 + 0x24) = piVar4;
  if (piVar4 != (int *)0x0) {
    iVar5 = *piVar4;
    while (iVar5 != 0) {
      puVar2 = *(undefined1 **)(iVar5 + 0x14);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(param_2,puVar2);
      if (iVar3 == 0) {
        piVar4 = (int *)0x0;
        piVar6 = *(int **)(param_1 + 0x1c);
        if (*(int **)(param_1 + 0x1c) == (int *)0x0) {
LAB_00433dfd:
          piVar4 = *(int **)(param_1 + 0x1c);
          *(int **)(param_1 + 0x24) = piVar4;
        }
        else {
          do {
            if (*piVar6 == iVar5) {
              if (piVar6 == *(int **)(param_1 + 0x24)) {
                *(int *)(param_1 + 0x24) = piVar6[1];
              }
              if (piVar4 == (int *)0x0) {
                *(int *)(param_1 + 0x1c) = piVar6[1];
              }
              else {
                piVar4[1] = piVar6[1];
              }
              if (*(int **)(param_1 + 0x20) == piVar6) {
                *(int **)(param_1 + 0x20) = piVar4;
              }
              *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + -1;
              if (((char)piVar6[2] != '\0') && (*piVar6 != 0)) {
                FUN_00433e60(1);
              }
              FUN_00587bcf(piVar6);
              goto LAB_00433dfd;
            }
            piVar1 = piVar6 + 1;
            piVar4 = piVar6;
            piVar6 = (int *)*piVar1;
          } while ((int *)*piVar1 != (int *)0x0);
          piVar4 = *(int **)(param_1 + 0x1c);
          *(int **)(param_1 + 0x24) = piVar4;
        }
      }
      else {
        if (*(int *)(param_1 + 0x24) != 0) {
          *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(*(int *)(param_1 + 0x24) + 4);
        }
        piVar4 = *(int **)(param_1 + 0x24);
      }
      if (piVar4 == (int *)0x0) break;
      iVar5 = *piVar4;
    }
  }
  puVar2 = *(undefined1 **)(param_1 + 0x10);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  iVar5 = FUN_00588410(param_2,puVar2);
  if (iVar5 == 0) {
    FUN_00566650(&DAT_005ea438);
  }
  return;
}


