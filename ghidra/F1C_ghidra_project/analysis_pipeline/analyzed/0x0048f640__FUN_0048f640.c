// Function: FUN_0048f640 @ 0048f640
// Size (bytes): 557


void __fastcall FUN_0048f640(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x5b] = 0;
  iVar5 = param_1[0x49] - param_1[0x48];
  piVar1 = (int *)param_1[0x3c];
  iVar4 = param_1[0x51] - param_1[0x50];
  param_1[0x3e] = (int)piVar1;
  if (piVar1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar1;
  }
  iVar2 = param_1[0x3f];
  if (iVar3 != 0) {
    while( true ) {
      if (param_1[0x58] < *(int *)(iVar3 + 0xc)) {
        param_1[0x58] = *(int *)(iVar3 + 0xc);
      }
      if (param_1[0x59] < *(int *)(iVar3 + 0x10)) {
        param_1[0x59] = *(int *)(iVar3 + 0x10);
      }
      if (param_1[0x3e] == 0) break;
      piVar1 = *(int **)(param_1[0x3e] + 4);
      param_1[0x3e] = (int)piVar1;
      if ((piVar1 == (int *)0x0) || (iVar3 = *piVar1, iVar3 == 0)) break;
    }
  }
  if (param_1[0x40] == 0) {
    if (param_1[0x59] != 0) {
      param_1[0x56] = iVar4 / (param_1[0x55] + param_1[0x59]);
    }
    if (param_1[0x57] != 0) {
      param_1[0x57] = iVar2 / param_1[0x57];
    }
    if ((param_1[0x56] != 0) && (0 < iVar2 % param_1[0x56])) {
      param_1[0x57] = param_1[0x57] + 1;
    }
    if (param_1[0x58] != 0) {
      param_1[0x5b] = param_1[0x57] - iVar5 / param_1[0x58];
    }
    if (param_1[0x5b] < 0) {
      param_1[0x5b] = 0;
    }
    goto LAB_0048f81b;
  }
  if (param_1[0x40] != 1) goto LAB_0048f81b;
  if (param_1[0x58] != 0) {
    param_1[0x57] = iVar5 / (param_1[0x54] + param_1[0x58]);
  }
  iVar3 = param_1[0x57];
  if ((iVar3 == 0) || (param_1[0x56] = iVar2 / iVar3, iVar3 == 0)) {
LAB_0048f75c:
    param_1[0x5b] = iVar2;
  }
  else {
    if (0 < iVar2 % iVar3) {
      param_1[0x56] = param_1[0x56] + 1;
    }
    if (iVar3 == 0) goto LAB_0048f75c;
    param_1[0x5b] = iVar2 / iVar3;
    if (0 < iVar2 % iVar3) {
      param_1[0x5b] = iVar2 / iVar3 + 1;
    }
  }
  iVar3 = param_1[0x55] + param_1[0x59];
  if (iVar3 != 0) {
    param_1[0x5b] = param_1[0x5b] - iVar4 / iVar3;
  }
  if (param_1[0x5b] < 0) {
    param_1[0x5b] = 0;
  }
  param_1[0x5b] = param_1[0x5b] * iVar3;
LAB_0048f81b:
  iVar3 = (param_1[0x54] + param_1[0x58]) * param_1[0x57];
  if ((iVar3 - iVar5 != 0 && iVar5 <= iVar3) ||
     (iVar5 = (param_1[0x55] + param_1[0x59]) * param_1[0x56], iVar5 - iVar4 != 0 && iVar4 <= iVar5)
     ) {
    param_1[0x41] = 0;
    (**(code **)(*param_1 + 0x40))(0);
  }
  FUN_0048f870();
  (**(code **)(*param_1 + 0x2c))(1);
  return;
}


