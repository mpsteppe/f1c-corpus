// Function: FUN_00499910 @ 00499910
// Size (bytes): 206


void __fastcall FUN_00499910(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  if ((char)param_1[1] != '\0') {
    param_1[2] = 0;
    return;
  }
  do {
    if (param_1[2] == 0) {
      iVar3 = *param_1;
      if (iVar3 == 0) {
        *param_1 = 1;
        piVar1 = *(int **)(param_1[3] + 4);
        *(int **)(param_1[3] + 0xc) = piVar1;
        if (piVar1 == (int *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *piVar1;
        }
        param_1[4] = iVar3;
        if (iVar3 == 0) {
LAB_004999cf:
          *(undefined1 *)(param_1 + 1) = 1;
          return;
        }
        iVar3 = *(int *)(iVar3 + 0x4c);
        param_1[5] = 0;
LAB_004999b8:
        param_1[2] = iVar3;
      }
      else if (iVar3 == 1) {
        *param_1 = 2;
        iVar3 = *(int *)(param_1[4] + 0x48);
        param_1[5] = iVar3;
        if (iVar3 != 0) {
          param_1[2] = *(int *)(iVar3 + 0x44);
        }
      }
      else if (iVar3 == 2) {
        cVar2 = FUN_004998c0();
        if (cVar2 == '\0') {
          cVar2 = FUN_00499870();
          if (cVar2 == '\0') goto LAB_004999cf;
          *param_1 = 1;
          iVar3 = *(int *)(param_1[4] + 0x4c);
          goto LAB_004999b8;
        }
        param_1[2] = *(int *)(param_1[5] + 0x44);
      }
    }
    else {
      param_1[2] = *(int *)(param_1[2] + 0x8c);
    }
    if ((char)param_1[1] != '\0') {
      return;
    }
    if (param_1[2] != 0) {
      return;
    }
  } while( true );
}


