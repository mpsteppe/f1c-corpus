// Function: FUN_00495b30 @ 00495b30
// Size (bytes): 42


void __fastcall FUN_00495b30(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  while ((iVar1 != 0 && (iVar1 = FUN_00498f70(), iVar1 == 1))) {
    FUN_00495ae0();
    iVar1 = *(int *)(param_1 + 0x18);
  }
  return;
}


