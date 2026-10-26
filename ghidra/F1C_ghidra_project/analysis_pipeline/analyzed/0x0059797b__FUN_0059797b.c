// Function: FUN_0059797b @ 0059797b
// Size (bytes): 293


int FUN_0059797b(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  HANDLE hFile;
  BOOL BVar4;
  DWORD DVar5;
  DWORD *pDVar6;
  int iVar7;
  undefined1 local_1008 [4064];
  undefined4 uStackY_28;
  undefined4 uStackY_24;
  undefined4 uStackY_20;
  
  FUN_005881c0();
  iVar7 = 0;
  iVar1 = FUN_0058c789();
  if ((iVar1 == -1) || (iVar1 = FUN_0058c789(), iVar1 == -1)) {
    iVar7 = -1;
  }
  else {
    param_2 = param_2 - iVar1;
    if (param_2 < 1) {
      if (param_2 < 0) {
        uStackY_20 = 0x597a4c;
        FUN_0058c789();
        uStackY_20 = param_1;
        uStackY_24 = 0x597a54;
        hFile = (HANDLE)FUN_00595a1f();
        BVar4 = SetEndOfFile(hFile);
        iVar7 = (BVar4 != 0) - 1;
        if (iVar7 == -1) {
          puVar3 = (undefined4 *)FUN_0058afcf();
          *puVar3 = 0xd;
          DVar5 = GetLastError();
          pDVar6 = (DWORD *)FUN_0058afd8();
          *pDVar6 = DVar5;
        }
      }
    }
    else {
      uStackY_20 = 0x5979db;
      _memset(local_1008,0,0x1000);
      uStackY_20 = 0x8000;
      uStackY_24 = param_1;
      uStackY_28 = 0x5979e8;
      FUN_0059801a();
      do {
        uStackY_20 = 0x597a06;
        iVar1 = FUN_0058e290();
        if (iVar1 == -1) {
          piVar2 = (int *)FUN_0058afd8();
          if (*piVar2 == 5) {
            puVar3 = (undefined4 *)FUN_0058afcf();
            *puVar3 = 0xd;
          }
          iVar7 = -1;
          break;
        }
        param_2 = param_2 - iVar1;
      } while (0 < param_2);
      FUN_0059801a();
    }
    uStackY_20 = 0x597a92;
    FUN_0058c789();
  }
  return iVar7;
}


