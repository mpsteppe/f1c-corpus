// Function: FUN_00499690 @ 00499690
// Size (bytes): 428


uint __fastcall FUN_00499690(char *param_1)

{
  char cVar1;
  HANDLE in_EAX;
  char *pcVar2;
  BOOL BVar3;
  int iVar4;
  uint uVar5;
  CHAR *pCVar6;
  char *pcVar7;
  bool bVar8;
  bool bVar9;
  _WIN32_FIND_DATAA local_d40;
  char local_c00 [1024];
  undefined1 local_800 [1024];
  char local_400 [1024];
  
  if (param_1 != (char *)0x0) {
    iVar4 = -1;
    in_EAX = (HANDLE)0x0;
    pcVar2 = param_1;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (iVar4 != -2) {
      pcVar2 = param_1;
      do {
        cVar1 = *pcVar2;
        pcVar2[(int)(local_c00 + -(int)param_1)] = cVar1;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      in_EAX = (HANDLE)0x0;
      uVar5 = 0xffffffff;
      pcVar2 = local_c00;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      if ((int)(~uVar5 - 1) < 0x400) {
        if (local_d40.cAlternateFileName[~uVar5 + 0xe] != '\\') {
          iVar4 = -1;
          pcVar2 = local_c00;
          do {
            pcVar7 = pcVar2;
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            pcVar7 = pcVar2 + 1;
            cVar1 = *pcVar2;
            pcVar2 = pcVar7;
          } while (cVar1 != '\0');
          *(undefined2 *)(pcVar7 + -1) = DAT_005c2aac;
        }
        iVar4 = 0;
        do {
          pcVar2 = local_c00 + iVar4;
          local_400[iVar4] = *pcVar2;
          iVar4 = iVar4 + 1;
        } while (*pcVar2 != '\0');
        iVar4 = -1;
        pcVar2 = local_c00;
        do {
          pcVar7 = pcVar2;
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pcVar7 = pcVar2 + 1;
          cVar1 = *pcVar2;
          pcVar2 = pcVar7;
        } while (cVar1 != '\0');
        *(undefined4 *)(pcVar7 + -1) = DAT_005c2ab8;
        in_EAX = FindFirstFileA(local_c00,&local_d40);
        if (in_EAX != (HANDLE)0xffffffff) {
          do {
            FUN_0058815f(local_800,&DAT_005be860,local_400,local_d40.cFileName);
            if (((byte)local_d40.dwFileAttributes & 0x10) == 0) {
              FUN_0058ba36(local_800,0x180);
              iVar4 = FUN_0058986e(local_800);
              if (iVar4 != 0) goto LAB_00499808;
            }
            else {
              iVar4 = 2;
              bVar8 = true;
              pCVar6 = local_d40.cFileName;
              pcVar2 = &DAT_005beb48;
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar8 = *pCVar6 == *pcVar2;
                pCVar6 = pCVar6 + 1;
                pcVar2 = pcVar2 + 1;
              } while (bVar8);
              iVar4 = 3;
              bVar9 = true;
              pCVar6 = local_d40.cFileName;
              pcVar2 = &DAT_005c2ab4;
              do {
                if (iVar4 == 0) break;
                iVar4 = iVar4 + -1;
                bVar9 = *pCVar6 == *pcVar2;
                pCVar6 = pCVar6 + 1;
                pcVar2 = pcVar2 + 1;
              } while (bVar9);
              if (((!bVar9) && (!bVar8)) && (cVar1 = FUN_00499690(), cVar1 == '\0')) {
LAB_00499808:
                in_EAX = (HANDLE)FindClose(in_EAX);
                break;
              }
            }
            BVar3 = FindNextFileA(in_EAX,&local_d40);
            if (BVar3 == 0) {
              FindClose(in_EAX);
              iVar4 = FUN_0059b9f3(param_1);
              return (uint)(iVar4 == 0);
            }
          } while( true );
        }
      }
    }
  }
  return (uint)in_EAX & 0xffffff00;
}


