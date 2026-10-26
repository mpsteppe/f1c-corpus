// Function: FUN_0049d3f0 @ 0049d3f0
// Size (bytes): 80


void __fastcall FUN_0049d3f0(int param_1)

{
  undefined4 uVar1;
  undefined1 local_10 [16];
  
  if (DAT_007d0474 == '\0') {
    uVar1 = FUN_0049b950();
  }
  else {
    uVar1 = FUN_0049b900();
  }
  FUN_0058815f(local_10,&DAT_005ccec8,uVar1);
  FUN_00553070(local_10,4,0x2b,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x54));
  return;
}


