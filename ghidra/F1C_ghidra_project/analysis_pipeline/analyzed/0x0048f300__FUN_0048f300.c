// Function: FUN_0048f300 @ 0048f300
// Size (bytes): 40


undefined4 __fastcall FUN_0048f300(int *param_1)

{
  *(undefined1 *)((int)param_1 + 0x17d) = 0;
  *(undefined1 *)((int)param_1 + 0x17e) = 0;
  if (param_1[0x41] != 4) {
    param_1[0x41] = 0;
    (**(code **)(*param_1 + 0x40))(0);
  }
  return 0;
}


