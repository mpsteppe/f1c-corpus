// Function: thunk_FUN_0050653e @ 0050696c
// Size (bytes): 5


undefined4 __fastcall thunk_FUN_0050653e(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))(piVar1);
  }
  *param_1 = 0;
  return 0;
}


