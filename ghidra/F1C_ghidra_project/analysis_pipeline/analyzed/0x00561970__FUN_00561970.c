// Function: FUN_00561970 @ 00561970
// Size (bytes): 63


void FUN_00561970(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined2 param_7,int param_8)

{
  int iVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)(param_8 + param_6 * 2);
  do {
    *puVar2 = param_7;
    puVar2 = puVar2 + 1;
    iVar1 = param_3;
    if (-1 < param_1) {
      puVar2 = puVar2 + param_5;
      iVar1 = param_4;
    }
    param_1 = param_1 + iVar1;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return;
}


