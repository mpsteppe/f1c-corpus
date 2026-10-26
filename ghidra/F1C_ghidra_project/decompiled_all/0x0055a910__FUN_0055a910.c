// Function: FUN_0055a910 @ 0055a910
// Strings:  [ACTOR, SHADOWOBJECT, LODOUT, LODIN, MESHFILE, INSTANCE, ORIENT, RESPONSE]


undefined4 __thiscall FUN_0055a910(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  bool bVar9;
  undefined4 local_338;
  int local_334;
  int local_330;
  int local_32c;
  int local_328;
  undefined4 local_324;
  undefined4 local_320;
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined4 local_310;
  undefined4 local_30c;
  undefined4 local_308;
  uint local_304;
  char local_300 [256];
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  iVar6 = 0;
  local_330 = 0;
  local_304 = 0;
  local_328 = 0;
  local_334 = 0;
  InterlockedDecrement(&DAT_008b8ee8);
  FUN_00545f50(0);
  pvVar1 = operator_new(0x23c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0054a600();
  }
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  *(int *)(iVar2 + 0x40) = param_3;
  local_314 = 0;
  local_308 = 0;
  local_30c = 0;
  local_320 = 0;
  local_318 = 0;
  local_310 = 0;
  local_31c = 0xbf800000;
  local_324 = 0xbf800000;
  if (param_3 != 0) {
    *(undefined4 *)(iVar2 + 0x3c) = 8;
  }
  iVar3 = FUN_00559a70();
  do {
    if ((iVar3 == 1) || (*param_4 == 3)) {
      iVar6 = *(int *)(iVar2 + 0x204);
      if (iVar6 == 0) {
        FUN_0054a770();
        FUN_0054a710();
        FUN_00587bcf(iVar2);
      }
      else {
        do {
          *(undefined4 *)(iVar6 + 0xfc) = *(undefined4 *)(iVar2 + 0x50);
          iVar6 = *(int *)(iVar6 + 0x10);
        } while (iVar6 != 0);
        if (param_3 == 0) {
          FUN_00545250(iVar2);
        }
        else {
          FUN_0054ba00(iVar2,0);
        }
      }
      if (local_328 != 0) {
        FUN_0054b4d0(local_310,local_318,local_320,local_30c,local_308,local_314);
      }
      return 0;
    }
    if (*param_4 != 2) {
      iVar3 = FUN_00559f00(s_VISGROUPS_005dc394,&local_304,0,0,0);
      if (iVar3 != 0) {
        if ((DAT_008b8ee0 & local_304) != local_304) {
          iVar6 = FUN_00559a70();
          while ((iVar6 != 1 && (*param_4 != 3))) {
            iVar6 = FUN_00559a70();
          }
          FUN_0054a710();
          FUN_00587bcf(iVar2);
          return 0;
        }
        *(uint *)(iVar2 + 0x38) = local_304;
      }
      iVar3 = FUN_00559e20(s_INSTANCE_005cd620,local_200,0);
      if ((iVar3 != 0) && (iVar3 = FUN_0055a910(local_200,iVar2,param_4), iVar3 != 0)) {
        return 0xffffffff;
      }
      iVar3 = FUN_00559e20(s_MESHFILE_005cd614,local_200,0);
      if (iVar3 != 0) {
        iVar6 = FUN_0054a730(param_2,local_200);
        if (iVar6 != 0) {
          return 0xffffffff;
        }
        iVar6 = *(int *)(iVar2 + 0x204);
        for (iVar3 = *(int *)(*(int *)(iVar2 + 0x204) + 0x10); iVar3 != 0;
            iVar3 = *(int *)(iVar3 + 0x10)) {
          iVar6 = iVar3;
        }
      }
      iVar3 = FUN_00559e20(s_ANIMFILE_005dc388,local_200,0);
      if (iVar3 != 0) {
        iVar6 = FUN_005518a0(&local_334,local_200,0);
        if (iVar6 == -1) {
          return 0xffffffff;
        }
        local_32c = 0;
        iVar6 = FUN_00559e20(s_AUTOSTART_005dc37c,local_300,0);
        if (iVar6 != 0) {
          iVar6 = 5;
          bVar9 = true;
          pcVar7 = local_300;
          pcVar8 = &DAT_005c596c;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar9 = *pcVar7 == *pcVar8;
            pcVar7 = pcVar7 + 1;
            pcVar8 = pcVar8 + 1;
          } while (bVar9);
          if (bVar9) {
            local_32c = 1;
          }
        }
        iVar3 = local_32c;
        iVar6 = *(int *)(iVar2 + 0x204);
        if (iVar6 == 0) {
          iVar6 = FUN_0054bb40(local_334);
          if (iVar6 != 0) {
            return 0xffffffff;
          }
          iVar6 = 0;
          if (local_32c != 0) {
            FUN_00551480();
          }
        }
        else {
          do {
            iVar4 = FUN_00551560(local_334);
            if (iVar4 != 0) {
              return 0xffffffff;
            }
            if (iVar3 != 0) {
              FUN_00551790(local_334 + 0x1c);
            }
            iVar6 = *(int *)(iVar6 + 0x10);
          } while (iVar6 != 0);
          iVar6 = 0;
        }
      }
      iVar3 = FUN_00559fb0(s_LODIN_005cd60c,&local_31c,0,0,0);
      if (iVar3 != 0) {
        FUN_0054d4e0(local_31c,0xbf800000);
      }
      iVar3 = FUN_00559fb0(s_LODOUT_005cd604,&local_324,0,0,0);
      if (iVar3 != 0) {
        FUN_0054d4e0(0xbf800000,local_324);
      }
      iVar3 = FUN_00559e20(s_HATTARGET_005dc370,local_300,0);
      if (iVar3 != 0) {
        bVar9 = true;
        iVar3 = 5;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar6 + 0x14) | 0x100;
        }
        else {
          uVar5 = *(uint *)(iVar6 + 0x14) & 0xfffffeff;
        }
        *(uint *)(iVar6 + 0x14) = uVar5;
      }
      iVar3 = FUN_00559e20(s_COLLTARGET_005dc364,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar6 + 0x14) | 0x40;
        }
        else {
          uVar5 = *(uint *)(iVar6 + 0x14) & 0xffffffbf;
        }
        *(uint *)(iVar6 + 0x14) = uVar5;
      }
      iVar3 = FUN_00559e20(s_SPHERETARGET_005dc354,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar6 + 0x14) | 0x80;
        }
        else {
          uVar5 = *(uint *)(iVar6 + 0x14) & 0xffffff7f;
        }
        *(uint *)(iVar6 + 0x14) = uVar5;
      }
      iVar3 = FUN_00559e20(s_ZBUFFER_005dc34c,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar6 + 0x14) & 0xffffdfff;
        }
        else {
          uVar5 = *(uint *)(iVar6 + 0x14) | 0x2000;
        }
        *(uint *)(iVar6 + 0x14) = uVar5;
      }
      iVar3 = FUN_00559e20(s_SHADOWCASTER_005dc33c,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if ((bVar9) && (local_330 == 0)) {
          iVar3 = FUN_00545930(iVar6,param_3);
          if (iVar3 != 0) {
            return 0xffffffff;
          }
          local_330 = 1;
        }
      }
      iVar3 = FUN_00559e20(s_SHADOWOBJECT_005cd5f4,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if ((bVar9) && (local_330 == 0)) {
          iVar3 = FUN_00545930(iVar6,param_3);
          if (iVar3 != 0) {
            return 0xffffffff;
          }
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) | 0x2000000;
          local_330 = 1;
        }
      }
      iVar3 = FUN_00559e20(s_SHADOWRECEIVER_005dc32c,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) | 0x4000;
          *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 1;
        }
        else {
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xffffbfff;
        }
      }
      iVar3 = FUN_00559e20(s_REFLECTOR_005dc320,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) | 0x20000;
          *(int *)(param_1 + 0x174) = *(int *)(param_1 + 0x174) + 1;
        }
        else {
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xfffdffff;
        }
      }
      iVar3 = FUN_00559e20(s_MORPHTARGET_005dc314,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) | 0x200000;
        }
      }
      FUN_00559e20(s_LIGHTOBJECT_005dc308,local_300,0);
      iVar3 = FUN_00559fb0(&DAT_005dc230,&local_310,&local_318,&local_320,0);
      if (iVar3 != 0) {
        local_328 = 1;
      }
      iVar3 = FUN_00559fb0(s_ORIENT_005dc228,&local_30c,&local_308,&local_314,0);
      if (iVar3 != 0) {
        local_328 = 1;
      }
      iVar3 = FUN_00559e20(s_MOVEABLE_005dc2fc,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar2 + 0x3c) | 0x10;
        }
        else {
          uVar5 = *(uint *)(iVar2 + 0x3c) & 0xffffffef;
        }
        *(uint *)(iVar2 + 0x3c) = uVar5;
      }
      iVar3 = FUN_00559e20(s_STAMP_005dc2f4,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar2 + 0x3c) | 0x110;
        }
        else {
          uVar5 = *(uint *)(iVar2 + 0x3c) & 0xfffffeff;
        }
        *(uint *)(iVar2 + 0x3c) = uVar5;
      }
      iVar3 = FUN_00559e20(s_BILLBOARD_005dc2e8,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar2 + 0x3c) | 0x2010;
        }
        else {
          uVar5 = *(uint *)(iVar2 + 0x3c) & 0xffffdfff;
        }
        *(uint *)(iVar2 + 0x3c) = uVar5;
      }
      iVar3 = FUN_00559e20(s_RENDER_005dc2e0,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar2 + 0x3c) & 0xfffffffb;
        }
        else {
          uVar5 = *(uint *)(iVar2 + 0x3c) | 4;
        }
        *(uint *)(iVar2 + 0x3c) = uVar5;
      }
      iVar3 = FUN_00559e20(s_CHANGE_005dc2d8,local_300,0);
      if (iVar3 != 0) {
        iVar3 = 5;
        bVar9 = true;
        pcVar7 = local_300;
        pcVar8 = &DAT_005c596c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar9 = *pcVar7 == *pcVar8;
          pcVar7 = pcVar7 + 1;
          pcVar8 = pcVar8 + 1;
        } while (bVar9);
        if (bVar9) {
          uVar5 = *(uint *)(iVar2 + 0x3c) & 0xfffffdff;
        }
        else {
          uVar5 = *(uint *)(iVar2 + 0x3c) | 0x200;
        }
        *(uint *)(iVar2 + 0x3c) = uVar5;
      }
      iVar3 = FUN_00559f00(s_SPECIAL1_005dc2cc,&local_338,0,0,0);
      if (iVar3 != 0) {
        FUN_0054c110(local_338,0x800);
      }
      iVar3 = FUN_00559f00(s_SPECIAL2_005dc2c0,&local_338,0,0,0);
      if (iVar3 != 0) {
        FUN_0054c110(local_338,0x1000);
      }
      iVar3 = FUN_00559f00(s_PLANES_005dc2b8,&local_338,0,0,0);
      if (iVar3 != 0) {
        *(undefined4 *)(iVar2 + 0x50) = local_338;
      }
      iVar3 = FUN_00559e20(s_ACTOR_005cd46c,local_300,0);
      if (iVar3 != 0) {
        FUN_00559820(iVar2,local_300,0);
      }
      iVar3 = FUN_00559e20(s_HATACTOR_005dc2ac,local_300,0);
      if (iVar3 != 0) {
        FUN_00559820(iVar2,local_300,1);
      }
      iVar3 = FUN_00559e20(s_RESPONSE_005dc2a0,local_300,local_100);
      if (iVar3 != 0) {
        FUN_005598b0(iVar2,local_300,local_100);
      }
    }
    iVar3 = FUN_00559a70();
  } while( true );
}


