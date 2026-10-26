// Function: FUN_00491ad0 @ 00491ad0
// Size (bytes): 246


void __fastcall FUN_00491ad0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_8;
  
  FUN_004910d0(*param_1 + 0x1c);
  iVar1 = *(int *)(*param_1 + 4);
  local_8 = 0;
  do {
    if (local_8 == 1) {
      piVar5 = (int *)(*param_1 + 0x2c);
    }
    else {
      piVar5 = (int *)(iVar1 * 0x10 + *(int *)(*param_1 + 8));
    }
    piVar4 = (int *)*piVar5;
    piVar5[2] = (int)piVar4;
    if ((piVar4 != (int *)0x0) && (iVar2 = *piVar4, iVar2 != 0)) {
      while( true ) {
        iVar3 = FUN_00490940((int)*(short *)(iVar2 + 4),(int)*(short *)(iVar2 + 6));
        iVar2 = *param_1;
        if (iVar3 != 0) {
          piVar4 = operator_new(0xc);
          if (piVar4 == (int *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            *piVar4 = iVar3;
            piVar4[1] = 0;
            *(undefined1 *)(piVar4 + 2) = 0;
          }
          if (*(int *)(iVar2 + 0x1c) == 0) {
            *(int *)(iVar2 + 0x1c) = (int)piVar4;
            *(int **)(iVar2 + 0x24) = piVar4;
          }
          else {
            *(int **)(*(int *)(iVar2 + 0x20) + 4) = piVar4;
          }
          *(int **)(iVar2 + 0x20) = piVar4;
          *(int *)(iVar2 + 0x28) = *(int *)(iVar2 + 0x28) + 1;
        }
        if (piVar5[2] == 0) break;
        piVar4 = *(int **)(piVar5[2] + 4);
        piVar5[2] = (int)piVar4;
        if ((piVar4 == (int *)0x0) || (iVar2 = *piVar4, iVar2 == 0)) break;
      }
    }
    local_8 = local_8 + 1;
    if (1 < local_8) {
      FUN_00490d00(*param_1 + 0x1c,*param_1 + 0xc);
      return;
    }
  } while( true );
}


