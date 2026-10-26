// Function: FUN_0045d490 @ 0045d490
// Size (bytes): 45


void __fastcall FUN_0045d490(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_00461dc0();
  if (cVar1 != '\0') {
    FUN_0045cd70();
    if (DAT_007d0f94 != '\0') {
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}


