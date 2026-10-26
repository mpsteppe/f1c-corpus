// Function: FUN_00565f80 @ 00565f80
// Strings:  [%s\%s]


void __thiscall
FUN_00565f80(int *param_1,LPCSTR param_2,undefined4 param_3,char *param_4,undefined1 param_5)

{
  char cVar1;
  bool bVar2;
  undefined1 *puVar3;
  HANDLE pvVar4;
  BOOL BVar5;
  int iVar6;
  uint uVar7;
  CHAR *pCVar8;
  char *pcVar9;
  undefined4 *puVar10;
  char *pcVar11;
  bool bVar12;
  _WIN32_FIND_DATAA local_640;
  CHAR local_500;
  undefined4 local_4ff;
  CHAR local_400;
  undefined4 local_3ff;
  char acStack_302 [2];
  CHAR local_300;
  undefined4 uStack_2ff;
  
  local_500 = DAT_005ea438;
  puVar10 = &local_4ff;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  *(undefined2 *)puVar10 = 0;
  *(undefined1 *)((int)puVar10 + 2) = 0;
  local_400 = DAT_005ea438;
  puVar10 = &local_3ff;
  for (iVar6 = 0x3f; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar10 = 0;
    puVar10 = puVar10 + 1;
  }
  *(undefined2 *)puVar10 = 0;
  *(undefined1 *)((int)puVar10 + 2) = 0;
  if (param_4 == (char *)0x0) {
    param_4 = &DAT_005beb48;
  }
  bVar2 = false;
  iVar6 = _strncmp(param_4,&DAT_005e5160,2);
  if ((iVar6 == 0) || (iVar6 = FUN_00587c20(param_4,&DAT_005c3f6c), iVar6 != 0)) {
    bVar2 = true;
  }
  if (*(int *)(*param_1 + 0x21c) == 0) {
    FUN_00565eb0();
    *(undefined1 *)(*param_1 + 0x218) = param_5;
    if ((*(char *)(*param_1 + 0x218) != '\0') && (param_4 != (char *)0x0)) {
      FUN_00566650(param_4);
      puVar3 = *(undefined1 **)(*param_1 + 0x210);
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      FUN_00589901(puVar3);
    }
  }
  *(int *)(*param_1 + 0x21c) = *(int *)(*param_1 + 0x21c) + 1;
  iVar6 = FUN_0058b903(&local_500,0xff);
  if ((iVar6 != 0) && (iVar6 = FUN_0059ba1d(param_4), iVar6 != -1)) {
    if ((char)param_3 != '\0') {
      FUN_0058815f(&local_400,&DAT_005c2ab8);
      pvVar4 = FindFirstFileA(&local_400,&local_640);
      if (pvVar4 != (HANDLE)0xffffffff) {
        do {
          if (((byte)local_640.dwFileAttributes & 0x10) != 0) {
            iVar6 = 2;
            bVar12 = true;
            pCVar8 = local_640.cFileName;
            pcVar9 = &DAT_005beb48;
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar12 = *pCVar8 == *pcVar9;
              pCVar8 = pCVar8 + 1;
              pcVar9 = pcVar9 + 1;
            } while (bVar12);
            if (!bVar12) {
              iVar6 = 3;
              bVar12 = true;
              pCVar8 = local_640.cFileName;
              pcVar9 = &DAT_005c2ab4;
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar12 = *pCVar8 == *pcVar9;
                pCVar8 = pCVar8 + 1;
                pcVar9 = pcVar9 + 1;
              } while (bVar12);
              if (!bVar12) {
                FUN_00565f80(param_2,param_3,local_640.cFileName,0);
              }
            }
          }
          BVar5 = FindNextFileA(pvVar4,&local_640);
        } while (BVar5 != 0);
        FindClose(pvVar4);
      }
    }
    pvVar4 = FindFirstFileA(param_2,&local_640);
    if (pvVar4 != (HANDLE)0xffffffff) {
      do {
        if (((byte)local_640.dwFileAttributes & 0x10) == 0) {
          local_300 = DAT_005ea438;
          puVar10 = &uStack_2ff;
          for (iVar6 = 0xbf; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar10 = 0;
            puVar10 = puVar10 + 1;
          }
          *(undefined2 *)puVar10 = 0;
          *(undefined1 *)((int)puVar10 + 2) = 0;
          if (bVar2) {
            FUN_0058815f(acStack_302 + 2,&DAT_005c2c18,param_4);
          }
          else {
            iVar6 = 2;
            bVar12 = true;
            pcVar9 = param_4;
            pcVar11 = &DAT_005beb48;
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar12 = *pcVar9 == *pcVar11;
              pcVar9 = pcVar9 + 1;
              pcVar11 = pcVar11 + 1;
            } while (bVar12);
            if (bVar12) {
              FUN_0058815f(acStack_302 + 2,&DAT_005c2c18,&local_500);
            }
            else {
              FUN_0058815f(acStack_302 + 2,s__s__s_005c2d64,&local_500,param_4);
            }
          }
          uVar7 = 0xffffffff;
          pcVar9 = acStack_302 + 2;
          do {
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            cVar1 = *pcVar9;
            pcVar9 = pcVar9 + 1;
          } while (cVar1 != '\0');
          if ((0 < (int)(~uVar7 - 1)) && (acStack_302[~uVar7] != '\\')) {
            iVar6 = -1;
            pcVar9 = acStack_302 + 2;
            do {
              pcVar11 = pcVar9;
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              pcVar11 = pcVar9 + 1;
              cVar1 = *pcVar9;
              pcVar9 = pcVar11;
            } while (cVar1 != '\0');
            *(undefined2 *)(pcVar11 + -1) = DAT_005c2aac;
          }
          FUN_00565ca0(&local_640,acStack_302 + 2);
        }
        BVar5 = FindNextFileA(pvVar4,&local_640);
      } while (BVar5 != 0);
      FindClose(pvVar4);
    }
    FUN_0059ba1d(&local_500);
    *(int *)(*param_1 + 0x21c) = *(int *)(*param_1 + 0x21c) + -1;
    if (*(int *)(*param_1 + 0x21c) == 0) {
      FUN_00565f50();
    }
  }
  return;
}


