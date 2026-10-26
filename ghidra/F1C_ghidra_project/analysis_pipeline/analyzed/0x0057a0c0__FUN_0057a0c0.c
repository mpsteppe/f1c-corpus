// Function: FUN_0057a0c0 @ 0057a0c0
// Size (bytes): 38


undefined1 __thiscall FUN_0057a0c0(char *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  param_2 = param_2 - (int)param_1;
  do {
    if (*param_1 != param_1[param_2]) {
      return 0;
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 < 0x10);
  return 1;
}


