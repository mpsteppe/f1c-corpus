// Function: FUN_00503888 @ 00503888
// Size (bytes): 56


void FUN_00503888(void)

{
  int iVar1;
  
  iVar1 = FUN_0050fc7d();
  if (iVar1 == 0) {
    PTR_FUN_005d76c0 = FUN_00503533;
    PTR_FUN_005d76c4 = FUN_0050368a;
  }
  else {
    PTR_FUN_005d76c0 = FUN_00503772;
    PTR_FUN_005d76c4 = FUN_00503772;
  }
                    /* WARNING: Could not recover jumptable at 0x005038ba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_005d76c0)();
  return;
}


