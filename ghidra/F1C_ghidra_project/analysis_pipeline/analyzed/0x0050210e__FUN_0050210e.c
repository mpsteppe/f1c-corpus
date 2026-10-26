// Function: FUN_0050210e @ 0050210e
// Size (bytes): 1430


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0050210e(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined1 auStack_158 [256];
  undefined8 local_58;
  double local_50;
  undefined4 local_48;
  undefined4 local_44;
  int local_40 [2];
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  void *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_20 = (void *)0x0;
  iVar3 = FUN_00513c38();
  if (iVar3 != 0) {
    return 0x80004005;
  }
  local_8 = FUN_005118e6("1.0.5",0,&LAB_00502102);
  if ((local_8 == 0) || (local_c = FUN_00513d3d(), local_c == 0)) goto LAB_00502571;
  iVar3 = __setjmp3(local_8);
  if (iVar3 == 0) {
    local_48 = param_1;
    local_44 = param_2;
    uVar9 = CONCAT44(&LAB_005020bf,&local_48);
    iVar3 = local_8;
    FUN_00513bf9();
    FUN_005119e9(local_8,local_c,iVar3,uVar9);
    FUN_005121ae(local_8,local_c,&local_34,&local_1c,&local_28,&local_30,0,0,0);
    if (local_30 == 0) {
      *local_38 = 0x32;
    }
    else if (local_30 == 2) {
      *local_38 = 0x14;
    }
    else if (local_30 == 3) {
      *local_38 = 0x29;
    }
    else if (local_30 == 4) {
      *local_38 = 0x33;
    }
    else if (local_30 == 6) {
      *local_38 = 0x15;
    }
    if (local_28 == 0x10) {
      FUN_00512322();
      iVar3 = *local_38;
      if (iVar3 == 0x14) {
        *local_38 = 0x36315220;
      }
      else if (iVar3 == 0x15) {
        *local_38 = 0x36315241;
      }
      else if (iVar3 == 0x32) {
        *local_38 = 0x36314c20;
      }
      else {
        if (iVar3 != 0x33) {
          return 0x80004005;
        }
        *local_38 = 0x36314c41;
      }
    }
    if (local_28 < 8) {
      FUN_00512334();
    }
    if ((local_30 == 0) && (local_28 < 8)) {
      FUN_005124d5();
    }
    iVar3 = FUN_00512183();
    if (iVar3 == 0) {
      iVar3 = FUN_0051215a();
      if (iVar3 != 0) {
        FUN_0051249f(local_8,_DAT_005adb70,local_58);
      }
    }
    else {
      FUN_00513b36();
    }
    if ((*local_38 != 0x29) && (iVar3 = FUN_00512114(), iVar3 != 0)) {
      FUN_005124d5();
      iVar3 = *local_38;
      if (iVar3 == 0x14) {
        *local_38 = 0x15;
      }
      else if (iVar3 == 0x32) {
        *local_38 = 0x33;
      }
      else if (iVar3 == 0x36314c20) {
        *local_38 = 0x36314c41;
      }
      else if (iVar3 == 0x36315220) {
        *local_38 = 0x36315241;
      }
    }
    iVar3 = *local_38;
    if ((((iVar3 == 0x14) || (iVar3 == 0x36315220)) || (iVar3 == 0x15)) || (iVar3 == 0x36315241)) {
      FUN_00512319();
    }
    if (*local_38 == 0x14) {
      FUN_00512366();
      *local_38 = 0x16;
    }
    FUN_00511b5c();
    iVar3 = *local_38;
    uVar4 = 3;
    if (iVar3 < 0x34) {
      if (iVar3 == 0x33) {
LAB_005023e1:
        local_10 = 2;
        uVar4 = local_10;
      }
      else if (iVar3 != 0x14) {
        if ((iVar3 == 0x15) || (iVar3 == 0x16)) {
LAB_005023d7:
          uVar4 = 4;
        }
        else if ((iVar3 == 0x29) || (uVar4 = local_10, iVar3 == 0x32)) goto LAB_0050239d;
      }
    }
    else if (iVar3 == 0x36314c20) {
LAB_0050239d:
      local_10 = 1;
      uVar4 = local_10;
    }
    else {
      if (iVar3 == 0x36314c41) goto LAB_005023e1;
      if ((iVar3 != 0x36315220) && (uVar4 = local_10, iVar3 == 0x36315241)) goto LAB_005023d7;
    }
    local_10 = uVar4;
    uVar4 = FUN_00512144(local_8);
    if (local_10 == (uVar4 & 0xff)) {
      local_38[3] = local_34;
      local_38[4] = local_1c;
      local_38[5] = 1;
      iVar3 = FUN_0051212e(local_8);
      local_38[0xc] = iVar3;
      local_38[0xd] = 0;
      if (local_38[0x10] == 0) goto LAB_00502673;
      pvVar5 = operator_new(iVar3 * local_1c);
      local_38[1] = (int)pvVar5;
      if (pvVar5 != (void *)0x0) {
        local_38[0xe] = 1;
        local_20 = operator_new(local_1c << 2);
        if (local_20 != (void *)0x0) {
          uVar4 = 0;
          if (local_1c != 0) {
            do {
              *(uint *)((int)local_20 + uVar4 * 4) = local_38[0xc] * uVar4 + local_38[1];
              uVar4 = uVar4 + 1;
            } while (uVar4 < local_1c);
          }
          FUN_00511f23(local_8);
          if (*local_38 == 0x29) {
            local_2c = 0;
            local_24 = 0;
            iVar3 = FUN_00512114();
            if (iVar3 != 0) {
              FUN_0051227f(local_8,local_c,&local_14);
            }
            iVar3 = FUN_00512114();
            if (iVar3 != 0) {
              FUN_005122b2(local_8,local_c,local_40,&local_2c);
            }
            if ((*(float *)(local_8 + 0x130) <= (float)_DAT_005adb68) ||
               (*(float *)(local_8 + 0x134) <= (float)_DAT_005adb68)) {
              iVar3 = 0;
              do {
                auStack_158[iVar3] = (char)iVar3;
                iVar3 = iVar3 + 1;
              } while (iVar3 < 0x100);
            }
            else {
              local_18 = 0;
              local_50 = (double)((float)_DAT_0059e420 /
                                 (*(float *)(local_8 + 0x134) * *(float *)(local_8 + 0x130)));
              do {
                FUN_005881f0();
                uVar2 = __ftol();
                iVar3 = local_18 + 1;
                puVar1 = auStack_158 + local_18;
                local_18 = iVar3;
                *puVar1 = uVar2;
              } while (iVar3 < 0x100);
            }
            pvVar5 = operator_new(0x400);
            local_38[2] = (int)pvVar5;
            if (pvVar5 == (void *)0x0) goto LAB_00502571;
            iVar3 = 0;
            local_38[0xf] = 1;
            if (0 < local_2c) {
              iVar8 = 0;
              do {
                iVar6 = iVar3 * 4;
                *(undefined1 *)(iVar6 + local_38[2]) = auStack_158[*(byte *)(iVar8 + local_14)];
                *(undefined1 *)(local_38[2] + 1 + iVar6) =
                     auStack_158[*(byte *)(iVar8 + 1 + local_14)];
                *(undefined1 *)(local_38[2] + 2 + iVar6) =
                     auStack_158[*(byte *)(iVar8 + 2 + local_14)];
                puVar1 = (undefined1 *)(iVar3 + local_40[0]);
                iVar3 = iVar3 + 1;
                *(undefined1 *)(local_38[2] + 3 + iVar6) = *puVar1;
                iVar8 = iVar8 + 3;
              } while (iVar3 < local_2c);
            }
            if (iVar3 < local_24) {
              iVar8 = iVar3 * 3;
              do {
                iVar6 = iVar3 * 4;
                *(undefined1 *)(iVar6 + local_38[2]) = auStack_158[*(byte *)(iVar8 + local_14)];
                *(undefined1 *)(local_38[2] + 1 + iVar6) =
                     auStack_158[*(byte *)(iVar8 + 1 + local_14)];
                *(undefined1 *)(local_38[2] + 2 + iVar6) =
                     auStack_158[*(byte *)(iVar8 + 2 + local_14)];
                *(undefined1 *)(local_38[2] + 3 + iVar6) = 0xff;
                iVar3 = iVar3 + 1;
                iVar8 = iVar8 + 3;
              } while (iVar3 < local_24);
            }
            if (iVar3 < 0x100) {
              iVar3 = iVar3 << 2;
              do {
                *(undefined1 *)(iVar3 + local_38[2]) = 0xff;
                *(undefined1 *)(iVar3 + 1 + local_38[2]) = 0xff;
                *(undefined1 *)(iVar3 + 2 + local_38[2]) = 0xff;
                *(undefined1 *)(iVar3 + 3 + local_38[2]) = 0xff;
                iVar3 = iVar3 + 4;
              } while (iVar3 < 0x400);
            }
          }
LAB_00502673:
          uVar7 = 0;
          goto LAB_00502675;
        }
      }
LAB_00502571:
      uVar7 = 0x8007000e;
      goto LAB_00502675;
    }
  }
  uVar7 = 0x80004005;
LAB_00502675:
  if (local_8 != 0) {
    FUN_00512093();
  }
  if (local_20 != (void *)0x0) {
    FUN_00587bcf();
  }
  return uVar7;
}


