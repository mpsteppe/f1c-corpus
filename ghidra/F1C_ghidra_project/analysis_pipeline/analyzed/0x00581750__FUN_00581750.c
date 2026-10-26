// Function: FUN_00581750 @ 00581750
// Size (bytes): 33


void __fastcall FUN_00581750(int param_1)

{
  BOOL BVar1;
  
  if (*(char *)(param_1 + 0xc) != '\0') {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 4));
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 4) = 0;
    }
  }
  return;
}


