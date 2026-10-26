// Function: thunk_FUN_00495b30 @ 004979b0
// Size (bytes): 5


void __fastcall thunk_FUN_00495b30(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  while ((iVar1 != 0 && (iVar1 = FUN_00498f70(), iVar1 == 1))) {
    FUN_00495ae0();
    iVar1 = *(int *)(param_1 + 0x18);
  }
  return;
}


