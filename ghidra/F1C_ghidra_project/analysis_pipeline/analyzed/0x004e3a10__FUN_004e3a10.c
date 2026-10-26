// Function: FUN_004e3a10 @ 004e3a10
// Size (bytes): 64


void __thiscall FUN_004e3a10(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0xba8)) {
    do {
      FUN_004df0a0(param_2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0xba8));
  }
  return;
}


