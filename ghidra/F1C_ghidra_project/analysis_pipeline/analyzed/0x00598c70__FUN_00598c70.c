// Function: FUN_00598c70 @ 00598c70
// Size (bytes): 24


void __fastcall FUN_00598c70(int *param_1)

{
  undefined4 *puVar1;
  
  if (*param_1 != 0) {
    puVar1 = (undefined4 *)FUN_00598c88();
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
  }
  return;
}


