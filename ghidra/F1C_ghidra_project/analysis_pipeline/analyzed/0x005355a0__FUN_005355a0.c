// Function: FUN_005355a0 @ 005355a0
// Size (bytes): 74


undefined4 __fastcall FUN_005355a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return 0xfffffffe;
  }
  if (*(char *)(param_1 + 0x5c) == 'w') {
    iVar1 = FUN_005352d0();
    if (iVar1 != 0) {
      uVar2 = FUN_00534ee0();
      return uVar2;
    }
    FUN_005355f0();
    FUN_005355f0();
  }
  uVar2 = FUN_00534ee0();
  return uVar2;
}


