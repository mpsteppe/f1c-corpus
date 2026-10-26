// Function: FUN_004c0ab0 @ 004c0ab0
// Size (bytes): 94


int __fastcall FUN_004c0ab0(int param_1)

{
  int iVar1;
  
  iVar1 = 0x67;
  do {
    FUN_004c03c0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004c03c0();
  FUN_004c0370();
  *(undefined4 *)(param_1 + 0xb144) = 0;
  *(undefined1 *)(param_1 + 0xb150) = 0;
  *(undefined4 *)(param_1 + 0xb148) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xb14c) = 1;
  return param_1;
}


