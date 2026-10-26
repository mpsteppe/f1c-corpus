// Function: FUN_00599534 @ 00599534
// Size (bytes): 44


void __fastcall FUN_00599534(int param_1)

{
  char cVar1;
  
  if (((*(int *)(param_1 + 4) != 0) &&
      (cVar1 = *(char *)(*(int *)(param_1 + 4) + -1), cVar1 != '\0')) && (cVar1 != -1)) {
    FUN_00599560(*(undefined4 *)(param_1 + 8),0);
  }
  if (*(int *)(param_1 + 4) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 4) + -1) = 0xff;
  }
  return;
}


