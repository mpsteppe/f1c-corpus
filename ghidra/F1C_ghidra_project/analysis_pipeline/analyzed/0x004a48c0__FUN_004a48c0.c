// Function: FUN_004a48c0 @ 004a48c0
// Size (bytes): 53


int __fastcall FUN_004a48c0(int param_1)

{
  int iVar1;
  
  iVar1 = 5;
  do {
    FUN_0042e1c0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_004a4db0();
  return param_1;
}


