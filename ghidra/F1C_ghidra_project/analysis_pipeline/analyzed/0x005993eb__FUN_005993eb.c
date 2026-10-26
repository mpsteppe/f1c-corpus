// Function: FUN_005993eb @ 005993eb
// Size (bytes): 64


void __thiscall FUN_005993eb(int param_1,undefined4 param_2,char param_3)

{
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  *(undefined1 *)(param_1 + 0x30) = 0x20;
  FUN_0059a948();
  if (*(int *)(param_1 + 0x28) == 0) {
    FUN_0059a5fe(*(uint *)(param_1 + 4) | 4,0);
  }
  if (param_3 != '\0') {
    FUN_0059a8fa();
  }
  return;
}


