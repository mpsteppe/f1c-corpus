// Function: FUN_0057a420 @ 0057a420
// Size (bytes): 158


undefined4 * __thiscall FUN_0057a420(undefined4 *param_1,int *param_2,char *param_3)

{
  void *pvVar1;
  int *piVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c75b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_3 = '\0';
  if ((*param_2 < 0) || (1 < *param_2)) {
    *param_1 = 0;
    *param_3 = '\x01';
  }
  else {
    pvVar1 = operator_new(0xbf8);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_0057ba10(param_2,param_3);
    }
    *param_1 = piVar2;
    local_4 = 0xffffffff;
    if (*param_3 != '\0') {
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x44))(1);
      }
      *param_1 = 0;
    }
  }
  ExceptionList = local_c;
  return param_1;
}


