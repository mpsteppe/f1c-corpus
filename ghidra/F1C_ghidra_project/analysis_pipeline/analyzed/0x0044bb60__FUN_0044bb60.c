// Function: FUN_0044bb60 @ 0044bb60
// Size (bytes): 163


void FUN_0044bb60(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_14 [20];
  
  iVar1 = DAT_008afe88;
  if (DAT_008afe88 != 0) {
    if (param_1 == 0) {
      FUN_0044acb0(DAT_008afe88,param_2);
    }
    else {
      if (param_1 == 1) {
        FUN_0044acb0(DAT_008afe88,param_2);
        FUN_00449700();
        FUN_004497e0();
        return;
      }
      if (param_1 == 2) {
        FUN_004492b0();
        FUN_0044acb0(iVar1,local_14);
        FUN_00449700();
        FUN_0044b370(local_14,param_2);
        FUN_00449340();
        FUN_004497e0();
        return;
      }
    }
  }
  FUN_004497e0();
  return;
}


