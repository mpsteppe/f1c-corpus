// Function: FUN_00585f30 @ 00585f30
// Size (bytes): 39


void __fastcall FUN_00585f30(int param_1)

{
  BOOL BVar1;
  
  if (*(char *)(param_1 + 0x58) != '\0') {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x50));
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 0x50) = 0;
    }
  }
  FUN_00583650();
  return;
}


