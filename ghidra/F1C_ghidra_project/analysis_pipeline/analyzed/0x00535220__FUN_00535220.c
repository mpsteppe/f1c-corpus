// Function: FUN_00535220 @ 00535220
// Size (bytes): 142


int __fastcall FUN_00535220(undefined4 *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (undefined4 *)0x0) || (*(char *)(param_1 + 0x17) != 'w')) {
    return -2;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  iVar1 = param_3;
  do {
    if (iVar1 == 0) {
LAB_00535289:
      uVar2 = FUN_00536e90(param_3);
      param_1[0x13] = uVar2;
      return param_3 - param_1[1];
    }
    if (param_1[4] == 0) {
      param_1[3] = param_1[0x12];
      iVar1 = FUN_00588678(param_1[0x12],1,0x4000,param_1[0x10]);
      if (iVar1 != 0x4000) {
        param_1[0xe] = 0xffffffff;
        goto LAB_00535289;
      }
      param_1[4] = 0x4000;
    }
    iVar1 = FUN_00535e80();
    param_1[0xe] = iVar1;
    if (iVar1 != 0) goto LAB_00535289;
    iVar1 = param_1[1];
  } while( true );
}


