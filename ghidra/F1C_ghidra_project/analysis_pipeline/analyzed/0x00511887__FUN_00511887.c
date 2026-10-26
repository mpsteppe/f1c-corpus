// Function: FUN_00511887 @ 00511887
// Size (bytes): 21


void FUN_00511887(int param_1,undefined4 param_2)

{
  if (*(code **)(param_1 + 0x44) != (code *)0x0) {
    (**(code **)(param_1 + 0x44))(param_1,param_2);
  }
  return;
}


