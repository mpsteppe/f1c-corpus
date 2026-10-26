// Function: FUN_00493480 @ 00493480
// Strings:  [SET_SYMBOL, LOSTFOCUS, FOCUS, RELEASE, SIMULATECLICK, EXIT_GAME, DROP_POPUPS, CLICK]


undefined4 __thiscall FUN_00493480(undefined4 *param_1,int param_2,int param_3)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined2 local_88;
  undefined1 local_86;
  undefined4 *local_84;
  undefined1 local_80;
  undefined4 local_7f;
  
  local_80 = DAT_005ea438;
  puVar3 = &local_7f;
  for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)puVar3 = 0;
  *(undefined1 *)((int)puVar3 + 2) = 0;
  if ((param_2 == 0) || (param_3 == 0)) {
    return 0xffffffff;
  }
  param_1[0x65] = param_1[0x65] + 1;
  local_84 = param_1;
  iVar6 = FUN_00491fb0();
  puVar3 = local_84;
  do {
    if ((iVar6 == 0) || (iVar6 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f4), iVar6 != 0)) {
      param_1[0x65] = param_1[0x65] + -1;
      return 0;
    }
    iVar6 = FUN_005654a0(s_DO_PAGE_005cc908,&local_80);
    if (iVar6 == 0) {
      iVar6 = FUN_005654a0(s_DO_PAGE_TRANSITION_SLIDE_005cc8ec,&local_80);
      if (iVar6 != 0) {
        pvVar1 = operator_new(0x1c);
        if (pvVar1 == (void *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          puVar2 = (undefined4 *)FUN_0049a580();
        }
        *puVar2 = 2;
        FUN_00566650(&local_80);
        goto LAB_004937e5;
      }
      iVar6 = FUN_005654a0(s_Do_Page_Transition_Shred_005cc8d0,&local_80);
      if (iVar6 != 0) {
        pvVar1 = operator_new(0x1c);
        if (pvVar1 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = (undefined4 *)FUN_0049a580();
        }
        *puVar3 = 3;
        FUN_00566650(&local_80);
        puVar2 = puVar3;
        goto LAB_004937e5;
      }
      iVar6 = FUN_005654a0(s_Do_Page_Transition_Iris_Open_005cc8b0,&local_80);
      if (iVar6 != 0) {
        pvVar1 = operator_new(0x1c);
        if (pvVar1 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = (undefined4 *)FUN_0049a580();
        }
        *puVar3 = 4;
        FUN_00566650(&local_80);
        puVar2 = puVar3;
        goto LAB_004937e5;
      }
      iVar6 = FUN_005654a0(s_Do_Page_Transition_Iris_Close_005cc890,&local_80);
      if (iVar6 != 0) {
        pvVar1 = operator_new(0x1c);
        if (pvVar1 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = (undefined4 *)FUN_0049a580();
        }
        *puVar3 = 5;
        FUN_00566650(&local_80);
        puVar2 = puVar3;
        goto LAB_004937e5;
      }
      iVar6 = FUN_005654a0(s_Do_Page_Transition_Attribute_005cc870,&local_80);
      if (iVar6 != 0) {
        pvVar1 = operator_new(0x1c);
        if (pvVar1 == (void *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = (undefined4 *)FUN_0049a580();
        }
        *puVar3 = 6;
        FUN_00566650(&local_80);
        puVar2 = puVar3;
        goto LAB_004937e5;
      }
      iVar6 = FUN_005654a0(s_Transition_Attribute_005cc858,&local_80);
      if (iVar6 == 0) {
        iVar6 = FUN_005654a0(s_DO_LAYER_005cc84c,&local_80);
        if (iVar6 == 0) {
          iVar6 = FUN_005654a0(s_SET_SYMBOL_005cc544,&local_80);
          if (iVar6 == 0) {
            iVar6 = FUN_005654a0(s_DROP_POPUPS_005cc838,&local_80);
            if (iVar6 == 0) {
              iVar6 = FUN_005654a0(s_EXIT_GAME_005cc82c,&local_80);
              if (iVar6 == 0) {
                iVar6 = FUN_005654a0(s_SIMULATECLICK_005cc81c,&local_80);
                if (iVar6 == 0) goto LAB_0049394d;
                pvVar1 = operator_new(0x1c);
                if (pvVar1 == (void *)0x0) {
                  puVar2 = (undefined4 *)0x0;
                }
                else {
                  puVar2 = (undefined4 *)FUN_0049a580();
                }
                *puVar2 = 0xc;
                FUN_00566650(&local_80);
              }
              else {
                pvVar1 = operator_new(0x1c);
                if (pvVar1 == (void *)0x0) {
                  puVar2 = (undefined4 *)0x0;
                  uRam00000000 = 0xb;
                }
                else {
                  puVar2 = (undefined4 *)FUN_0049a580();
                  *puVar2 = 0xb;
                }
              }
            }
            else {
              pvVar1 = operator_new(0x1c);
              if (pvVar1 == (void *)0x0) {
                puVar2 = (undefined4 *)0x0;
                uRam00000000 = 10;
              }
              else {
                puVar2 = (undefined4 *)FUN_0049a580();
                *puVar2 = 10;
              }
            }
          }
          else {
            local_88 = DAT_005cc540;
            local_86 = DAT_005cc542;
            pvVar1 = operator_new(0x1c);
            if (pvVar1 == (void *)0x0) {
              puVar2 = (undefined4 *)0x0;
            }
            else {
              puVar2 = (undefined4 *)FUN_0049a580();
            }
            *puVar2 = 9;
            iVar6 = FUN_005897ca(&local_80,&local_88);
            iVar5 = FUN_005897ca(0,&local_88);
            if (iVar6 != 0) {
              FUN_00566650(iVar6);
            }
            param_1 = local_84;
            if (iVar5 != 0) {
              FUN_00566650(iVar5);
              param_1 = local_84;
            }
          }
        }
        else {
          pvVar1 = operator_new(0x1c);
          if (pvVar1 == (void *)0x0) {
            puVar2 = (undefined4 *)0x0;
          }
          else {
            puVar2 = (undefined4 *)FUN_0049a580();
          }
          *puVar2 = 7;
          FUN_00566650(&local_80);
        }
        goto LAB_004937e5;
      }
      uVar4 = FUN_0049a210(&local_80);
      puVar3[5] = uVar4;
    }
    else {
      pvVar1 = operator_new(0x1c);
      if (pvVar1 == (void *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = (undefined4 *)FUN_0049a580();
      }
      *puVar2 = 1;
      FUN_00566650(&local_80);
LAB_004937e5:
      iVar6 = FUN_00588410(param_3,s_CLICK_005cc844);
      if (iVar6 == 0) {
        FUN_00486480(puVar2);
      }
      else {
        iVar6 = FUN_00588410(param_3,s_RELEASE_005cc814);
        if (iVar6 == 0) {
          FUN_004864c0(puVar2);
        }
        else {
          iVar6 = FUN_00588410(param_3,s_FOCUS_005cc80c);
          if (iVar6 == 0) {
            FUN_00486500(puVar2);
          }
          else {
            iVar6 = FUN_00588410(param_3,s_LOSTFOCUS_005cc800);
            if (iVar6 == 0) {
              FUN_00486540(puVar2);
            }
          }
        }
      }
    }
LAB_0049394d:
    iVar6 = FUN_00491fb0();
  } while( true );
}


