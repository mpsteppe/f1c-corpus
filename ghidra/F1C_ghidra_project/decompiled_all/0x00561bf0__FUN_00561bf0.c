// Function: FUN_00561bf0 @ 00561bf0
// Strings:  [master.openspy.net]


undefined4 __thiscall
FUN_00561bf0(undefined **param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  SOCKET s;
  u_long uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14;
  sockaddr local_10;
  
  if (param_1 != (undefined **)0x0) {
    *param_1 = (undefined *)0x0;
  }
  FUN_00564660();
  s = socket(2,2,0x11);
  if (s == 0xffffffff) {
    return 1;
  }
  iVar3 = param_2 + 100;
  iVar2 = param_2;
  for (; param_2 < iVar3; param_2 = param_2 + 1) {
    FUN_00562010(&local_10,0);
    uVar1 = htonl(0x7f000001);
    if (CONCAT22(local_10.sa_data._4_2_,local_10.sa_data._2_2_) == uVar1) {
      local_10.sa_data[2] = '\0';
      local_10.sa_data[3] = '\0';
      local_10.sa_data[4] = '\0';
      local_10.sa_data[5] = '\0';
    }
    iVar2 = bind(s,&local_10,0x10);
    if (iVar2 == 0) goto LAB_00561c86;
  }
  if (iVar2 != 0) {
    return 2;
  }
LAB_00561c86:
  if (param_2 == 0) {
    local_14 = 0x10;
    iVar3 = getsockname(s,&local_10,&local_14);
    if (iVar3 != 0) {
      return 2;
    }
    ntohs(local_10.sa_data._0_2_);
  }
  FUN_00561d40(s,s,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  if (param_1 == (undefined **)0x0) {
    param_1 = &PTR_DAT_005e4dfc;
  }
  uVar4 = FUN_00561ff0(0x6cfc,*param_1 + 0xec);
  return uVar4;
}


