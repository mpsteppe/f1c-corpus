// Function: FUN_004c2780 @ 004c2780
// Size (bytes): 131


uint __fastcall FUN_004c2780(int *param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  
  iVar1 = FUN_004c2760();
  if (iVar1 == 2) {
    FUN_004c1820();
  }
  pvVar2 = operator_new(0xb154);
  if (pvVar2 == (void *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004c0ab0();
  }
  piVar3 = (int *)FUN_004c0db0();
  if (iVar1 != 0) {
    piVar3 = operator_new(0xc);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      *piVar3 = iVar1;
      piVar3[1] = 0;
      *(undefined1 *)(piVar3 + 2) = 1;
    }
    if (*param_1 == 0) {
      *param_1 = (int)piVar3;
      param_1[2] = (int)piVar3;
      param_1[1] = (int)piVar3;
      param_1[3] = param_1[3] + 1;
      return (uint)piVar3 & 0xffffff00;
    }
    *(int **)(param_1[1] + 4) = piVar3;
    param_1[1] = (int)piVar3;
    param_1[3] = param_1[3] + 1;
  }
  return (uint)piVar3 & 0xffffff00;
}


