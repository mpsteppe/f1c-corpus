// Function: FUN_0055b6b0 @ 0055b6b0
// Strings:  [%s\%s, Could not locate scene file %s, Illegal scene file name %s]


undefined4 FUN_0055b6b0(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  if (*param_1 == '\0') {
    FUN_0058815f(local_200,s_Illegal_scene_file_name__s_005dc454,param_1);
    FUN_0053c590(0xffffffff,local_200);
    return 0xffffffff;
  }
  iVar1 = FUN_00587db0(param_1,&DAT_005be828);
  if (iVar1 == 0) {
    iVar1 = 0;
    if (0 < DAT_008b8e30) {
      puVar5 = &DAT_008b5a3c;
      do {
        FUN_0058815f(local_100,s__s__s_005c2d64,puVar5,param_1);
        iVar3 = FUN_00587db0(local_100,&DAT_005be828);
        if (iVar3 != 0) {
          FUN_00587f64(iVar3,0,2);
          uVar2 = FUN_0058ace6(iVar3);
          FUN_00587f64(iVar3,0,0);
          iVar4 = FUN_0055b200(iVar3,uVar2);
          if (iVar4 != 0) {
            FUN_00587d02(iVar3);
            return 0xffffffff;
          }
          FUN_00587d02(iVar3);
          break;
        }
        iVar1 = iVar1 + 1;
        puVar5 = puVar5 + 0x84;
      } while (iVar1 < DAT_008b8e30);
    }
    if (iVar1 == DAT_008b8e30) {
      iVar1 = 0;
      if (DAT_008b8f14 != 0) {
        iVar1 = 0;
        iVar3 = DAT_008b8f14;
        do {
          iVar4 = FUN_00560230(param_1);
          if (iVar4 == 0) {
            iVar3 = FUN_0055b200(*(undefined4 *)(iVar3 + 0x10),
                                 *(undefined4 *)
                                  (*(int *)(iVar3 + 0x124) * 0x100 + 8 + *(int *)(iVar3 + 0x128)));
            if (iVar3 != 0) {
              return 0xffffffff;
            }
            break;
          }
          iVar3 = *(int *)(iVar3 + 0x130);
          iVar1 = iVar1 + 1;
        } while (iVar3 != 0);
      }
    }
    else {
      iVar1 = -1;
    }
    if (iVar1 == DAT_008b6ac0) {
      FUN_0058815f(local_200,s_Could_not_locate_scene_file__s_005dc434,param_1);
      FUN_0053c590(0xffffffff,local_200);
      return 0xffffffff;
    }
  }
  else {
    FUN_00587f64(iVar1,0,2);
    uVar2 = FUN_0058ace6(iVar1);
    FUN_00587f64(iVar1,0,0);
    iVar3 = FUN_0055b200(iVar1,uVar2);
    if (iVar3 != 0) {
      FUN_00587d02(iVar1);
      return 0xffffffff;
    }
    FUN_00587d02(iVar1);
  }
  return 0;
}


