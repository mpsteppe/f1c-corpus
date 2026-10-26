// Function: FUN_004184b0 @ 004184b0
// Size (bytes): 62


int __fastcall FUN_004184b0(int param_1)

{
  int extraout_EDX;
  
  FUN_00411680();
  do {
    FUN_004144d0();
  } while (extraout_EDX != 1);
  *(undefined1 *)(param_1 + 0xaf0) = 0;
  *(undefined4 *)(param_1 + 0xaf4) = 0;
  FUN_004b0170();
  FUN_004186a0();
  return param_1;
}


