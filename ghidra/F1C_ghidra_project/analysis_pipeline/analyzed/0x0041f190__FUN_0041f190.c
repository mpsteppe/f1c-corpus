// Function: FUN_0041f190 @ 0041f190
// Size (bytes): 66


undefined4 __fastcall FUN_0041f190(int param_1)

{
  char cVar1;
  int iVar2;
  
  FUN_004c2850();
  iVar2 = FUN_004c11d0();
  cVar1 = FUN_0041f1e0();
  if ((cVar1 != '\0') &&
     ((iVar2 == 2 || ((2 < iVar2 && (*(int *)(param_1 + 0xcc + iVar2 * 4) != 10)))))) {
    return 1;
  }
  return 0;
}


