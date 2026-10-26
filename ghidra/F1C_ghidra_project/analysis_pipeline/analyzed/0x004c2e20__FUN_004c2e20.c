// Function: FUN_004c2e20 @ 004c2e20
// Size (bytes): 241


int * FUN_004c2e20(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  iVar2 = 0;
  piVar4 = param_1;
  if (param_1 != (int *)0x0) {
    do {
      piVar4 = (int *)piVar4[1];
      iVar2 = iVar2 + 1;
    } while (piVar4 != (int *)0x0);
    if (1 < iVar2) {
      iVar2 = iVar2 / 2 + -1;
      piVar4 = param_1;
      if (0 < iVar2) {
        do {
          iVar2 = iVar2 + -1;
          piVar4 = (int *)piVar4[1];
        } while (iVar2 != 0);
      }
      iVar2 = piVar4[1];
      piVar4[1] = 0;
      piVar3 = (int *)FUN_004c2e20(param_1);
      piVar4 = (int *)FUN_004c2e20(iVar2);
      param_1 = piVar4;
      if ((piVar3 != (int *)0x0) && (param_1 = piVar3, piVar4 != (int *)0x0)) {
        if (*(float *)(*piVar4 + 4) <= *(float *)(*piVar3 + 4)) {
          piVar1 = (int *)piVar4[1];
          piVar7 = piVar3;
          piVar3 = piVar4;
        }
        else {
          piVar1 = piVar4;
          piVar7 = (int *)piVar3[1];
          piVar4 = piVar3;
        }
        do {
          if (piVar7 == (int *)0x0) {
            if (piVar1 != (int *)0x0) {
              piVar4[1] = (int)piVar1;
              return piVar3;
            }
LAB_004c2ef8:
            piVar4[1] = 0;
            return piVar3;
          }
          if (piVar1 == (int *)0x0) {
            if (piVar7 != (int *)0x0) {
              piVar4[1] = (int)piVar7;
              return piVar3;
            }
            goto LAB_004c2ef8;
          }
          if (*(float *)(*piVar1 + 4) <= *(float *)(*piVar7 + 4)) {
            piVar6 = (int *)piVar1[1];
            piVar5 = piVar1;
          }
          else {
            piVar5 = piVar7;
            piVar6 = piVar1;
            piVar7 = (int *)piVar7[1];
          }
          piVar4[1] = (int)piVar5;
          piVar1 = piVar6;
          piVar4 = piVar5;
        } while( true );
      }
    }
  }
  return param_1;
}


