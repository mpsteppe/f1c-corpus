// Function: FUN_005861e0 @ 005861e0
// Size (bytes): 33


void __fastcall FUN_005861e0(int param_1)

{
  BOOL BVar1;
  
  if (*(char *)(param_1 + 0x5c) != '\0') {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x54));
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
  }
  return;
}


