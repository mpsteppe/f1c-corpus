// Function: FUN_00464f50 @ 00464f50
// Size (bytes): 55


int FUN_00464f50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int iVar4;
  
  iVar2 = FUN_00464ee0();
  iVar4 = 1;
  if (1 < *(int *)(extraout_ECX + 0xe40c)) {
    iVar4 = *(int *)(extraout_ECX + 0xe40c) + -1;
  }
  iVar1 = *(int *)(param_1 * 0x230 + 0x2ac + extraout_ECX);
  iVar3 = iVar2 / iVar4;
  if (iVar1 <= iVar2 / iVar4) {
    iVar3 = iVar1;
  }
  return iVar3;
}


