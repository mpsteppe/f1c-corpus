// Function: FUN_005598b0 @ 005598b0
// Strings:  [Could not find resposne %s, Could not find resposne %s, Could not find actor %s]


undefined4 FUN_005598b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_100 [256];
  
  if (DAT_008b8f2c == 0) {
    FUN_0053c590(0xffffffff,s_Could_not_find_resposne__s_005dc1d8);
    return 0xffffffff;
  }
  iVar1 = FUN_00559760(param_2);
  if (iVar1 == 0) {
    FUN_0058815f(local_100,s_Could_not_find_actor__s_005dc1f4,param_2);
    return 0xffffffff;
  }
  iVar2 = FUN_005597c0(param_3);
  if (iVar2 == 0) {
    FUN_0058815f(local_100,s_Could_not_find_resposne__s_005dc1d8,param_3);
    return 0xffffffff;
  }
  uVar3 = FUN_00559630(iVar1,iVar2);
  iVar1 = *(int *)(param_1 + 0x224);
  if (iVar1 != 0) {
    for (iVar2 = *(int *)(iVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      iVar1 = iVar2;
    }
    puVar4 = operator_new(8);
    *(undefined4 **)(iVar1 + 4) = puVar4;
    *puVar4 = uVar3;
    puVar4[1] = 0;
    return 0;
  }
  puVar4 = operator_new(8);
  *(undefined4 **)(param_1 + 0x224) = puVar4;
  *puVar4 = uVar3;
  *(undefined4 *)(*(int *)(param_1 + 0x224) + 4) = 0;
  return 0;
}


