// Function: FUN_00584f90 @ 00584f90
// Size (bytes): 82


float10 __fastcall FUN_00584f90(int param_1)

{
  float10 fVar1;
  
  if (*(HANDLE *)(param_1 + 0xd4) != (HANDLE)0x0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0xd4),*(DWORD *)(param_1 + 0xd8));
  }
  fVar1 = (float10)FUN_00583680();
  if (*(HANDLE *)(param_1 + 0xd4) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xd4));
    fVar1 = (float10)(double)fVar1;
  }
  return fVar1;
}


