// Function: FUN_00454d30 @ 00454d30
// Size (bytes): 102


undefined4 FUN_00454d30(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  char cVar1;
  
  cVar1 = FUN_00454350(param_1,&param_3,param_3);
  if (cVar1 != '\0') {
    *param_2 = 1;
    param_2[1] = param_3;
    return 1;
  }
  cVar1 = FUN_004541d0(param_1,&param_3);
  if (cVar1 != '\0') {
    *param_2 = 0;
    param_2[1] = param_3;
    return 1;
  }
  return 0;
}


