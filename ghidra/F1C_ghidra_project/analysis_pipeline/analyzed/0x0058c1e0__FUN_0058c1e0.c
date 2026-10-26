// Function: FUN_0058c1e0 @ 0058c1e0
// Size (bytes): 35


void FUN_0058c1e0(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_0058dfea(param_1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


