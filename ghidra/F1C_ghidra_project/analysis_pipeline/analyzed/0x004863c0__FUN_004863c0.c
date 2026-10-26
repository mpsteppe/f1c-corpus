// Function: FUN_004863c0 @ 004863c0
// Size (bytes): 50


int __thiscall FUN_004863c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((-1 < param_2) && (iVar1 = *(int *)(param_1 + 0x90), iVar1 != 0)) {
    for (; (iVar2 = iVar1, 0 < param_2 && (iVar2 = 0, iVar1 != 0)); iVar1 = *(int *)(iVar1 + 0x8c))
    {
      param_2 = param_2 + -1;
    }
  }
  return iVar2;
}


