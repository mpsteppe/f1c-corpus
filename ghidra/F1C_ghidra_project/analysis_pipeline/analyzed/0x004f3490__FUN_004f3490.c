// Function: FUN_004f3490 @ 004f3490
// Size (bytes): 68


void __thiscall FUN_004f3490(int param_1,undefined4 param_2,undefined4 param_3)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  int iVar4;
  
  pdVar1 = (double *)(param_1 + 0xa0);
  pdVar2 = (double *)(param_1 + 0x98);
  pdVar3 = (double *)(param_1 + 0x90);
  iVar4 = FUN_00565aa0(param_3,pdVar3,pdVar2,pdVar1,0);
  if (iVar4 != 0) {
    *pdVar3 = ABS(*pdVar3);
    *pdVar2 = ABS(*pdVar2);
    *pdVar1 = ABS(*pdVar1);
  }
  return;
}


