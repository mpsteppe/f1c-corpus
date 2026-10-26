// Function: FUN_005487a0 @ 005487a0
// Size (bytes): 64


undefined4 __fastcall FUN_005487a0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x24);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = FUN_00546450(0xffffffff);
    if (iVar2 != 0) break;
    InterlockedDecrement(&DAT_008b8eec);
    FUN_00545f50(0);
    iVar1 = *(int *)(iVar1 + 0xc0);
  }
  return 0xffffffff;
}


