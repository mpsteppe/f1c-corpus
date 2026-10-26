// Function: FUN_004e3a50 @ 004e3a50
// Size (bytes): 66


void __thiscall FUN_004e3a50(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xba8)) {
    do {
      FUN_004df110(param_2,0xffffffff);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0xba8));
  }
  return;
}


