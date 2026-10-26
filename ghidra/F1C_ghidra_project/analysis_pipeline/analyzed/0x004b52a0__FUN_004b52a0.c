// Function: FUN_004b52a0 @ 004b52a0
// Size (bytes): 215


void __fastcall FUN_004b52a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  *(undefined4 *)(param_1 + 0x30) = DAT_005acd24;
  do {
    piVar5 = *(int **)(param_1 + 0x20);
    *(int **)(param_1 + 0x28) = piVar5;
    if ((piVar5 == (int *)0x0) || (iVar1 = *piVar5, iVar1 == 0)) {
      return;
    }
    piVar4 = (int *)0x0;
    while (piVar3 = piVar5, piVar3 != (int *)0x0) {
      if (*piVar3 == iVar1) {
        if (piVar3 == *(int **)(param_1 + 0x28)) {
          *(int *)(param_1 + 0x28) = piVar3[1];
        }
        if (piVar4 == (int *)0x0) {
          *(int *)(param_1 + 0x20) = piVar3[1];
        }
        else {
          piVar4[1] = piVar3[1];
        }
        if (*(int **)(param_1 + 0x24) == piVar3) {
          *(int **)(param_1 + 0x24) = piVar4;
        }
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -1;
        if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
          FUN_004b0170();
          FUN_00587bcf(iVar2);
        }
        FUN_00587bcf(piVar3);
        break;
      }
      piVar4 = piVar3;
      piVar5 = (int *)piVar3[1];
    }
    piVar5 = operator_new(0xc);
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      *piVar5 = iVar1;
      piVar5[1] = 0;
      *(undefined1 *)(piVar5 + 2) = 0;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      *(int **)(param_1 + 0x14) = piVar5;
      *(int **)(param_1 + 0x18) = piVar5;
      *(int **)(param_1 + 0x10) = piVar5;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    }
    else {
      piVar5[1] = *(int *)(param_1 + 0x10);
      *(int **)(param_1 + 0x10) = piVar5;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    }
  } while( true );
}


