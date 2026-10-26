// Function: FUN_004b1ac0 @ 004b1ac0
// Size (bytes): 78


void __thiscall
FUN_004b1ac0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6,char param_7)

{
  FUN_00566650(param_2);
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x20) = param_5;
  if (param_6 != 0) {
    FUN_00566650(param_6);
  }
  if (param_7 != '\0') {
    *(undefined4 *)(param_1 + 0x14) = param_3;
  }
  FUN_004a1b70();
  return;
}


