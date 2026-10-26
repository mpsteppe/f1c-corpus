// Function: FUN_0054c230 @ 0054c230
// Size (bytes): 33


int __thiscall FUN_0054c230(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x204);
  iVar2 = 0;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar2 == param_2) break;
    iVar1 = *(int *)(iVar1 + 0x10);
    iVar2 = iVar2 + 1;
  }
  return iVar1;
}


