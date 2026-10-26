// Function: FUN_0040d410 @ 0040d410
// Size (bytes): 50


void __fastcall FUN_0040d410(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0040cd60();
  if ((6 < iVar1) && (iVar1 < 0xb)) {
    FUN_0040cde0(*(undefined4 *)(param_1 + 0x10),0);
  }
  FUN_00408450(0x3f000000);
  *(undefined1 *)(param_1 + 0x24) = 0;
  return;
}


