// Function: FUN_00559820 @ 00559820
// Strings:  [Could not find resposne %s, Could not find actor %s]


undefined4 FUN_00559820(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  char local_100 [256];
  
  if (DAT_008b8f2c == 0) {
    pcVar2 = s_Could_not_find_resposne__s_005dc1d8;
  }
  else {
    iVar1 = FUN_00559760(param_2);
    if (iVar1 != 0) {
      *(int *)(param_1 + 0x220) = iVar1;
      *(undefined4 *)(param_1 + 0x21c) = param_3;
      return 0;
    }
    FUN_0058815f(local_100,s_Could_not_find_actor__s_005dc1f4,param_2);
    pcVar2 = local_100;
  }
  FUN_0053c590(0xffffffff,pcVar2);
  return 0xffffffff;
}


