// Function: FUN_004a4000 @ 004a4000
// Size (bytes): 38


void __fastcall FUN_004a4000(int param_1)

{
  *(undefined4 *)(param_1 + 0x78) = 1;
  *(undefined4 *)(param_1 + 0x84) = 0;
  if (*(int *)(param_1 + 100) != 0) {
    FUN_0054c030(1,1,1,0);
  }
  return;
}


