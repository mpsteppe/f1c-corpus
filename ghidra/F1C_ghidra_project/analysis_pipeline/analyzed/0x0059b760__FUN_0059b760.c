// Function: FUN_0059b760 @ 0059b760
// Size (bytes): 659


undefined4 FUN_0059b760(uint param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  BOOL BVar5;
  uint uVar6;
  int iVar7;
  _BY_HANDLE_FILE_INFORMATION local_54;
  _SYSTEMTIME local_20;
  _FILETIME local_10;
  undefined4 local_8;
  
  local_8 = 0;
  if (DAT_008d4a20 <= param_1) {
LAB_0059b9e1:
    puVar4 = (undefined4 *)FUN_0058afcf();
    *puVar4 = 9;
    return 0xffffffff;
  }
  piVar1 = &DAT_008d4920 + ((int)param_1 >> 5);
  iVar7 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)(*piVar1 + 4 + iVar7) & 1) == 0) goto LAB_0059b9e1;
  FUN_00595a61(param_1);
  DVar3 = GetFileType(*(HANDLE *)(*piVar1 + iVar7));
  puVar2 = param_2;
  uVar6 = DVar3 & 0xffff7fff;
  if (uVar6 != 1) {
    if (uVar6 == 2) {
      *(undefined2 *)((int)param_2 + 6) = 0x2000;
    }
    else {
      if (uVar6 != 3) {
        if (uVar6 == 0) {
          puVar4 = (undefined4 *)FUN_0058afcf();
          *puVar4 = 9;
          goto LAB_0059b7db;
        }
        goto LAB_0059b887;
      }
      *(undefined2 *)((int)param_2 + 6) = 0x1000;
    }
    *(undefined2 *)(param_2 + 2) = 1;
    *param_2 = param_1;
    param_2[4] = param_1;
    *(undefined2 *)(param_2 + 1) = 0;
    *(undefined2 *)(param_2 + 3) = 0;
    *(undefined2 *)((int)param_2 + 10) = 0;
    param_2[8] = 0;
    param_2[7] = 0;
    param_2[6] = 0;
    if (uVar6 == 2) {
      param_2[5] = 0;
    }
    else {
      BVar5 = PeekNamedPipe(*(HANDLE *)(*piVar1 + iVar7),(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPDWORD)&param_2,(LPDWORD)0x0);
      if (BVar5 == 0) {
        puVar2[5] = 0;
      }
      else {
        puVar2[5] = (uint)param_2;
      }
    }
    goto LAB_0059b7df;
  }
  *(undefined2 *)((int)param_2 + 6) = 0;
  *(undefined2 *)(param_2 + 3) = 0;
  *(undefined2 *)((int)param_2 + 10) = 0;
  *(undefined2 *)(param_2 + 1) = 0;
  *(undefined2 *)(param_2 + 2) = 1;
  BVar5 = GetFileInformationByHandle(*(HANDLE *)(*piVar1 + iVar7),&local_54);
  if (BVar5 == 0) {
LAB_0059b887:
    DVar3 = GetLastError();
    FUN_0058af5c(DVar3);
  }
  else {
    if (((byte)local_54.dwFileAttributes & 1) == 0) {
      *(ushort *)((int)puVar2 + 6) = *(ushort *)((int)puVar2 + 6) | 0x1b6;
    }
    else {
      *(ushort *)((int)puVar2 + 6) = *(ushort *)((int)puVar2 + 6) | 0x124;
    }
    BVar5 = FileTimeToLocalFileTime(&local_54.ftLastWriteTime,&local_10);
    if ((BVar5 != 0) && (BVar5 = FileTimeToSystemTime(&local_10,&local_20), BVar5 != 0)) {
      uVar6 = FUN_00591edf(local_20.wYear,local_20.wMonth,local_20.wDay,local_20.wHour,
                           local_20.wMinute,local_20.wSecond,0xffffffff);
      puVar2[7] = uVar6;
      if ((local_54.ftLastAccessTime.dwLowDateTime == 0) &&
         (local_54.ftLastAccessTime.dwHighDateTime == 0)) {
LAB_0059b965:
        puVar2[6] = uVar6;
        if ((local_54.ftCreationTime.dwLowDateTime == 0) &&
           (local_54.ftCreationTime.dwHighDateTime == 0)) {
          uVar6 = puVar2[7];
        }
        else {
          BVar5 = FileTimeToLocalFileTime(&local_54.ftCreationTime,&local_10);
          if ((BVar5 == 0) || (BVar5 = FileTimeToSystemTime(&local_10,&local_20), BVar5 == 0))
          goto LAB_0059b9d9;
          uVar6 = FUN_00591edf(local_20.wYear,local_20.wMonth,local_20.wDay,local_20.wHour,
                               local_20.wMinute,local_20.wSecond,0xffffffff);
        }
        *(byte *)((int)puVar2 + 7) = *(byte *)((int)puVar2 + 7) | 0x80;
        puVar2[8] = uVar6;
        *puVar2 = 0;
        puVar2[5] = local_54.nFileSizeLow;
        puVar2[4] = 0;
      }
      else {
        BVar5 = FileTimeToLocalFileTime(&local_54.ftLastAccessTime,&local_10);
        if ((BVar5 != 0) && (BVar5 = FileTimeToSystemTime(&local_10,&local_20), BVar5 != 0)) {
          uVar6 = FUN_00591edf(local_20.wYear,local_20.wMonth,local_20.wDay,local_20.wHour,
                               local_20.wMinute,local_20.wSecond,0xffffffff);
          goto LAB_0059b965;
        }
LAB_0059b9d9:
        local_8 = 0xffffffff;
      }
      goto LAB_0059b7df;
    }
  }
LAB_0059b7db:
  local_8 = 0xffffffff;
LAB_0059b7df:
  FUN_00595ac0(param_1);
  return local_8;
}


