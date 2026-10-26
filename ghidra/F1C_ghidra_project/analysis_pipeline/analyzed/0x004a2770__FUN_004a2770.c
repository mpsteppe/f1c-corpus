// Function: FUN_004a2770 @ 004a2770
// Size (bytes): 85


void __thiscall
FUN_004a2770(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  *(undefined1 *)(param_1 + 2) = param_2;
  *(undefined4 *)(param_1 + 0x48) = param_3;
  FUN_004a2010(param_4,param_5,param_6,0);
  if (*(int *)(param_1 + 100) != 0) {
    if (*(char *)(param_1 + 2) != '\0') {
      FUN_0054c030(1,1,0,0);
      return;
    }
    FUN_0054c030(0,0,0,0);
  }
  return;
}


