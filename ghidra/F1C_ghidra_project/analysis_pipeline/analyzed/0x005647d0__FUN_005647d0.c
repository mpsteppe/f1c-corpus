// Function: FUN_005647d0 @ 005647d0
// Size (bytes): 63


undefined4 __fastcall FUN_005647d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  (**(code **)(param_1 + 0xc))();
  iVar1 = FUN_00564a20(*(undefined4 *)(param_1 + 0x10),0,0);
  if (iVar1 == -1) {
    return 0;
  }
  uVar2 = FUN_005648b0();
  return uVar2;
}


