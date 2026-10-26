// Function: FUN_00462ce0 @ 00462ce0
// Size (bytes): 75


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_00462ce0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = FUN_0057a580(param_2,param_3);
  if (uVar1 == 0) {
    *(undefined1 *)(*param_1 + 0x29) = 1;
    *(undefined4 *)(*param_1 + 0x10) = _DAT_0059f0a0;
    *(undefined4 *)(*param_1 + 0x3fc4) = 4;
    return 1;
  }
  return uVar1 & 0xffffff00;
}


