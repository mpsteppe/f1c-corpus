// Function: FUN_0058c1b1 @ 0058c1b1
// Size (bytes): 47


void FUN_0058c1b1(uint param_1)

{
  if ((0x5e6747 < param_1) && (param_1 < 0x5e69a9)) {
    FUN_0058dfea(((int)(param_1 - 0x5e6748) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x20));
  return;
}


