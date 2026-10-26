// Function: FUN_00561af8 @ 00561af8
// Size (bytes): 50


void FUN_00561af8(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_5 + param_1 * 4);
  do {
    *puVar1 = param_3;
    puVar1 = puVar1 + param_4;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return;
}


