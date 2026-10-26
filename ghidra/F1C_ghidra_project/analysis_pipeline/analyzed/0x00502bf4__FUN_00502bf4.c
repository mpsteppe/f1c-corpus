// Function: FUN_00502bf4 @ 00502bf4
// Size (bytes): 30


void __fastcall FUN_00502bf4(int *param_1)

{
  if ((undefined4 *)param_1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[1])(1);
  }
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*param_1)(1);
  }
  return;
}


