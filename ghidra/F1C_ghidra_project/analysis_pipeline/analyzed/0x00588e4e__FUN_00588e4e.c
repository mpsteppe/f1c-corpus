// Function: FUN_00588e4e @ 00588e4e
// Size (bytes): 280


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00588e4e(char *param_1,undefined1 *param_2,undefined2 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined1 local_8c [136];
  
  if (param_1 == (char *)0x0) {
LAB_00588ef4:
    puVar2 = (undefined *)0x0;
  }
  else {
    if ((*param_1 == 'C') && (param_1[1] == '\0')) {
      param_2[1] = 0;
      *param_2 = 0x43;
      if (param_3 != (undefined2 *)0x0) {
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0;
      }
      if (param_4 == (undefined4 *)0x0) {
        return param_2;
      }
      *param_4 = 0;
      return param_2;
    }
    iVar1 = _strcmp(&DAT_005e6468,param_1);
    if ((iVar1 != 0) && (iVar1 = _strcmp(&DAT_005e63e4,param_1), iVar1 != 0)) {
      iVar1 = FUN_00588f8b(local_8c,param_1);
      if ((iVar1 != 0) || (iVar1 = FUN_0058fd90(local_8c,&DAT_008d3e48,local_8c), iVar1 == 0))
      goto LAB_00588ef4;
      _DAT_008d3e50 = (uint)DAT_008d3e4c;
      FUN_00589057(&DAT_005e6468,local_8c);
      if (*param_1 == '\0') {
        param_1 = &DAT_005e6468;
      }
      FUN_0058fca0(&DAT_005e63e4,param_1);
    }
    if (param_3 != (undefined2 *)0x0) {
      FUN_0058cc00(param_3,&DAT_008d3e48,6);
    }
    if (param_4 != (undefined4 *)0x0) {
      FUN_0058cc00(param_4,&DAT_008d3e50,4);
    }
    FUN_0058fca0(param_2,&DAT_005e6468);
    puVar2 = &DAT_005e6468;
  }
  return puVar2;
}


