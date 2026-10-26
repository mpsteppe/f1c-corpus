// Function: FUN_0057fbe0 @ 0057fbe0
// Size (bytes): 157


undefined4 __fastcall FUN_0057fbe0(int *param_1)

{
  if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
    WaitForSingleObject((HANDLE)param_1[0x2b6],param_1[0x2b7]);
  }
  if ((HANDLE)param_1[0x2b6] != (HANDLE)0x0) {
    ReleaseMutex((HANDLE)param_1[0x2b6]);
  }
  if ((HANDLE)param_1[0x2bd] != (HANDLE)0x0) {
    WaitForSingleObject((HANDLE)param_1[0x2bd],param_1[0x2be]);
  }
  if ((HANDLE)param_1[0x2bd] != (HANDLE)0x0) {
    ReleaseMutex((HANDLE)param_1[0x2bd]);
  }
  FUN_0057e570();
  FUN_0057e6e0();
  (**(code **)(*param_1 + 0x30))();
  FUN_0057e760();
  FUN_0057e7e0();
  if ((char)param_1[0x29d] != '\0') {
    WSACleanup();
    *(undefined1 *)(param_1 + 0x29d) = 0;
    return 1;
  }
  return 0;
}


