// Function: FUN_004d12c0 @ 004d12c0
// Strings:  [PITORDER, False, ReversePitOrder]


void __fastcall FUN_004d12c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined1 local_110 [60];
  undefined4 auStack_d4 [53];
  
  iVar1 = FUN_00568210(s_PITORDER_005d3a28);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x1a8) = 0;
    iVar1 = FUN_005679c0(&DAT_005d3a34);
    while (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x1a8);
      uVar2 = FUN_00567970();
      auStack_d4[iVar1 + 1] = uVar2;
      *(int *)(param_1 + 0x1a8) = iVar1 + 1;
      iVar1 = FUN_0049adb0();
    }
    iVar1 = *(int *)(param_1 + 0x1a8);
    piVar3 = operator_new(iVar1 * 8 + 4);
    if (piVar3 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = piVar3 + 1;
      *piVar3 = iVar1;
      piVar3 = piVar4;
      if (-1 < iVar1 + -1) {
        do {
          *piVar3 = 0;
          piVar3[1] = -1;
          iVar1 = iVar1 + -1;
          piVar3 = piVar3 + 2;
        } while (iVar1 != 0);
      }
    }
    *(int **)(param_1 + 0x1ac) = piVar4;
    iVar1 = FUN_004c58a0(local_110,0x40,s_ReversePitOrder_005d3be0,0);
    if ((iVar1 == 0) && (iVar1 = FUN_00588410(local_110,s_False_005d3bd8), iVar1 != 0)) {
      iVar1 = *(int *)(param_1 + 0x1a8);
      iVar5 = 0;
      if (0 < iVar1) {
        do {
          FUN_00566650(auStack_d4[iVar1 - iVar5]);
          iVar1 = *(int *)(param_1 + 0x1a8);
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar1);
        return;
      }
    }
    else {
      iVar1 = 0;
      if (0 < *(int *)(param_1 + 0x1a8)) {
        do {
          FUN_00566650(auStack_d4[iVar1 + 1]);
          iVar1 = iVar1 + 1;
        } while (iVar1 < *(int *)(param_1 + 0x1a8));
      }
    }
  }
  return;
}


