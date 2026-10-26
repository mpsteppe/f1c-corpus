// Function: FUN_004d0b00 @ 004d0b00
// Size (bytes): 23


int __fastcall FUN_004d0b00(int param_1)

{
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  FUN_004a2220();
  return param_1;
}


