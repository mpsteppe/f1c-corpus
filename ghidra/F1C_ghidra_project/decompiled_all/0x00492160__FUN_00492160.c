// Function: FUN_00492160 @ 00492160
// Strings:  [DISABLE_GIZMO, SET_SYMBOL, TOOLTIP_COLOR_EDGE, TOOLTIP_COLOR_FILL, TOOLTIPFONT, SYSTEMFONT, LOADINGSCREENPAGE, DOPAGE]


undefined4 __fastcall FUN_00492160(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined2 local_84;
  undefined1 local_82;
  char local_80;
  undefined4 local_7f;
  
  if (*(int *)(param_1 + 0x1a4) == 0) {
    pcVar7 = s_Invalid_Options_Pointer_in_Optio_005cc5e8;
    pcVar3 = &local_80;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar3 = pcVar3 + 4;
    }
    *(undefined2 *)pcVar3 = *(undefined2 *)pcVar7;
    pcVar3[2] = pcVar7[2];
    FUN_00493c80(3,&local_80);
    return 0;
  }
  if (*(char *)(param_1 + 0x19a) != '\0') {
    FUN_00493e20(s_Options_Screens_Hierarchy_005cc5cc);
  }
  iVar6 = FUN_00491fb0();
  while (iVar6 != 0) {
    puVar8 = &local_7f;
    for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    *(undefined2 *)puVar8 = 0;
    *(undefined1 *)((int)puVar8 + 2) = 0;
    local_80 = DAT_005ea438;
    iVar6 = FUN_005654a0(s_ATTRIBUTESET_005cc5bc,&local_80);
    if (iVar6 == 0) {
      iVar6 = FUN_005654a0(s_LAYER_005cc5b4,&local_80);
      if (iVar6 == 0) {
        iVar6 = FUN_005654a0(s_GIZMO_005cc5ac,&local_80);
        if (iVar6 == 0) {
          iVar6 = FUN_005654a0(s_DOPAGE_005cc5a4,&local_80);
          if (iVar6 == 0) {
            iVar6 = FUN_005654a0(s_LOADINGSCREENPAGE_005cc590,&local_80);
            if (iVar6 == 0) {
              iVar6 = FUN_005654a0(s_SYSTEMFONT_005cc584,&local_80);
              if (iVar6 == 0) {
                iVar6 = FUN_005654a0(s_TOOLTIPFONT_005cc578,&local_80);
                if (iVar6 == 0) {
                  iVar6 = FUN_00565760(s_TOOLTIP_COLOR_FILL_005cc564,
                                       *(int *)(param_1 + 0x1a4) + 0xb4,0,0,0);
                  if ((iVar6 == 0) &&
                     (iVar6 = FUN_00565760(s_TOOLTIP_COLOR_EDGE_005cc550,
                                           *(int *)(param_1 + 0x1a4) + 0xb8,0,0,0), iVar6 == 0)) {
                    iVar6 = FUN_005654a0(s_SET_SYMBOL_005cc544,&local_80);
                    if (iVar6 == 0) {
                      iVar6 = FUN_005654a0(s_DISABLE_GIZMO_005cc530,&local_80);
                      if ((iVar6 != 0) &&
                         (piVar5 = (int *)FUN_00497750(&local_80), piVar5 != (int *)0x0)) {
                        (**(code **)(*piVar5 + 0x38))(1);
                      }
                    }
                    else {
                      local_84 = DAT_005cc540;
                      local_82 = DAT_005cc542;
                      iVar6 = FUN_005897ca(&local_80,&local_84);
                      iVar4 = FUN_005897ca(0,&local_84);
                      if ((iVar6 != 0) && (iVar4 != 0)) {
                        FUN_0049a490(iVar6,iVar4);
                      }
                    }
                  }
                }
                else {
                  pcVar7 = &local_80;
                  pcVar3 = (char *)(*(int *)(param_1 + 0x1a4) + 0x1538);
                  do {
                    cVar1 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                    *pcVar3 = cVar1;
                    pcVar3 = pcVar3 + 1;
                  } while (cVar1 != '\0');
                }
              }
              else {
                FUN_00498440(&local_80);
              }
            }
            else {
              iVar6 = FUN_004976c0(&local_80);
              if (iVar6 != 0) {
                FUN_004980c0(iVar6);
              }
            }
          }
          else {
            uVar2 = FUN_004976c0(&local_80);
            FUN_00497890(uVar2,0xffffffff);
          }
        }
        else {
          iVar6 = FUN_00492a40(&local_80);
          if (iVar6 != 0) {
            FUN_004975d0(iVar6,0);
          }
        }
      }
      else {
        FUN_00492460(&local_80);
      }
    }
    else {
      FUN_00493060(&local_80);
    }
    iVar6 = FUN_00491fb0();
  }
  return 0;
}


