// Function: FUN_00513bd1 @ 00513bd1
// Size (bytes): 40


void FUN_00513bd1(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(code **)(param_1 + 0x50) != (code *)0x0) {
    (**(code **)(param_1 + 0x50))(param_1,param_2,param_3);
    return;
  }
  FUN_00511869(param_1,"Call to NULL read function");
  return;
}


