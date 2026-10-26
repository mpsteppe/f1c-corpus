// Function: FUN_00583aa0 @ 00583aa0
// Size (bytes): 61


void __fastcall FUN_00583aa0(int param_1)

{
  BOOL BVar1;
  
  if (*(char *)(param_1 + 0x24) != '\0') {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x1c));
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  if (*(char *)(param_1 + 0x14) != '\0') {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0xc));
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  return;
}


