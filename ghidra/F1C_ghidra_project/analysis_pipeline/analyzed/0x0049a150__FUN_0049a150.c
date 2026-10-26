// Function: FUN_0049a150 @ 0049a150
// Size (bytes): 34


int __thiscall FUN_0049a150(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 0xc) < param_2) {
    return 0;
  }
  if (0 < param_2) {
    do {
      if (iVar1 != 0) {
        iVar1 = *(int *)(iVar1 + 0x24);
      }
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return iVar1;
}


