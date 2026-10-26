// Function: FUN_00488f40 @ 00488f40
// Size (bytes): 65


void __thiscall
FUN_00488f40(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined1 *puVar1;
  
  if (*(int *)(param_1 + 200) != 0) {
    puVar1 = *(undefined1 **)(*(int *)(param_1 + 200) + 0x40);
    if (puVar1 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    FUN_00498560(puVar1);
  }
  FUN_00488be0(param_2,param_3,param_4,param_5);
  return;
}


