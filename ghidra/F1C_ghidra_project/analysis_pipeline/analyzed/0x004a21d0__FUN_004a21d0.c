// Function: FUN_004a21d0 @ 004a21d0
// Size (bytes): 71


void FUN_004a21d0(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  char local_48 [64];
  undefined1 local_8;
  undefined4 local_4;
  
  iVar2 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_48 + iVar2)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  local_8 = 1;
  local_4 = 0;
  FUN_004a2010(param_1,local_48,param_3,param_4);
  return;
}


