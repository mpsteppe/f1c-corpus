// Function: FUN_00488970 @ 00488970
// Size (bytes): 90


void __fastcall FUN_00488970(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[0x38] < 0) {
    param_1[0x38] = 0;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x18))();
    iVar3 = param_1[0x38];
    iVar2 = (**(code **)(*param_1 + 0x20))();
    if (iVar2 < iVar1 + iVar3) {
      iVar3 = (**(code **)(*param_1 + 0x20))();
      iVar1 = (**(code **)(*param_1 + 0x18))();
      param_1[0x38] = iVar3 - iVar1;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x004889c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xa8))();
  return;
}


