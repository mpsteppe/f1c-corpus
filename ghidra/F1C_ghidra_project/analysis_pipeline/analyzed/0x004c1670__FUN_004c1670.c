// Function: FUN_004c1670 @ 004c1670
// Size (bytes): 61


void __fastcall FUN_004c1670(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0xb150) != '\0') {
    *(int *)(param_1 + 0xb148) = *(int *)(param_1 + 0xb148) + 1;
    iVar1 = FUN_004c1190();
    if (iVar1 <= *(int *)(param_1 + 0xb148)) {
      *(undefined4 *)(param_1 + 0xb144) = 3;
    }
    *(undefined4 *)(param_1 + 0xb14c) = 1;
    *(undefined1 *)(param_1 + 0xb150) = 0;
  }
  return;
}


