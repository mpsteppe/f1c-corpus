// Function: FUN_00563a70 @ 00563a70
// Size (bytes): 51


int __fastcall FUN_00563a70(char *param_1,int param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  if (param_3 != 0) {
    while (pcVar1 != param_1 + param_2) {
      if (*pcVar1 == '\\') {
        param_3 = param_3 + -1;
      }
      pcVar1 = pcVar1 + 1;
      if (param_3 == 0) {
        return (int)pcVar1 - (int)param_1;
      }
    }
    if (param_3 != 0) {
      return -1;
    }
  }
  return (int)pcVar1 - (int)param_1;
}


