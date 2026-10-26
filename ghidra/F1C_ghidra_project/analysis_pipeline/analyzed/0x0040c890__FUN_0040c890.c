// Function: FUN_0040c890 @ 0040c890
// Size (bytes): 54


int __thiscall FUN_0040c890(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x1c))(param_2);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x1c))(param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 0x1c))(param_2);
      }
    }
  }
  return iVar1;
}


