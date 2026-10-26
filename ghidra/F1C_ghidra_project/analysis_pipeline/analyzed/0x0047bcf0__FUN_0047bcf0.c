// Function: FUN_0047bcf0 @ 0047bcf0
// Size (bytes): 159


void __fastcall FUN_0047bcf0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0047bc30();
  iVar2 = FUN_0047bc90();
  iVar3 = *(int *)(param_1 + 0xec);
  if (iVar1 < iVar3) {
    if (iVar3 + -1 <= iVar1) {
      *(int *)(param_1 + 0xec) = iVar3 + -1;
      goto LAB_0047bd5a;
    }
    iVar4 = iVar3 - iVar1;
    if (iVar3 - iVar1 < *(int *)(param_1 + 0xf0)) {
      iVar4 = *(int *)(param_1 + 0xf0);
    }
    iVar3 = iVar3 - iVar4;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xf0);
    iVar4 = iVar5 + iVar3;
    if (iVar1 < iVar4) goto LAB_0047bd5a;
    if (iVar4 < iVar1) {
      iVar1 = iVar1 - (iVar4 + -1);
      if (iVar5 <= iVar1) {
        iVar5 = iVar1;
      }
      iVar3 = iVar3 + iVar5;
    }
    else {
      iVar3 = iVar3 + 1;
    }
  }
  *(int *)(param_1 + 0xec) = iVar3;
LAB_0047bd5a:
  if (*(int *)(param_1 + 0xec) < 0) {
    *(undefined4 *)(param_1 + 0xec) = 0;
    FUN_0047bd90();
    return;
  }
  if (iVar2 + -1 < *(int *)(param_1 + 0xec)) {
    *(int *)(param_1 + 0xec) = iVar2 + -1;
  }
  FUN_0047bd90();
  return;
}


