// Function: FUN_00405b00 @ 00405b00
// Size (bytes): 71


void __fastcall FUN_00405b00(int *param_1)

{
  int *piVar1;
  
  (**(code **)(*param_1 + 8))();
  if (param_1[0x17] != 0) {
    piVar1 = (int *)(param_1[0x17] + 4);
    *piVar1 = *piVar1 + -1;
    if ((int)((undefined4 *)param_1[0x17])[1] < 1) {
      _AIL_mem_free_lock_4(*(undefined4 *)param_1[0x17]);
      if (param_1[0x17] != 0) {
        FUN_00587bcf(param_1[0x17]);
      }
    }
    param_1[0x17] = 0;
  }
  FUN_00407be0(param_1);
  return;
}


