// Function: FUN_004ce860 @ 004ce860
// Size (bytes): 105


int __thiscall FUN_004ce860(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char local_40 [64];
  
  iVar2 = -(int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(local_40 + iVar2)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  FUN_00589901(local_40);
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      cVar1 = FUN_004cdbf0(local_40);
      if (cVar1 != '\0') {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 8));
  }
  return -1;
}


