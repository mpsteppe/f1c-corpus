// Function: FUN_00593dd3 @ 00593dd3
// Size (bytes): 72


undefined4 FUN_00593dd3(undefined4 param_1)

{
  DAT_008d48fc = HeapAlloc(DAT_008d4904,0,0x140);
  if (DAT_008d48fc == (LPVOID)0x0) {
    return 0;
  }
  DAT_008d48f4 = 0;
  DAT_008d48f8 = 0;
  DAT_008d48f0 = DAT_008d48fc;
  DAT_008d4900 = param_1;
  DAT_008d48e8 = 0x10;
  return 1;
}


