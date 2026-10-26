// Function: FUN_00561a86 @ 00561a86
// Size (bytes): 73


void FUN_00561a86(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,int param_8,int param_9)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_9 + param_6 * 4);
  do {
    *puVar2 = param_7;
    puVar2 = puVar2 + param_8;
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


