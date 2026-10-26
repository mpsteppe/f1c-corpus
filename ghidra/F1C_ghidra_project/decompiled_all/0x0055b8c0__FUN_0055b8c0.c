// Function: FUN_0055b8c0 @ 0055b8c0
// Strings:  [%s\%s, MESHFILE, INSTANCE, Illegal scene file name %s, Illegal scene file name %s]


undefined4 FUN_0055b8c0(char *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 local_514 [256];
  int local_414;
  uint local_40c;
  void *local_104;
  undefined1 local_100 [256];
  
  FUN_00559a40();
  if (*param_1 == '\0') {
    FUN_0058815f(local_514,s_Illegal_scene_file_name__s_005dc454,param_1);
    FUN_0053c590(0xffffffff,local_514);
    return 0xffffffff;
  }
  iVar1 = FUN_00587db0(param_1,&DAT_005be828);
  if (iVar1 == 0) {
    iVar4 = 0;
    if (0 < DAT_008b8e30) {
      puVar5 = &DAT_008b5a3c;
      do {
        FUN_0058815f(local_100,s__s__s_005c2d64,puVar5,param_1);
        iVar1 = FUN_00587db0(local_100,&DAT_005be828);
        if (iVar1 != 0) break;
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 0x84;
      } while (iVar4 < DAT_008b8e30);
    }
    if (iVar4 == DAT_008b8e30) {
      FUN_0058815f(local_514,s_Illegal_scene_file_name__s_005dc454,param_1);
      FUN_0053c590(0xffffffff,local_514);
      return 0xffffffff;
    }
  }
  FUN_00587f64(iVar1,0,2);
  uVar2 = FUN_0058ace6(iVar1);
  FUN_00587f64(iVar1,0,0);
  local_40c = uVar2;
  local_104 = operator_new(uVar2);
  uVar3 = FUN_0058803f(local_104,1,local_40c,iVar1);
  if (uVar3 == uVar2) {
    iVar4 = FUN_00559a70();
    while ((iVar4 != 3 && (local_414 != 3))) {
      if ((local_414 != 2) &&
         ((iVar4 = FUN_00559e20(s_INSTANCE_005cd620,local_514,0), iVar4 != 0 &&
          (iVar4 = FUN_00559a70(), iVar4 != 3)))) {
        while (local_414 != 3) {
          if ((local_414 != 2) &&
             (iVar4 = FUN_00559e20(s_MESHFILE_005cd614,local_514,0), iVar4 != 0)) {
            if (param_2 != (int *)0x0) {
              *param_2 = *param_2 + 1;
            }
            break;
          }
          iVar4 = FUN_00559a70();
          if (iVar4 == 3) break;
        }
      }
      iVar4 = FUN_00559a70();
    }
  }
  FUN_00587bcf(local_104);
  FUN_00587d02(iVar1);
  return 0;
}


