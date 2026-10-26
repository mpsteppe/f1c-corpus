// Function: FUN_00404fa0 @ 00404fa0
// Strings:  [LowPass Filter]


char * __fastcall FUN_00404fa0(int param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if ((-1 < param_1) && (param_1 < 4)) {
    pcVar1 = s_LowPass_Filter_005be720 + param_1 * 0x20;
  }
  return pcVar1;
}


