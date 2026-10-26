// Function: FUN_004f8250 @ 004f8250
// Size (bytes): 45


void FUN_004f8250(int *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
    (**(code **)(*(int *)*param_1 + 0x18))();
    if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*param_1)(1);
    }
    *param_1 = 0;
  }
  return;
}


