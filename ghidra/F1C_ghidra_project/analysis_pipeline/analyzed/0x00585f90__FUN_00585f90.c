// Function: FUN_00585f90 @ 00585f90
// Size (bytes): 27


bool __fastcall FUN_00585f90(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(HANDLE *)(param_1 + 0x50) != (HANDLE)0x0) {
    iVar1 = ReleaseMutex(*(HANDLE *)(param_1 + 0x50));
  }
  return iVar1 == 1;
}


