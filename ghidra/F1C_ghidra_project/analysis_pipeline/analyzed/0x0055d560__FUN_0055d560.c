// Function: FUN_0055d560 @ 0055d560
// Size (bytes): 45


void __thiscall FUN_0055d560(int param_1,int param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) {
    if (param_2 == 1) {
      *param_3 = *(undefined4 *)(param_1 + 0x14);
    }
    else {
      if (param_2 == 2) {
        *param_3 = *(undefined4 *)(param_1 + 0x24);
        return;
      }
      if (param_2 == 3) {
        *param_3 = *(undefined4 *)(param_1 + 0x34);
        return;
      }
    }
  }
  return;
}


