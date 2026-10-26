// Function: FUN_0049e570 @ 0049e570
// Size (bytes): 59


void FUN_0049e570(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 * 0x128 + 0x834 + DAT_007c54e0);
  if ((*piVar1 != 0) && ((char)piVar1[0x10] != '\0')) {
    FUN_0049e670();
    return;
  }
  FUN_0049e760();
  return;
}


