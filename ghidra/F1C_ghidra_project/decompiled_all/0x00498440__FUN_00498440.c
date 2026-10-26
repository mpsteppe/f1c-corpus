// Function: FUN_00498440 @ 00498440
// Strings:  [Error, Error, Specified system font "%s" not found, using "%s" instead, Cannot set system font with no fonts loaded!]


void __thiscall FUN_00498440(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  HWND pHVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  CHAR *lpText;
  char *pcVar7;
  UINT UVar8;
  CHAR local_80 [128];
  
  if (param_2 != (char *)0x0) {
    iVar4 = -1;
    pcVar6 = param_2;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      FUN_00497ec0(param_2);
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x1514)) {
        iVar5 = param_1 + 0x114;
        do {
          iVar2 = FUN_00588410(iVar5,param_2);
          if (iVar2 == 0) {
            iVar4 = (param_1 + 0x166c) - (int)param_2;
            do {
              cVar1 = *param_2;
              param_2[iVar4] = cVar1;
              param_2 = param_2 + 1;
            } while (cVar1 != '\0');
            return;
          }
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x50;
        } while (iVar4 < *(int *)(param_1 + 0x1514));
        if (0 < *(int *)(param_1 + 0x1514)) {
          pcVar6 = (char *)(param_1 + 0x114);
          FUN_0058815f(local_80,s_Specified_system_font___s__not_f_005cca78,param_2,pcVar6);
          UVar8 = 0;
          pcVar7 = s_Error_005cc970;
          lpText = local_80;
          pHVar3 = GetDesktopWindow();
          MessageBoxA(pHVar3,lpText,pcVar7,UVar8);
          iVar4 = (param_1 + 0x166c) - (int)pcVar6;
          do {
            cVar1 = *pcVar6;
            pcVar6[iVar4] = cVar1;
            pcVar6 = pcVar6 + 1;
          } while (cVar1 != '\0');
          return;
        }
      }
      UVar8 = 0;
      pcVar7 = s_Error_005cc970;
      pcVar6 = s_Cannot_set_system_font_with_no_f_005ccab4;
      pHVar3 = GetDesktopWindow();
      MessageBoxA(pHVar3,pcVar6,pcVar7,UVar8);
      return;
    }
  }
  return;
}


