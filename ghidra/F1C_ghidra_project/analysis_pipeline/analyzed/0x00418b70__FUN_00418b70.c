// Function: FUN_00418b70 @ 00418b70
// Size (bytes): 27


undefined4 FUN_00418b70(int param_1)

{
  if (param_1 == -1) {
    return 0xffffffff;
  }
  return *(undefined4 *)(&DAT_005bf9a0 + param_1 * 0x14);
}


