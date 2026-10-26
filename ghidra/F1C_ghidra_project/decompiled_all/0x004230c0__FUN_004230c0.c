// Function: FUN_004230c0 @ 004230c0
// Strings:  [Windows 2000, Windows NT, Windows XP, Microsoft Win32s, Windows 98, Windows 95, Windows ME, Unknown]


void FUN_004230c0(int param_1)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  char *pcVar4;
  _OSVERSIONINFOA *p_Var5;
  _OSVERSIONINFOA local_19c;
  char local_100 [256];
  
  iVar2 = 0;
  do {
    cVar1 = s_Unknown_005c307c[iVar2];
    local_100[iVar2] = cVar1;
    iVar2 = iVar2 + 1;
  } while (cVar1 != '\0');
  p_Var5 = &local_19c;
  for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
    p_Var5->dwOSVersionInfoSize = 0;
    p_Var5 = (_OSVERSIONINFOA *)&p_Var5->dwMajorVersion;
  }
  local_19c.dwOSVersionInfoSize = 0x9c;
  BVar3 = GetVersionExA(&local_19c);
  if (BVar3 == 0) {
    local_19c.dwOSVersionInfoSize = 0x94;
    BVar3 = GetVersionExA(&local_19c);
    if (BVar3 == 0) {
      return;
    }
  }
  if (local_19c.dwPlatformId == 0) {
    iVar2 = 0;
    do {
      cVar1 = s_Microsoft_Win32s_005c3044[iVar2];
      local_100[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  else if (local_19c.dwPlatformId == 1) {
    if (3 < local_19c.dwMajorVersion) {
      if (0x59 < local_19c.dwMinorVersion) {
        iVar2 = 0;
        do {
          cVar1 = s_Windows_ME_005c3070[iVar2];
          local_100[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
        goto LAB_00423212;
      }
      if ((4 < local_19c.dwMajorVersion) ||
         ((local_19c.dwMajorVersion == 4 && (local_19c.dwMinorVersion != 0)))) {
        iVar2 = 0;
        do {
          cVar1 = s_Windows_98_005c3058[iVar2];
          local_100[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
        goto LAB_00423212;
      }
    }
    iVar2 = 0;
    do {
      cVar1 = s_Windows_95_005c3064[iVar2];
      local_100[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  else if (local_19c.dwPlatformId == 2) {
    if (local_19c.dwMajorVersion < 5) {
      iVar2 = 0;
      do {
        cVar1 = s_Windows_NT_005c2d90[iVar2];
        local_100[iVar2] = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
    }
    if (4 < local_19c.dwMajorVersion) {
      if (local_19c.dwMinorVersion == 0) {
        iVar2 = 0;
        do {
          cVar1 = s_Windows_2000_005c2d80[iVar2];
          local_100[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
      }
      else {
        iVar2 = 0;
        do {
          cVar1 = s_Windows_XP_005c2d9c[iVar2];
          local_100[iVar2] = cVar1;
          iVar2 = iVar2 + 1;
        } while (cVar1 != '\0');
      }
    }
  }
LAB_00423212:
  if (param_1 != 0) {
    pcVar4 = local_100;
    do {
      cVar1 = *pcVar4;
      pcVar4[param_1 - (int)local_100] = cVar1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  return;
}


