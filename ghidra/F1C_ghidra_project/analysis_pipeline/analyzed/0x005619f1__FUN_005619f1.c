// Function: FUN_005619f1 @ 005619f1
// Size (bytes): 36


void FUN_005619f1(int param_1,int param_2,undefined2 param_3,int param_4)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_4 + param_1 * 2);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    *puVar1 = param_3;
    puVar1 = puVar1 + 1;
  }
  return;
}


