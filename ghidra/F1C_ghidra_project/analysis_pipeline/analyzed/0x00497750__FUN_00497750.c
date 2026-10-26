// Function: FUN_00497750 @ 00497750
// Size (bytes): 132


int __thiscall FUN_00497750(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  FUN_00499840();
  FUN_004998e0(param_1);
  iVar1 = FUN_0053d880();
  while( true ) {
    if (iVar1 == 0) {
      FUN_004b0170();
      return 0;
    }
    puVar2 = *(undefined1 **)(iVar1 + 0x34);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    iVar3 = FUN_00588410(puVar2,param_2);
    if (iVar3 == 0) break;
    FUN_00499910();
    iVar1 = FUN_0053d880();
  }
  FUN_004b0170();
  return iVar1;
}


