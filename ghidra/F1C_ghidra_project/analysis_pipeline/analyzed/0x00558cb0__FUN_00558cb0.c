// Function: FUN_00558cb0 @ 00558cb0
// Size (bytes): 62


void __thiscall
FUN_00558cb0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint *puVar1;
  
  if (param_2 < *(int *)(param_1 + 0x2c)) {
    FUN_0053b330(param_3,param_4,param_5);
    puVar1 = (uint *)(*(int *)(param_1 + 0x34) + param_2 * 0x80);
    *puVar1 = *puVar1 | 0x4000;
  }
  return;
}


