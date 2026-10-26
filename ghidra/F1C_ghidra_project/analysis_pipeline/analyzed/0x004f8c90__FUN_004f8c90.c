// Function: FUN_004f8c90 @ 004f8c90
// Size (bytes): 46


undefined4 FUN_004f8c90(void)

{
  if (DAT_008afc78 != (HMODULE)0x0) {
    (*DAT_008afc80)();
    FreeLibrary(DAT_008afc78);
    DAT_008afc78 = (HMODULE)0x0;
    return 0;
  }
  return 3;
}


