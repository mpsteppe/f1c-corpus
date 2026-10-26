// Function: FUN_0054f7a0 @ 0054f7a0
// Size (bytes): 144


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0054f7a0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  if ((param_2 != param_1) && (*(int *)(param_1 + 0x1e0) != 0)) {
    _DAT_008c5f44 = 0;
    FUN_0054b570(0,*(undefined4 *)(param_1 + 0x204));
    uVar1 = *(uint *)(*(int *)(param_1 + 0x204) + 0x14);
    if ((uVar1 & 0x20000000) == 0) {
      *(uint *)(*(int *)(param_1 + 0x204) + 0x14) = uVar1 | 0x20000000;
      (**(code **)(*DAT_008b8f24 + 4))
                (DAT_008b8f24,*(int *)(param_1 + 0x204) + 0xdc,*(int *)(param_1 + 0x204) + 0xe8,
                 param_1 + 0x114);
    }
    DAT_008c5f40 = FUN_0054f710(param_3);
    FUN_0054f5c0(param_2,param_3);
  }
  return;
}


