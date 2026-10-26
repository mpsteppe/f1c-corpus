// Function: FUN_00490940 @ 00490940
// Size (bytes): 345


int __fastcall
FUN_00490940(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar5 = FUN_00490930();
  piVar6 = *(int **)(iVar5 + 0x10);
  piVar1 = (int *)(iVar5 + 0x10);
  iVar8 = 0;
  *(int **)(iVar5 + 0x18) = piVar6;
  if (piVar6 != (int *)0x0) {
    iVar8 = *piVar6;
    *(undefined1 *)(piVar6 + 2) = 0;
    cVar4 = FUN_00491d30(iVar8,1);
    if (cVar4 == '\0') {
      iVar8 = 0;
    }
  }
  if (iVar8 == 0) {
    piVar6 = operator_new(4);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      puVar7 = operator_new(0x44);
      if (puVar7 == (undefined4 *)0x0) {
        *piVar6 = 0;
      }
      else {
        *puVar7 = 4;
        iVar8 = 4;
        do {
          FUN_004912f0();
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        *piVar6 = (int)(puVar7 + 1);
      }
    }
    FUN_00434030(piVar6,1);
    iVar8 = 0;
    do {
      FUN_004bb490(*piVar6 + iVar8,0);
      iVar8 = iVar8 + 0x10;
    } while (iVar8 < 0x40);
    piVar6 = (int *)*piVar1;
    iVar8 = 0;
    *(int **)(iVar5 + 0x18) = piVar6;
    if (piVar6 != (int *)0x0) {
      *(undefined1 *)(piVar6 + 2) = 0;
      iVar8 = *piVar6;
      if (iVar8 != 0) {
        piVar3 = (int *)*piVar1;
        piVar6 = (int *)0x0;
        while (piVar2 = piVar3, piVar2 != (int *)0x0) {
          if (*piVar2 == iVar8) {
            if (piVar2 == *(int **)(iVar5 + 0x18)) {
              *(int *)(iVar5 + 0x18) = piVar2[1];
            }
            if (piVar6 == (int *)0x0) {
              *piVar1 = piVar2[1];
            }
            else {
              piVar6[1] = piVar2[1];
            }
            if (*(int **)(iVar5 + 0x14) == piVar2) {
              *(int **)(iVar5 + 0x14) = piVar6;
            }
            *(int *)(iVar5 + 0x1c) = *(int *)(iVar5 + 0x1c) + -1;
            FUN_00491e40();
            FUN_00587bcf(piVar2);
            goto LAB_00490a36;
          }
          piVar6 = piVar2;
          piVar3 = (int *)piVar2[1];
        }
      }
      iVar8 = 0;
    }
  }
LAB_00490a36:
  FUN_004916e0(param_1,param_2,param_3,param_4);
  return iVar8;
}


