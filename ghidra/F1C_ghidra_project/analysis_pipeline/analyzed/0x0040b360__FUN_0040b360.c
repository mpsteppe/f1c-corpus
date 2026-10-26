// Function: FUN_0040b360 @ 0040b360
// Size (bytes): 29


void __fastcall FUN_0040b360(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x18))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
                    /* WARNING: Could not recover jumptable at 0x0040b378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar2 + 0x1c))();
    return;
  }
  return;
}


