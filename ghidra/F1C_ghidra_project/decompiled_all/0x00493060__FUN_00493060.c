// Function: FUN_00493060 @ 00493060
// Strings:  [SOUND_LOSTFOCUS, SOUND_FOCUS, FRAME, FONT3, FONT2, FONT1, OFFSET_PAIR, SECONDARYOFFSET]


undefined4 __thiscall FUN_00493060(int param_1,char *param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80;
  undefined4 local_7f;
  
  local_80 = DAT_005ea438;
  puVar8 = &local_7f;
  for (iVar7 = 0x1f; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *(undefined2 *)puVar8 = 0;
  *(undefined1 *)((int)puVar8 + 2) = 0;
  local_88 = 0;
  local_8c = 0;
  local_94 = 0;
  local_98 = 0;
  local_90 = 0;
  local_84 = 0;
  if (param_2 != (char *)0x0) {
    iVar7 = -1;
    pcVar9 = param_2;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    if ((iVar7 != -2) && (iVar7 = FUN_0049a210(param_2), iVar7 == 0)) {
      pvVar2 = operator_new(0x7c);
      if (pvVar2 == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_00499c50(*(undefined4 *)(param_1 + 0x1a4));
      }
      FUN_00499e10(param_2);
      iVar7 = FUN_00491fb0();
      do {
        if ((iVar7 == 0) || (iVar7 = FUN_00587c20(&DAT_007cdb70,&DAT_005cc4f4), iVar7 != 0)) {
          uVar3 = FUN_0049a1c0(uVar3);
          return uVar3;
        }
        iVar7 = FUN_005654a0(s_SOUND_CLICK_005cc7f4,&local_84);
        if (iVar7 == 0) {
          iVar7 = FUN_005654a0(s_SOUND_RELEASE_005cc7e4,&local_84);
          if (iVar7 != 0) {
            FUN_00499e40(&local_84);
            goto LAB_0049316e;
          }
          iVar7 = FUN_005654a0(s_SOUND_FOCUS_005cc644,&local_84);
          if (iVar7 != 0) {
            FUN_00499e50(&local_84);
            goto LAB_0049316e;
          }
          iVar7 = FUN_005654a0(s_SOUND_LOSTFOCUS_005cc634,&local_84);
          if (iVar7 != 0) {
            FUN_00499e60(&local_84);
            goto LAB_0049316e;
          }
          iVar7 = FUN_005654a0(s_SOUND_DRAG_005cc7d8,&local_84);
          if (iVar7 != 0) {
            FUN_00499e70(&local_84);
            goto LAB_0049316e;
          }
          iVar7 = FUN_00565870(&DAT_005c57d0,&local_98,&stack0xffffff64,0,0,0,0,0,0);
          if (iVar7 == 0) {
            iVar7 = FUN_00565870(s_SECONDARYOFFSET_005cc7c8,&local_98,&stack0xffffff64,&local_94,
                                 &local_88,0,0,0,0);
            if (iVar7 == 0) {
              iVar7 = FUN_00565760(s_OFFSET_PAIR_005cc7bc,&local_8c,&local_90,0,0);
              if (iVar7 == 0) {
                iVar7 = FUN_005654a0(&DAT_005cc7b4,&local_84);
                if ((iVar7 == 0) && (iVar7 = FUN_005654a0(s_FONT1_005cc7ac,&local_84), iVar7 == 0))
                {
                  iVar7 = FUN_005654a0(s_FONT2_005cc7a4,&local_84);
                  if (iVar7 == 0) {
                    iVar7 = FUN_005654a0(s_FONT3_005cc794,&local_84);
                    if (iVar7 == 0) {
                      iVar7 = FUN_00565520(s_FRAME_005cc78c,&local_84,0);
                      if (iVar7 != 0) {
                        FUN_00493990(uVar3,0);
                      }
                    }
                    else {
                      FUN_00497ec0(&local_84);
                      puVar6 = (undefined1 *)FUN_00587c20(&local_84,&DAT_005cc79c);
                      if (puVar6 != (undefined1 *)0x0) {
                        *puVar6 = 0;
                      }
                      FUN_00499ea0(&local_84);
                    }
                  }
                  else {
                    FUN_00497ec0(&local_84);
                    puVar6 = (undefined1 *)FUN_00587c20(&local_84,&DAT_005cc79c);
                    if (puVar6 != (undefined1 *)0x0) {
                      *puVar6 = 0;
                    }
                    FUN_00499e90(&local_84);
                  }
                }
                else {
                  FUN_00497ec0(&local_84);
                  puVar6 = (undefined1 *)FUN_00587c20(&local_84,&DAT_005cc79c);
                  if (puVar6 != (undefined1 *)0x0) {
                    *puVar6 = 0;
                  }
                  FUN_00499e80(&local_84);
                }
              }
              else {
                FUN_0049adc0(local_8c,local_90);
              }
            }
            else {
              uVar4 = __ftol();
              uVar5 = __ftol(uVar4);
              FUN_0049ae40(0,uVar5,uVar4);
              uVar4 = __ftol();
              uVar5 = __ftol(uVar4);
              FUN_0049ae40(1,uVar5,uVar4);
            }
          }
          else {
            uVar4 = __ftol();
            uVar5 = __ftol(uVar4);
            FUN_00499eb0(uVar5,uVar4);
          }
        }
        else {
          FUN_00499e30(&local_84);
LAB_0049316e:
          FUN_00497d20(&local_84);
        }
        iVar7 = FUN_00491fb0();
      } while( true );
    }
  }
  return 0xffffffff;
}


