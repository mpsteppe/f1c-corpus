// Function: FUN_004e4500 @ 004e4500
// Size (bytes): 105


int __fastcall FUN_004e4500(int param_1)

{
  int iVar1;
  
  FUN_004f6f20();
  FUN_004dfbb0();
  FUN_004a48c0();
  iVar1 = 4;
  do {
    FUN_004dfb90();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004f2430();
  *(undefined4 *)(param_1 + 0x32bc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x39a4) = 0;
  FUN_004e4790();
  return param_1;
}


