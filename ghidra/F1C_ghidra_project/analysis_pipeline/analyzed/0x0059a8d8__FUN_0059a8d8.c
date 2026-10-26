// Function: FUN_0059a8d8 @ 0059a8d8
// Size (bytes): 34


void __thiscall FUN_0059a8d8(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x1c); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    (*(code *)puVar1[2])(param_2,param_1,puVar1[1]);
  }
  return;
}


