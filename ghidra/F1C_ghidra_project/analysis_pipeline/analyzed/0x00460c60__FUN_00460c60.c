// Function: FUN_00460c60 @ 00460c60
// Size (bytes): 75


void __fastcall FUN_00460c60(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x3e18);
  iVar1 = 0x68;
  do {
    *puVar2 = 0xffffffff;
    FUN_00461480();
    thunk_FUN_00500170();
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


