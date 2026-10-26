// Function: FUN_00494de0 @ 00494de0
// Size (bytes): 120


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00494de0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = FUN_0053cfe0(&param_1,param_1,0x10801);
  iVar1 = param_1;
  if ((iVar4 == 0) && (param_1 != 0)) {
    piVar5 = operator_new(0xc);
    if (piVar5 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      *piVar5 = iVar1;
      piVar5[1] = 0;
      *(undefined1 *)(piVar5 + 2) = 0;
    }
    piVar2 = piVar5;
    piVar3 = piVar5;
    if (DAT_007cddf0 != (int *)0x0) {
      DAT_007cddf4[1] = (int)piVar5;
      piVar2 = DAT_007cddf0;
      piVar3 = DAT_007cddf8;
    }
    DAT_007cddf8 = piVar3;
    DAT_007cddf0 = piVar2;
    _DAT_007cddfc = _DAT_007cddfc + 1;
    DAT_007cddf4 = piVar5;
  }
  return iVar4;
}


