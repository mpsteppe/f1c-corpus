// Function: FUN_0042e470 @ 0042e470
// Size (bytes): 42


void __thiscall FUN_0042e470(undefined1 *param_1,int param_2,int param_3)

{
  if ((*(int *)(param_2 + 0x10) == *(int *)(param_3 + 0x10)) &&
     (*(int *)(param_3 + 0x14) != *(int *)(param_2 + 0x14))) {
    *(int *)(param_3 + 0x14) = *(int *)(param_2 + 0x14);
    param_1[0x19a4] = 1;
    *param_1 = 1;
  }
  return;
}


