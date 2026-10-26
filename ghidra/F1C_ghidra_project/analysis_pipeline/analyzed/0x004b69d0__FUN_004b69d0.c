// Function: FUN_004b69d0 @ 004b69d0
// Size (bytes): 29


int __fastcall FUN_004b69d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x9bc);
  if (iVar2 != *(int *)(param_1 + 0x9b8)) {
    iVar1 = iVar2 + 1;
    iVar2 = iVar1 / *(int *)(param_1 + 0x9b4);
    *(int *)(param_1 + 0x9bc) = iVar1 % *(int *)(param_1 + 0x9b4);
  }
  return iVar2;
}


