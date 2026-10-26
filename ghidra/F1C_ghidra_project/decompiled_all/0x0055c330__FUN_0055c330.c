// Function: FUN_0055c330 @ 0055c330
// Strings:  [Could not get current display mode]


undefined4 __fastcall FUN_0055c330(int *param_1)

{
  int iVar1;
  int unaff_retaddr;
  int local_10 [2];
  undefined4 *puStack_8;
  int iStack_4;
  
  iVar1 = (**(code **)(*(int *)param_1[0x43f] + 0x20))((int *)param_1[0x43f]);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    FUN_0053c590(0xffffffff,s_Could_not_get_current_display_mo_005dbcac);
    return 0xffffffff;
  }
  if (puStack_8 != (undefined4 *)0x0) {
    *puStack_8 = 0;
  }
  if (iStack_4 != 0) {
    *(int **)iStack_4 = local_10;
  }
  if (unaff_retaddr != 0) {
    if (local_10[0] == 0x16) {
      FUN_0055c450(0x15,0,unaff_retaddr);
      return 0;
    }
    FUN_0055c450(local_10[0],0,unaff_retaddr);
  }
  return 0;
}


