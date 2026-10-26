// Function: FUN_00489450 @ 00489450
// Size (bytes): 38


int __fastcall FUN_00489450(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x168);
  iVar1 = 0;
  if (-1 < iVar2) {
    iVar1 = *(int *)(param_1 + 0x90);
    for (; (iVar1 != 0 && (0 < iVar2)); iVar2 = iVar2 + -1) {
      iVar1 = *(int *)(iVar1 + 0x8c);
    }
  }
  return iVar1;
}


