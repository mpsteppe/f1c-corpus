// Function: FUN_0047bae0 @ 0047bae0
// Size (bytes): 91


void __thiscall FUN_0047bae0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 1) {
    param_2 = *(int *)(param_1 + 0xec) + param_2;
    *(int *)(param_1 + 0xec) = param_2;
    if (param_2 < 0) {
      *(undefined4 *)(param_1 + 0xec) = 0;
      FUN_0047bd90();
      return;
    }
  }
  else {
    *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + param_2;
    iVar1 = FUN_0047bc90();
    if (iVar1 + -1 < *(int *)(param_1 + 0xec)) {
      *(int *)(param_1 + 0xec) = iVar1 + -1;
    }
  }
  FUN_0047bd90();
  return;
}


