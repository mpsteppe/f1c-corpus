// Function: FUN_00516853 @ 00516853
// Size (bytes): 48


void FUN_00516853(int param_1)

{
  int iVar1;
  
  iVar1 = 1;
  do {
    FUN_00516772(param_1,iVar1);
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  FUN_00519351(param_1,*(undefined4 *)(param_1 + 4),0x50);
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_00587b96(param_1);
  return;
}


