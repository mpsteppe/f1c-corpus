// Function: FUN_0055b200 @ 0055b200
// Strings:  [INSTANCE, MASFILE, SEARCHPATH, LIGHT, GROUP, FOGDENSITY, FOGOUT, FOGIN]


undefined4 __thiscall FUN_0055b200(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  undefined4 uVar6;
  undefined4 local_42c;
  undefined4 local_428;
  undefined4 local_424;
  undefined4 local_420;
  undefined4 local_41c;
  undefined1 local_418 [4];
  char local_414 [256];
  int local_314 [2];
  uint local_30c;
  void *local_4;
  
  FUN_00559a40();
  local_30c = param_3;
  local_4 = operator_new(param_3);
  uVar1 = FUN_0058803f(local_4,1,local_30c,param_2);
  if (uVar1 == param_3) {
    iVar2 = FUN_00559a70();
    while ((iVar2 != 3 && (local_314[0] != 3))) {
      if (local_314[0] != 2) {
        iVar2 = FUN_00559e20(s_INCLUDEFILE_005dc428,local_414,0);
        if ((iVar2 != 0) && (iVar2 = FUN_0055b6b0(local_414), iVar2 != 0)) goto LAB_0055b68a;
        iVar2 = FUN_00559e20(s_SEARCHPATH_005d3968,local_414,0);
        if (iVar2 != 0) {
          FUN_0053c6f0(local_414);
        }
        iVar2 = FUN_00559e20(s_GROUPMETHOD_005dc41c,local_414,0);
        if (iVar2 != 0) {
          iVar2 = _strncmp(local_414,s_DYNAMIC_005dc414,7);
          if (iVar2 == 0) {
            uVar6 = 0x2000;
          }
          else {
            iVar2 = _strncmp(local_414,s_LINKSINGLE_005dc408,10);
            if (iVar2 != 0) goto LAB_0055b340;
            uVar6 = 0x1000;
          }
          FUN_0054a160(uVar6);
        }
LAB_0055b340:
        iVar2 = FUN_00559e20(s_FONTFILE_005dc3fc,local_414,0);
        if (iVar2 != 0) {
          iVar2 = FUN_0053cfe0(&local_41c,local_414,0x10801);
          if (iVar2 != 0) goto LAB_0055b64c;
          FUN_0053d340(local_41c);
        }
        iVar2 = FUN_00559e20(s_MASFILE_005d3960,local_414,0);
        if ((iVar2 != 0) && (iVar2 = FUN_0053ce10(local_418,local_414), iVar2 != 0)) {
LAB_0055b66b:
          FUN_00587bcf(local_4);
          return 0xffffffff;
        }
        iVar2 = FUN_00559f00(s_AMBIENTCOLOR_005dc3ec,&local_420,&local_424,&local_428,0);
        if (iVar2 != 0) {
          FUN_00543800(local_420,local_424,local_428);
        }
        iVar2 = FUN_00559e20(s_FOGMODE_005dc3e4,local_414,0);
        if (iVar2 != 0) {
          iVar2 = 7;
          bVar5 = true;
          pcVar3 = local_414;
          pcVar4 = s_LINEAR_005dc3dc;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar5 = *pcVar3 == *pcVar4;
            pcVar3 = pcVar3 + 1;
            pcVar4 = pcVar4 + 1;
          } while (bVar5);
          if (bVar5) {
            *(undefined4 *)(param_1 + 0x19c) = 0x20000;
          }
          else {
            iVar2 = 4;
            bVar5 = true;
            pcVar3 = local_414;
            pcVar4 = &DAT_005dc3d8;
            do {
              if (iVar2 == 0) break;
              iVar2 = iVar2 + -1;
              bVar5 = *pcVar3 == *pcVar4;
              pcVar3 = pcVar3 + 1;
              pcVar4 = pcVar4 + 1;
            } while (bVar5);
            if (bVar5) {
              *(undefined4 *)(param_1 + 0x19c) = 0x40000;
            }
            else {
              iVar2 = 5;
              bVar5 = true;
              pcVar3 = local_414;
              pcVar4 = &DAT_005dc3d0;
              do {
                if (iVar2 == 0) break;
                iVar2 = iVar2 + -1;
                bVar5 = *pcVar3 == *pcVar4;
                pcVar3 = pcVar3 + 1;
                pcVar4 = pcVar4 + 1;
              } while (bVar5);
              if (bVar5) {
                *(undefined4 *)(param_1 + 0x19c) = 0x80000;
              }
            }
          }
        }
        iVar2 = FUN_00559f00(s_FOGCOLOR_005dc3c4,&local_420,&local_424,&local_428,0);
        if (iVar2 != 0) {
          *(undefined2 *)(param_1 + 0x18c) = (undefined2)local_420;
          *(undefined2 *)(param_1 + 0x18a) = (undefined2)local_424;
          *(undefined2 *)(param_1 + 0x188) = (undefined2)local_428;
        }
        iVar2 = FUN_00559fb0(s_FOGIN_005dc3bc,&local_42c,0,0,0);
        if (iVar2 != 0) {
          *(undefined4 *)(param_1 + 0x194) = local_42c;
        }
        iVar2 = FUN_00559fb0(s_FOGOUT_005dc3b4,&local_42c,0,0,0);
        if (iVar2 != 0) {
          *(undefined4 *)(param_1 + 0x198) = local_42c;
        }
        iVar2 = FUN_00559fb0(s_FOGDENSITY_005dc3a8,&local_42c,0,0,0);
        if (iVar2 != 0) {
          *(undefined4 *)(param_1 + 400) = local_42c;
        }
        iVar2 = FUN_00559e20(&DAT_005dc234,local_414,0);
        if ((iVar2 != 0) && (iVar2 = FUN_0055a060(local_414,0,local_314), iVar2 != 0)) {
LAB_0055b68a:
          FUN_00587bcf(local_4);
          return 0xffffffff;
        }
        iVar2 = FUN_00559e20(s_GROUP_005dc3a0,local_414,0);
        if ((iVar2 != 0) && (iVar2 = FUN_0055a790(local_414,local_314), iVar2 != 0)) {
LAB_0055b64c:
          FUN_00587bcf(local_4);
          return 0xffffffff;
        }
        iVar2 = FUN_00559e20(s_INSTANCE_005cd620,local_414,0);
        if ((iVar2 != 0) && (iVar2 = FUN_0055a910(local_414,0,local_314), iVar2 != 0))
        goto LAB_0055b66b;
        iVar2 = FUN_00559e20(s_LIGHT_005dc298,local_414,0);
        if ((iVar2 != 0) && (iVar2 = FUN_0055a500(local_414,local_314), iVar2 != 0))
        goto LAB_0055b68a;
      }
      iVar2 = FUN_00559a70();
    }
  }
  FUN_00587bcf(local_4);
  return 0;
}


