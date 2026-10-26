// Function: FUN_00586210 @ 00586210
// Size (bytes): 39


void __fastcall FUN_00586210(int param_1)

{
  BOOL BVar1;
  
  if (*(char *)(param_1 + 0x24) != '\0') {
    BVar1 = CloseHandle(*(HANDLE *)(param_1 + 0x1c));
    if (BVar1 != 0) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  FUN_005870d0();
  return;
}


