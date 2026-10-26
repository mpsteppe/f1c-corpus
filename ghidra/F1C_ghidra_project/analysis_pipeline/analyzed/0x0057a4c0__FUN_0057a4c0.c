// Function: FUN_0057a4c0 @ 0057a4c0
// Size (bytes): 35


void __fastcall FUN_0057a4c0(int *param_1)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 0x4c))();
    if ((int *)*param_1 != (int *)0x0) {
      (**(code **)(*(int *)*param_1 + 0x44))(1);
    }
    *param_1 = 0;
  }
  return;
}


