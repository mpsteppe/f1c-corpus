// Function: FUN_0057fb90 @ 0057fb90
// Size (bytes): 73


undefined1 __fastcall FUN_0057fb90(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0xa74) == '\0') {
    iVar1 = WSAStartup(0x202,(LPWSADATA)(param_1 + 0x778));
    if (iVar1 == 0) {
      *(undefined1 *)(param_1 + 0xa74) = 1;
      return *(undefined1 *)(param_1 + 0xa74);
    }
    *(undefined1 *)(param_1 + 0xa74) = 0;
    FUN_0057d400();
  }
  return *(undefined1 *)(param_1 + 0xa74);
}


