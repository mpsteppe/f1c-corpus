// Function: FUN_0057b950 @ 0057b950
// Size (bytes): 76


undefined4 __thiscall
FUN_0057b950(int *param_1,int param_2,int param_3,int param_4,int param_5,SOCKET param_6)

{
  int iVar1;
  
  *param_1 = param_2;
  param_2 = 0x10;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  iVar1 = getsockname(param_6,(sockaddr *)(param_1 + 4),&param_2);
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}


