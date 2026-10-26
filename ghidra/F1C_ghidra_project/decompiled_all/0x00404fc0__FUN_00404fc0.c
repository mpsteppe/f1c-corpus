// Function: FUN_00404fc0 @ 00404fc0
// Strings:  [LowPass Cutoff]


char * __fastcall FUN_00404fc0(int param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if ((-1 < param_1) && (param_1 < 4)) {
    pcVar1 = s_LowPass_Cutoff_005be7a0 + param_1 * 0x20;
  }
  return pcVar1;
}


