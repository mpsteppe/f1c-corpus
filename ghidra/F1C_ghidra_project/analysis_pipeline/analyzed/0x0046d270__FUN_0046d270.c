// Function: FUN_0046d270 @ 0046d270
// Size (bytes): 94


undefined4 __fastcall FUN_0046d270(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_005eb10c != (int *)0x0) {
    (**(code **)(*DAT_005eb10c + 0xc))();
  }
  FUN_004186a0();
  iVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))(0x27);
  iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))(0x29);
  if (iVar1 != 0) {
    FUN_0047c360(1);
  }
  if (iVar2 != 0) {
    FUN_0047c360(0);
  }
  FUN_0041c540();
  return 0;
}


