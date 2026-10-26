// Function: FUN_004482d0 @ 004482d0
// Size (bytes): 43


void __fastcall FUN_004482d0(undefined4 *param_1)

{
  *param_1 = 0;
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
    param_1[1] = 0;
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0xff7fffff;
  return;
}


