// Function: FUN_0059a3a9 @ 0059a3a9
// Size (bytes): 74


void __thiscall FUN_0059a3a9(int param_1,undefined4 param_2,char param_3)

{
  undefined2 uVar1;
  
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  uVar1 = FUN_0059b208(0x20);
  *(undefined2 *)(param_1 + 0x30) = uVar1;
  FUN_0059a948();
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_0059a5fe(*(uint *)(param_1 + 4) | 4,0);
  }
  if (param_3 != '\0') {
    FUN_0059a8fa();
  }
  return;
}


