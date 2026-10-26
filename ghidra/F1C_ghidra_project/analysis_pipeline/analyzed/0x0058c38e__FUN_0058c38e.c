// Function: FUN_0058c38e @ 0058c38e
// Size (bytes): 131


undefined4 FUN_0058c38e(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_00595a1f(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_00595a1f(2);
      iVar2 = FUN_00595a1f(1);
      if (iVar2 == iVar1) goto LAB_0058c3dc;
    }
    hObject = (HANDLE)FUN_00595a1f(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_0058c3de;
    }
  }
LAB_0058c3dc:
  DVar4 = 0;
LAB_0058c3de:
  FUN_005959a0(param_1);
  *(undefined1 *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_0058af5c(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


