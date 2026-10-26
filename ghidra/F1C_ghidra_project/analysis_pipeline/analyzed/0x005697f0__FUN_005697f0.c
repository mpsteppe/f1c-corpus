// Function: FUN_005697f0 @ 005697f0
// Size (bytes): 104


void __fastcall FUN_005697f0(int param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(*(int *)(param_1 + 0x22c) * 0x38);
  *(void **)(param_1 + 0x230) = pvVar1;
  *(undefined4 *)(param_1 + 0x22c) = 0;
  pvVar1 = operator_new(*(int *)(param_1 + 0x234) * 0x84);
  *(void **)(param_1 + 0x238) = pvVar1;
  *(undefined4 *)(param_1 + 0x234) = 0;
  pvVar1 = operator_new(*(int *)(param_1 + 0x23c) * 0x58);
  *(void **)(param_1 + 0x240) = pvVar1;
  *(undefined4 *)(param_1 + 0x23c) = 0;
  return;
}


