// Function: FUN_004bdb90 @ 004bdb90
// Size (bytes): 78


int __fastcall FUN_004bdb90(int param_1)

{
  int iVar1;
  
  iVar1 = 0x40;
  do {
    FUN_004bd7d0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004bd7d0();
  *(undefined4 *)(param_1 + 0x924) = 0;
  *(undefined4 *)(param_1 + 0x928) = 0;
  *(undefined4 *)(param_1 + 0x92c) = 0;
  *(undefined4 *)(param_1 + 0x930) = 0;
  *(undefined4 *)(param_1 + 0x934) = 0;
  return param_1;
}


