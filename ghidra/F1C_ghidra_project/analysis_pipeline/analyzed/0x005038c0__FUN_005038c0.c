// Function: FUN_005038c0 @ 005038c0
// Size (bytes): 47


void FUN_005038c0(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = FUN_0050fc7d();
  if (iVar1 == 0) {
    PTR_FUN_005d76c0 = FUN_00503533;
    UNRECOVERED_JUMPTABLE = FUN_0050368a;
  }
  else {
    UNRECOVERED_JUMPTABLE = FUN_00503772;
    PTR_FUN_005d76c0 = FUN_00503772;
  }
  PTR_FUN_005d76c4 = UNRECOVERED_JUMPTABLE;
                    /* WARNING: Could not recover jumptable at 0x005038ed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


