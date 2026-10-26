// Function: FUN_00582310 @ 00582310
// Size (bytes): 33


void __fastcall FUN_00582310(int param_1)

{
  BOOL BVar1;
  
  if (*(char *)(param_1 + 0x18) != '\0') {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x10));
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
  }
  return;
}


