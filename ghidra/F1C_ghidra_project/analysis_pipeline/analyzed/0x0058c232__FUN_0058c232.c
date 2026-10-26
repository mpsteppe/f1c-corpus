// Function: FUN_0058c232 @ 0058c232
// Size (bytes): 35


void FUN_0058c232(int param_1,int param_2)

{
  if (param_1 < 0x14) {
    FUN_0058e04b(param_1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x20));
  return;
}


