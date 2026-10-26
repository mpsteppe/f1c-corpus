// Function: FUN_00564780 @ 00564780
// Size (bytes): 72


void __fastcall FUN_00564780(int param_1)

{
  int iVar1;
  
  (**(code **)(param_1 + 0xc))();
  iVar1 = FUN_00564a20(*(undefined4 *)(param_1 + 0x10),0,0);
  if (iVar1 == -1) {
    FUN_005648c0();
    return;
  }
  FUN_005649d0(iVar1);
  return;
}


