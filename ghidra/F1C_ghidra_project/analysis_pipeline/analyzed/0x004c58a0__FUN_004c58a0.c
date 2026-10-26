// Function: FUN_004c58a0 @ 004c58a0
// Size (bytes): 83


undefined4 FUN_004c58a0(char *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *_Source;
  
  iVar1 = FUN_004c5840(param_4);
  if (iVar1 != 0) {
    iVar1 = FUN_005679c0(param_3);
    if (iVar1 != 0) {
      _Source = (char *)FUN_00567970();
      _strncpy(param_1,_Source,param_2 - 1U);
      param_1[param_2 - 1U] = '\0';
      return 0;
    }
  }
  return 1;
}


