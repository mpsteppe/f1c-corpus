// Function: FUN_00476660 @ 00476660
// Size (bytes): 135


void __fastcall FUN_00476660(int *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  piVar1 = (int *)param_1[0x3c];
  param_1[0x3e] = (int)piVar1;
  if (piVar1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar1;
  }
  iVar5 = 0;
  param_1[0x5d] = 0;
  if (iVar3 != 0) {
    while( true ) {
      puVar2 = *(undefined1 **)(iVar3 + 0x3c);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      puVar4 = DAT_007d0434;
      if (DAT_007d0434 == (undefined1 *)0x0) {
        puVar4 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(puVar4,puVar2);
      if (iVar3 == 0) break;
      iVar5 = iVar5 + 1;
      if (param_1[0x3e] != 0) {
        param_1[0x3e] = *(int *)(param_1[0x3e] + 4);
      }
      if (((int *)param_1[0x3e] == (int *)0x0) || (iVar3 = *(int *)param_1[0x3e], iVar3 == 0))
      goto LAB_004766db;
    }
    param_1[0x5d] = iVar5;
  }
LAB_004766db:
                    /* WARNING: Could not recover jumptable at 0x004766e1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x98))();
  return;
}


