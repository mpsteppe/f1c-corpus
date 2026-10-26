// Function: FUN_004b7860 @ 004b7860
// Size (bytes): 404


undefined4 __thiscall FUN_004b7860(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  iVar2 = FUN_004b68c0();
  if (((iVar2 == *(int *)(param_1 + 0x9b4)) || (param_2 != '\0')) && (0 < iVar2)) {
    while( true ) {
      piVar6 = *(int **)(param_1 + 0x30);
      iVar2 = 0;
      *(int **)(param_1 + 0x38) = piVar6;
      if (piVar6 != (int *)0x0) {
        iVar2 = *piVar6;
        *(undefined1 *)(piVar6 + 2) = 0;
        cVar1 = FUN_004bb6b0(iVar2,1);
        if (cVar1 == '\0') {
          iVar2 = 0;
        }
      }
      if (iVar2 == 0) {
        pvVar3 = operator_new(4);
        if (pvVar3 == (void *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_004baac0(0);
        }
        FUN_004bb150(uVar4,0);
        iVar2 = 0;
        FUN_004ba780();
        piVar6 = *(int **)(param_1 + 0x38);
        if (piVar6 != (int *)0x0) {
          iVar2 = *piVar6;
          *(undefined1 *)(piVar6 + 2) = 0;
          cVar1 = FUN_004bb6b0(iVar2,1);
          if (cVar1 == '\0') {
            iVar2 = 0;
          }
        }
      }
      iVar5 = FUN_004b4b50(param_1 + 0x6e4,iVar2);
      if (iVar5 < 1) break;
      *(int *)(param_1 + 0xf24) = *(int *)(param_1 + 0xf24) + 1;
      *(int *)(param_1 + 0xf28) = *(int *)(param_1 + 0xf28) + iVar5;
      if (iVar2 != 0) {
        piVar6 = operator_new(0x10);
        if (piVar6 == (int *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          *piVar6 = iVar2;
          piVar6[1] = 0;
          piVar6[2] = 0;
          *(undefined1 *)(piVar6 + 3) = 0;
        }
        if (*(int *)(param_1 + 0x714) == 0) {
          *(int **)(param_1 + 0x714) = piVar6;
          *(int **)(param_1 + 0x71c) = piVar6;
        }
        else {
          *(int **)(*(int *)(param_1 + 0x718) + 4) = piVar6;
          piVar6[2] = *(int *)(param_1 + 0x718);
        }
        *(int **)(param_1 + 0x718) = piVar6;
        *(int *)(param_1 + 0x720) = *(int *)(param_1 + 0x720) + 1;
      }
    }
    FUN_004b4460();
    if (iVar2 != 0) {
      piVar6 = operator_new(0xc);
      if (piVar6 == (int *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        *piVar6 = iVar2;
        piVar6[1] = 0;
        *(undefined1 *)(piVar6 + 2) = 0;
      }
      if (*(int *)(param_1 + 0x30) == 0) {
        *(int **)(param_1 + 0x34) = piVar6;
        *(int **)(param_1 + 0x38) = piVar6;
      }
      else {
        piVar6[1] = *(int *)(param_1 + 0x30);
      }
      *(int **)(param_1 + 0x30) = piVar6;
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    }
    FUN_004b69d0();
    return 1;
  }
  return 0;
}


