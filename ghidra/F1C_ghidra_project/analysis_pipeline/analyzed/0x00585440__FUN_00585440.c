// Function: FUN_00585440 @ 00585440
// Size (bytes): 42


void __thiscall FUN_00585440(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00587890();
  if (iVar1 < param_2) {
    *(int *)(param_1 + 0x80) = iVar1;
    return;
  }
  *(int *)(param_1 + 0x80) = param_2;
  return;
}


