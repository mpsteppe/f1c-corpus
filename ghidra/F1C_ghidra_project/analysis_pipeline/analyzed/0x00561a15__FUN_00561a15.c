// Function: FUN_00561a15 @ 00561a15
// Size (bytes): 44


void FUN_00561a15(int param_1,int param_2,undefined2 param_3,int param_4,int param_5)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(param_5 + param_1 * 2);
  do {
    *puVar1 = param_3;
    puVar1 = puVar1 + param_4;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return;
}


