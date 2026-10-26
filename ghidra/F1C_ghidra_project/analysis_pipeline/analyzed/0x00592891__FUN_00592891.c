// Function: FUN_00592891 @ 00592891
// Size (bytes): 147


undefined4 FUN_00592891(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  if (DAT_008d4a20 <= param_1) {
LAB_00592912:
    puVar4 = (undefined4 *)FUN_0058afcf();
    *puVar4 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 0x24;
  if ((*(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) goto LAB_00592912;
  FUN_00595a61(param_1);
  if ((*(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + iVar5) & 1) != 0) {
    hFile = (HANDLE)FUN_00595a1f(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    uVar6 = 0;
    if (DVar2 == 0) goto LAB_00592907;
    pDVar3 = (DWORD *)FUN_0058afd8();
    *pDVar3 = DVar2;
  }
  puVar4 = (undefined4 *)FUN_0058afcf();
  *puVar4 = 9;
  uVar6 = 0xffffffff;
LAB_00592907:
  FUN_00595ac0(param_1);
  return uVar6;
}


