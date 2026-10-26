// Function: FUN_004582a0 @ 004582a0
// Size (bytes): 27


int __thiscall FUN_004582a0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((-1 < param_2) && (param_2 < param_1[1])) {
    iVar1 = param_2 * 0x1c + *param_1;
  }
  return iVar1;
}


