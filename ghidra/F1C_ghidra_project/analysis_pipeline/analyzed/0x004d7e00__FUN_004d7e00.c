// Function: FUN_004d7e00 @ 004d7e00
// Size (bytes): 41


void __fastcall FUN_004d7e00(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x18))();
  if (cVar1 != '\0') {
    FUN_004d7fe0();
  }
  if ((char)param_1[2] != '\0') {
    FUN_004d7ff0();
  }
                    /* WARNING: Could not recover jumptable at 0x004d7e26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 4))();
  return;
}


