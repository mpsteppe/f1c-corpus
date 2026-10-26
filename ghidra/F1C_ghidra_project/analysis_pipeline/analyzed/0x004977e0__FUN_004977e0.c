// Function: FUN_004977e0 @ 004977e0
// Size (bytes): 155


void __thiscall FUN_004977e0(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 != -1) {
    *(undefined4 *)(param_1 + 0x157c) = param_2;
    FUN_00496e90(1);
    FUN_00496e90(1);
    switch(param_3) {
    case 0:
      *(undefined4 *)(param_1 + 0x1578) = 0;
      *(undefined4 *)(param_1 + 0xdc) = 0x3c23d70a;
      return;
    case 1:
      *(undefined4 *)(param_1 + 0x1578) = 1;
      *(undefined4 *)(param_1 + 0xdc) = 0x3c23d70a;
      return;
    case 2:
      *(undefined4 *)(param_1 + 0x1578) = 2;
      *(undefined4 *)(param_1 + 0xdc) = 0x3c23d70a;
      return;
    case 3:
      *(undefined4 *)(param_1 + 0x1578) = 3;
    case 4:
      *(undefined4 *)(param_1 + 0xdc) = 0x3c23d70a;
    }
  }
  return;
}


