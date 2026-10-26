// Function: FUN_004c6e80 @ 004c6e80
// Size (bytes): 137


void __fastcall FUN_004c6e80(int param_1)

{
  int iVar1;
  
  FUN_00410b40(param_1 + 0xc);
  FUN_004e4790();
  FUN_004e09e0();
  FUN_004a4db0();
  FUN_004f83b0();
  FUN_004bb950();
  iVar1 = 0;
  if (0 < DAT_005c329c) {
    do {
      FUN_0042ae20(param_1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_005c329c);
  }
  *(undefined4 *)(param_1 + 0x48a4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x48a8) = 0xffffffff;
  FUN_004c79e0();
  FUN_004d1670();
  return;
}


