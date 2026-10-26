// Function: FUN_00544e90 @ 00544e90
// Strings:  [Error creating view]


undefined4 __thiscall FUN_00544e90(undefined4 param_1,int *param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  pvVar1 = operator_new(0x1bc);
  if (pvVar1 != (void *)0x0) {
    puVar2 = (undefined4 *)FUN_005418b0();
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = param_1;
      FUN_005418e0(param_3);
      if (param_2 != (int *)0x0) {
        *param_2 = (int)puVar2;
      }
      return 0;
    }
  }
  FUN_0053c590(0xffffffff,s_Error_creating_view_005dbe1c);
  return 0xffffffff;
}


