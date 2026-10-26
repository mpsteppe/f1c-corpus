// Function: FUN_00564c40 @ 00564c40
// Size (bytes): 42


byte __fastcall FUN_00564c40(byte param_1)

{
  if (param_1 < 0x1a) {
    return param_1 + 0x41;
  }
  if (param_1 < 0x34) {
    return param_1 + 0x47;
  }
  if (param_1 < 0x3e) {
    return param_1 - 4;
  }
  if (param_1 == 0x3e) {
    return 0x2b;
  }
  return (param_1 != 0x3f) - 1U & 0x2f;
}


