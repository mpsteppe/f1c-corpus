// Function: FUN_005932f3 @ 005932f3
// Strings:  [Microsoft Visual C++ Runtime Library, <program name unknown>]


void FUN_005932f3(DWORD param_1)

{
  undefined4 *puVar1;
  DWORD *pDVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  int iVar5;
  char acStackY_1e3 [7];
  undefined1 *puStackY_1dc;
  char *pcStackY_1d8;
  undefined4 uStackY_1d4;
  undefined1 *puStackY_1d0;
  undefined4 uStackY_1cc;
  undefined1 *puStackY_1c8;
  undefined *puStackY_1c4;
  LPCVOID lpBuffer;
  LPDWORD lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  CHAR local_1a8 [260];
  undefined1 local_a4 [160];
  
  iVar5 = 0;
  pDVar2 = &DAT_005e78c0;
  do {
    if (param_1 == *pDVar2) break;
    pDVar2 = pDVar2 + 2;
    iVar5 = iVar5 + 1;
  } while ((int)pDVar2 < 0x5e7950);
  if (param_1 == (&DAT_005e78c0)[iVar5 * 2]) {
    if ((DAT_008d3ebc == 1) || ((DAT_008d3ebc == 0 && (DAT_005e65b4 == 1)))) {
      lpNumberOfBytesWritten = &param_1;
      puVar1 = (undefined4 *)(iVar5 * 8 + 0x5e78c4);
      lpOverlapped = (LPOVERLAPPED)0x0;
      sVar4 = _strlen((char *)*puVar1);
      lpBuffer = (LPCVOID)*puVar1;
      puStackY_1c4 = (undefined *)0x59343c;
      hFile = GetStdHandle(0xfffffff4);
      puStackY_1c4 = (undefined *)0x593443;
      WriteFile(hFile,lpBuffer,sVar4,lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar3 = GetModuleFileNameA((HMODULE)0x0,local_1a8,0x104);
      if (DVar3 == 0) {
        FUN_0058fca0();
      }
      sVar4 = _strlen(local_1a8);
      if (0x3c < sVar4 + 1) {
        sVar4 = _strlen(local_1a8);
        puStackY_1c4 = (undefined *)0x5933bd;
        _strncpy(acStackY_1e3 + sVar4,&DAT_005c5c8c,3);
      }
      FUN_0058fca0();
      puStackY_1c4 = (undefined *)0x5933de;
      FUN_0058fcb0();
      puStackY_1c8 = local_a4;
      puStackY_1c4 = &DAT_005b9908;
      uStackY_1cc = 0x5933ef;
      FUN_0058fcb0();
      uStackY_1cc = *(undefined4 *)(iVar5 * 8 + 0x5e78c4);
      puStackY_1d0 = local_a4;
      uStackY_1d4 = 0x593401;
      FUN_0058fcb0();
      uStackY_1d4 = 0x12010;
      puStackY_1dc = local_a4;
      pcStackY_1d8 = "Microsoft Visual C++ Runtime Library";
      builtin_strncpy(acStackY_1e3 + 3,"\x174Y",4);
      FUN_00597234();
    }
  }
  return;
}


