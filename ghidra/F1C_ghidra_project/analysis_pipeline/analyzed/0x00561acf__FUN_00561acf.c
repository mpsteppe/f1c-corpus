// Function: FUN_00561acf @ 00561acf
// Size (bytes): 41


void FUN_00561acf(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_4 + param_1 * 4);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    *puVar1 = param_3;
    puVar1 = puVar1 + 1;
  }
  return;
}


