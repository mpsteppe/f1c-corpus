// Function: FUN_005487e0 @ 005487e0
// Size (bytes): 39


undefined4 __fastcall FUN_005487e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x24);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = FUN_005469c0();
    if (iVar2 == -1) break;
    iVar1 = *(int *)(iVar1 + 0xc0);
  }
  return 0xffffffff;
}


