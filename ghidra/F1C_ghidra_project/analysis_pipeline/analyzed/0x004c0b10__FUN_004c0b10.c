// Function: FUN_004c0b10 @ 004c0b10
// Size (bytes): 83


void __fastcall FUN_004c0b10(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xb128) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0xb128));
  }
  if (*(int *)(param_1 + 0xb120) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0xb120));
  }
  FUN_0049a270();
  iVar1 = 0x67;
  do {
    FUN_0049a270();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


