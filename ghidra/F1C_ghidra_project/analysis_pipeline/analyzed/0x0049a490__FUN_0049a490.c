// Function: FUN_0049a490 @ 0049a490
// Size (bytes): 130


undefined4 FUN_0049a490(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char local_100 [256];
  
  local_100[0] = '\0';
  iVar2 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_100 + iVar2)] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_100);
  iVar2 = FUN_0049a360(local_100);
  if (iVar2 != 0) {
    FUN_0049a2e0(param_2);
    return 0;
  }
  FUN_0049a3b0(local_100,param_2);
  return 0;
}


