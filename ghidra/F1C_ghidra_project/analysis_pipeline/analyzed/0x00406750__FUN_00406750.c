// Function: FUN_00406750 @ 00406750
// Size (bytes): 62


void __fastcall FUN_00406750(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    _AIL_close_stream_4(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x5c) != -1) {
    FUN_00406a70();
  }
  iVar1 = FUN_004080b0(*(undefined4 *)(param_1 + 0x1c));
  if (iVar1 != 0) {
    FUN_00405630();
    return;
  }
  return;
}


