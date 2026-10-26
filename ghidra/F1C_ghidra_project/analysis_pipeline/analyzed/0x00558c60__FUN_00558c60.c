// Function: FUN_00558c60 @ 00558c60
// Size (bytes): 69


void __thiscall
FUN_00558c60(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  uint *puVar1;
  
  if (param_2 < *(int *)(param_1 + 0x2c)) {
    FUN_0053b200(param_3,param_4,param_5);
    puVar1 = (uint *)(*(int *)(param_1 + 0x34) + param_2 * 0x80);
    *puVar1 = *puVar1 | 0x1000;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffeffff;
  }
  return;
}


