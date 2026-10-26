// Function: FUN_0052e320 @ 0052e320
// Size (bytes): 43


undefined4 __fastcall FUN_0052e320(int param_1)

{
  if (*(char *)(param_1 + 0x24ec) != '\0') {
    *(undefined4 *)(param_1 + 0x24f0) = 0;
    *(undefined1 *)(param_1 + 0x24ec) = 0;
    FUN_0047abb0();
    FUN_004b0170();
  }
  return 0;
}


