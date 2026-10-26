// Function: FUN_004060c0 @ 004060c0
// Size (bytes): 63


void __fastcall FUN_004060c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x58) != 0) &&
     (iVar2 = *(int *)(*(int *)(param_1 + 0x58) + 0x10), iVar2 != 0)) {
    _AIL_set_sample_processor_12(iVar2,1,*(undefined4 *)(param_1 + 100));
    if (*(int *)(param_1 + 0x60) != -1) {
      iVar2 = param_1 + 0x68;
      uVar1 = FUN_00404fc0(iVar2);
      _AIL_set_filter_sample_preference_12
                (*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x10),uVar1,iVar2);
    }
  }
  return;
}


