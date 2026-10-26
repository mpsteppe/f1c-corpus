// Function: FUN_004b1c20 @ 004b1c20
// Size (bytes): 78


void __thiscall
FUN_004b1c20(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,undefined1 param_5
            ,int param_6,char param_7)

{
  FUN_00566650(param_2);
  *(undefined1 *)(param_1 + 0x15) = param_3;
  *(undefined1 *)(param_1 + 0x16) = param_4;
  *(undefined1 *)(param_1 + 0x17) = param_5;
  if (param_6 != 0) {
    FUN_00566650(param_6);
  }
  if (param_7 != '\0') {
    *(undefined1 *)(param_1 + 0x14) = param_3;
  }
  FUN_004a1b70();
  return;
}


