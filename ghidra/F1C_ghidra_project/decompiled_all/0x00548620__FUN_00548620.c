// Function: FUN_00548620 @ 00548620
// Strings:  [%s\%s, Unable to locate material lib %s]


undefined4 FUN_00548620(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 local_100 [256];
  
  iVar1 = FUN_00587db0(param_1,&DAT_005be828);
  if (iVar1 == 0) {
    iVar1 = 0;
    if (0 < DAT_008b8e30) {
      puVar4 = &DAT_008b5a3c;
      do {
        FUN_0058815f(local_100,s__s__s_005c2d64,puVar4,param_1);
        iVar2 = FUN_00587db0(local_100,&DAT_005be828);
        if (iVar2 != 0) {
          iVar3 = FUN_00548190(0);
          if (iVar3 != 0) {
            FUN_00587d02(iVar2);
            return 0xffffffff;
          }
          FUN_00587d02(iVar2);
          break;
        }
        iVar1 = iVar1 + 1;
        puVar4 = puVar4 + 0x84;
      } while (iVar1 < DAT_008b8e30);
    }
    if (iVar1 == DAT_008b8e30) {
      iVar1 = 0;
      for (iVar2 = DAT_008b8f14; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x130)) {
        iVar3 = FUN_00560230(param_1);
        if (iVar3 == 0) {
          iVar2 = FUN_00548190(0);
          if (iVar2 != 0) {
            return 0xffffffff;
          }
          break;
        }
        iVar1 = iVar1 + 1;
      }
    }
    else {
      iVar1 = -1;
    }
    if (iVar1 == DAT_008b6ac0) {
      FUN_0058815f(local_100,s_Unable_to_locate_material_lib__s_005dbe70,param_1);
      FUN_0053c590(0xffffffff,local_100);
      return 0xffffffff;
    }
  }
  else {
    iVar2 = FUN_00548190(0);
    if (iVar2 != 0) {
      FUN_00587d02(iVar1);
      return 0xffffffff;
    }
    FUN_00587d02(iVar1);
  }
  return 0;
}


