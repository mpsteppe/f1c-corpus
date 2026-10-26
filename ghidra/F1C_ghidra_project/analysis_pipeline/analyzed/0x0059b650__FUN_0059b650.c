// Function: FUN_0059b650 @ 0059b650
// Size (bytes): 264


uint FUN_0059b650(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceHandle;
  HANDLE hSourceProcessHandle;
  int iVar4;
  HANDLE *lpTargetHandle;
  DWORD DVar5;
  BOOL BVar6;
  DWORD dwOptions;
  HANDLE local_8;
  
  if (param_1 < DAT_008d4a20) {
    iVar4 = (param_1 & 0x1f) * 0x24;
    if ((*(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
      FUN_00595a61(param_1);
      bVar1 = *(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + iVar4);
      uVar2 = FUN_00595801();
      if (uVar2 == 0xffffffff) {
        puVar3 = (undefined4 *)FUN_0058afcf();
        *puVar3 = 0x18;
        puVar3 = (undefined4 *)FUN_0058afd8();
        *puVar3 = 0;
        FUN_00595ac0(param_1);
        return 0xffffffff;
      }
      dwOptions = 2;
      BVar6 = 1;
      lpTargetHandle = &local_8;
      DVar5 = 0;
      hTargetProcessHandle = GetCurrentProcess();
      hSourceHandle = (HANDLE)FUN_00595a1f(param_1);
      hSourceProcessHandle = GetCurrentProcess();
      BVar6 = DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle
                              ,DVar5,BVar6,dwOptions);
      if (BVar6 == 0) {
        DVar5 = GetLastError();
      }
      else {
        FUN_00595924(uVar2,local_8);
        DVar5 = 0;
      }
      FUN_00595ac0(uVar2);
      FUN_00595ac0(param_1);
      if (DVar5 != 0) {
        FUN_0058af5c(DVar5);
        return 0xffffffff;
      }
      *(byte *)((&DAT_008d4920)[(int)uVar2 >> 5] + 4 + (uVar2 & 0x1f) * 0x24) = bVar1 & 0xef;
      return uVar2;
    }
  }
  puVar3 = (undefined4 *)FUN_0058afcf();
  *puVar3 = 9;
  puVar3 = (undefined4 *)FUN_0058afd8();
  *puVar3 = 0;
  return 0xffffffff;
}


