// Function: FUN_005594b0 @ 005594b0
// Strings:  [Actor %s already exists]


undefined4 __thiscall
FUN_005594b0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined1 local_100 [256];
  
  iVar2 = FUN_00559760(param_2);
  if (iVar2 != 0) {
    FUN_0058815f(local_100,s_Actor__s_already_exists_005dc1a4,param_2);
    return 0xffffffff;
  }
  iVar2 = *param_1;
  if (iVar2 == 0) {
    pvVar3 = operator_new(0x20);
    if (pvVar3 == (void *)0x0) {
      *param_1 = 0;
    }
    else {
      iVar2 = FUN_00559330();
      *param_1 = iVar2;
    }
  }
  else {
    for (iVar1 = *(int *)(iVar2 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
      iVar2 = iVar1;
    }
    pvVar3 = operator_new(0x20);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_00559330();
    }
    *(undefined4 *)(iVar2 + 0x1c) = uVar4;
  }
  FUN_00559350(param_2,param_3,param_4);
  return 0;
}


