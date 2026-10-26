// Function: FUN_00403fc0 @ 00403fc0
// Size (bytes): 101


void __thiscall
FUN_00403fc0(int param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           ((*(int *)(param_1 + 0x164) * param_3 + param_2) * 0x1c + *(int *)(param_1 + 0x158));
  *param_4 = *puVar1;
  param_4[1] = puVar1[1];
  param_4[2] = puVar1[2];
  puVar1 = (undefined4 *)
           ((*(int *)(param_1 + 0x164) * param_3 + param_2) * 0x1c + 0xc + *(int *)(param_1 + 0x158)
           );
  *param_5 = *puVar1;
  param_5[1] = puVar1[1];
  param_5[2] = puVar1[2];
  return;
}


