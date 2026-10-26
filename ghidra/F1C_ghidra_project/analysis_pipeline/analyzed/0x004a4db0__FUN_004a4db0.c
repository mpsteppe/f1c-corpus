// Function: FUN_004a4db0 @ 004a4db0
// Size (bytes): 273


void __fastcall FUN_004a4db0(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x35) = 1;
  *(undefined1 *)(param_1 + 0x75) = 1;
  *(undefined1 *)(param_1 + 0xb5) = 1;
  *(undefined1 *)(param_1 + 0xf5) = 1;
  *(undefined1 *)(param_1 + 0x135) = 1;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x184) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  *(undefined4 *)(param_1 + 0x18c) = 0;
  *(undefined1 *)(param_1 + 400) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x160) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x194) = 0;
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  *(undefined1 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_004a29a0();
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0xc));
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_004a29a0();
    if (*(int *)(param_1 + 0x10) != 0) {
      FUN_00587bcf(*(int *)(param_1 + 0x10));
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_004a3b30();
    iVar1 = *(int *)(param_1 + 0x14);
    if (iVar1 != 0) {
      FUN_004a2220();
      FUN_00587bcf(iVar1);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}


