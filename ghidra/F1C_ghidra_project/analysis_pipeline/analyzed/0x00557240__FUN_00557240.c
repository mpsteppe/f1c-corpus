// Function: FUN_00557240 @ 00557240
// Size (bytes): 57


int __fastcall FUN_00557240(int param_1)

{
  int iVar1;
  
  FUN_0053c2a0();
  iVar1 = 8;
  do {
    FUN_00553db0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x208) = 0;
  *(undefined4 *)(param_1 + 0x20c) = 0;
  return param_1;
}


