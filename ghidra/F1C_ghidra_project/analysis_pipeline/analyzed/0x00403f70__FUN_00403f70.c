// Function: FUN_00403f70 @ 00403f70
// Size (bytes): 72


void __thiscall FUN_00403f70(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x154) + param_2 * 0x1c);
  *param_3 = *puVar1;
  param_3[1] = puVar1[1];
  param_3[2] = puVar1[2];
  puVar1 = (undefined4 *)(param_2 * 0x1c + 0xc + *(int *)(param_1 + 0x154));
  *param_4 = *puVar1;
  param_4[1] = puVar1[1];
  param_4[2] = puVar1[2];
  return;
}


