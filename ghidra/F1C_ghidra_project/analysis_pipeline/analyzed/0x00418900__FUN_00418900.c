// Function: FUN_00418900 @ 00418900
// Size (bytes): 57


void __fastcall FUN_00418900(int param_1)

{
  FUN_00411740(0);
  FUN_00411740(1);
  FUN_004150c0();
  if (*(undefined4 **)(param_1 + 0xaf4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xaf4))(1);
    *(undefined4 *)(param_1 + 0xaf4) = 0;
  }
  return;
}


