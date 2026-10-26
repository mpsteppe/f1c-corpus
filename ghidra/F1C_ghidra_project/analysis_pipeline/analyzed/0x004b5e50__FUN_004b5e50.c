// Function: FUN_004b5e50 @ 004b5e50
// Size (bytes): 267


void __fastcall FUN_004b5e50(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int local_4;
  
  piVar6 = (int *)(param_1 + 0x40);
  local_4 = 0x68;
  do {
    piVar5 = (int *)*piVar6;
    piVar6[2] = (int)piVar5;
    if (piVar5 != (int *)0x0) {
      iVar1 = *piVar5;
      while (iVar1 != 0) {
        piVar4 = (int *)*piVar6;
        piVar5 = (int *)0x0;
        while (piVar3 = piVar4, piVar3 != (int *)0x0) {
          if (*piVar3 == iVar1) {
            if (piVar3 == (int *)piVar6[2]) {
              piVar6[2] = piVar3[1];
            }
            if (piVar5 == (int *)0x0) {
              *piVar6 = piVar3[1];
            }
            else {
              piVar5[1] = piVar3[1];
            }
            if ((int *)piVar6[1] == piVar3) {
              piVar6[1] = (int)piVar5;
            }
            piVar6[3] = piVar6[3] + -1;
            if (((char)piVar3[2] != '\0') && (iVar2 = *piVar3, iVar2 != 0)) {
              FUN_004b0170();
              FUN_00587bcf(iVar2);
            }
            FUN_00587bcf(piVar3);
            break;
          }
          piVar5 = piVar3;
          piVar4 = (int *)piVar3[1];
        }
        FUN_004b4f70();
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
        }
        else {
          piVar5[1] = *(int *)(param_1 + 0x10);
        }
        *(int **)(param_1 + 0x10) = piVar5;
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        piVar5 = (int *)*piVar6;
        piVar6[2] = (int)piVar5;
        if (piVar5 == (int *)0x0) break;
        iVar1 = *piVar5;
      }
    }
    piVar6 = piVar6 + 4;
    local_4 = local_4 + -1;
    if (local_4 == 0) {
      return;
    }
  } while( true );
}


