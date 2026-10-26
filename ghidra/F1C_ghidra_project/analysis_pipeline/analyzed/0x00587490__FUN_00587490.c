// Function: FUN_00587490 @ 00587490
// Size (bytes): 61


undefined4 * __thiscall FUN_00587490(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *local_4;
  
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  local_4 = param_1;
  cVar1 = FUN_00587580(&local_4,&param_2);
  if (cVar1 != '\0') {
    FUN_00587510(local_4,param_2);
  }
  return param_1;
}


