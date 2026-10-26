// Function: FUN_004b1f50 @ 004b1f50
// Size (bytes): 85


void __thiscall
FUN_004b1f50(int param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5
            ,int param_6,char param_7)

{
  FUN_00566650(param_2);
  *(undefined2 *)(param_1 + 0x16) = param_3;
  *(undefined2 *)(param_1 + 0x18) = param_4;
  *(undefined2 *)(param_1 + 0x1a) = param_5;
  if (param_6 != 0) {
    FUN_00566650(param_6);
  }
  if (param_7 != '\0') {
    *(undefined2 *)(param_1 + 0x14) = param_3;
  }
  FUN_004a1b70();
  return;
}


