// Function: FUN_0054e100 @ 0054e100
// Size (bytes): 30


int __fastcall FUN_0054e100(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x118);
  iVar1 = 0;
  if (0 < iVar3) {
    piVar2 = (int *)(*(int *)(param_1 + 0x11c) + 8);
    do {
      iVar1 = iVar1 + *piVar2;
      piVar2 = piVar2 + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar1;
}


