// Function: FUN_004647d0 @ 004647d0
// Size (bytes): 335


int * FUN_004647d0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  
  iVar1 = 0;
  piVar3 = param_1;
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  do {
    piVar3 = (int *)piVar3[1];
    iVar1 = iVar1 + 1;
  } while (piVar3 != (int *)0x0);
  if (iVar1 < 2) {
    return param_1;
  }
  iVar1 = iVar1 / 2 + -1;
  piVar3 = param_1;
  if (0 < iVar1) {
    do {
      iVar1 = iVar1 + -1;
      piVar3 = (int *)piVar3[1];
    } while (iVar1 != 0);
  }
  iVar1 = piVar3[1];
  piVar3[1] = 0;
  piVar2 = (int *)FUN_004647d0(param_1);
  piVar3 = (int *)FUN_004647d0(iVar1);
  if (piVar2 == (int *)0x0) {
    return piVar3;
  }
  if (piVar3 == (int *)0x0) {
    return piVar2;
  }
  iVar1 = ((int *)*piVar2)[2];
  piVar4 = (int *)*piVar3;
  if (iVar1 == -1) {
    if (piVar4[2] == -1) {
      iVar1 = *(int *)*piVar2;
      iVar7 = *piVar4;
LAB_00464863:
      if (iVar1 < iVar7) goto LAB_0046486c;
    }
    else if (piVar4[2] == -1) goto LAB_00464860;
    piVar4 = (int *)piVar3[1];
    piVar6 = piVar2;
    piVar2 = piVar3;
  }
  else {
    if (piVar4[2] != -1) {
LAB_00464860:
      iVar7 = piVar4[2];
      goto LAB_00464863;
    }
LAB_0046486c:
    piVar4 = piVar3;
    piVar3 = piVar2;
    piVar6 = (int *)piVar2[1];
  }
  do {
    piVar5 = piVar4;
    if (piVar6 == (int *)0x0) {
      if (piVar5 != (int *)0x0) {
        piVar3[1] = (int)piVar5;
        return piVar2;
      }
LAB_004648f5:
      piVar3[1] = 0;
      return piVar2;
    }
    if (piVar5 == (int *)0x0) {
      if (piVar6 != (int *)0x0) {
        piVar3[1] = (int)piVar6;
        return piVar2;
      }
      goto LAB_004648f5;
    }
    iVar1 = ((int *)*piVar6)[2];
    piVar4 = (int *)*piVar5;
    if (iVar1 == -1) {
      if (piVar4[2] == -1) {
        iVar1 = *(int *)*piVar6;
        iVar7 = *piVar4;
LAB_004648b3:
        if (iVar1 < iVar7) goto LAB_004648bc;
      }
      else if (piVar4[2] == -1) goto LAB_004648b0;
      piVar4 = (int *)piVar5[1];
    }
    else {
      if (piVar4[2] != -1) {
LAB_004648b0:
        iVar7 = piVar4[2];
        goto LAB_004648b3;
      }
LAB_004648bc:
      piVar4 = piVar5;
      piVar5 = piVar6;
      piVar6 = (int *)piVar6[1];
    }
    piVar3[1] = (int)piVar5;
    piVar3 = piVar5;
  } while( true );
}


