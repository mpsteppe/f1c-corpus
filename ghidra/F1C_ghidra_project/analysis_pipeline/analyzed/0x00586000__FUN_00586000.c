// Function: FUN_00586000 @ 00586000
// Size (bytes): 98


uint __thiscall FUN_00586000(int *param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  uint in_EAX;
  uint uVar2;
  int *piVar3;
  
  uVar2 = in_EAX & 0xffffff00;
  if (param_2 != 0) {
    piVar3 = operator_new(0xc);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      *piVar3 = param_2;
      piVar3[1] = 0;
      *(undefined1 *)(piVar3 + 2) = param_3;
    }
    if (*param_1 == 0) {
      *param_1 = (int)piVar3;
      param_1[2] = (int)piVar3;
      param_1[1] = (int)piVar3;
      iVar1 = param_1[3];
      param_1[3] = iVar1 + 1;
      return CONCAT31((int3)((uint)(iVar1 + 1) >> 8),1);
    }
    *(int **)(param_1[1] + 4) = piVar3;
    param_1[1] = (int)piVar3;
    iVar1 = param_1[3];
    param_1[3] = iVar1 + 1;
    uVar2 = CONCAT31((int3)((uint)(iVar1 + 1) >> 8),1);
  }
  return uVar2;
}


