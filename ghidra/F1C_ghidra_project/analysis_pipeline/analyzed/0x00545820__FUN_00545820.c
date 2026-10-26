// Function: FUN_00545820 @ 00545820
// Size (bytes): 46


int __thiscall FUN_00545820(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 300) <= param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x130);
    if (0 < param_2) {
      do {
        param_2 = param_2 + -1;
        iVar1 = *(int *)(iVar1 + 0x6c);
      } while (param_2 != 0);
      return iVar1;
    }
  }
  return iVar1;
}


