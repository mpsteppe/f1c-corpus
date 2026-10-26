// Function: FUN_004c9790 @ 004c9790
// Size (bytes): 25


void __fastcall FUN_004c9790(int param_1)

{
  if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x20))(1);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}


