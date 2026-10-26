// Function: FUN_00438cc0 @ 00438cc0
// Size (bytes): 222


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00438cc0(int param_1)

{
  char cVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x72) = (undefined1)DAT_007ce6f4;
  *(undefined1 *)(param_1 + 0x73) = (undefined1)DAT_007ce73c;
  *(undefined1 *)(param_1 + 0x74) = (undefined1)DAT_007ce7f0;
  *(undefined1 *)(param_1 + 0x75) = (undefined1)DAT_007ce8a4;
  *(undefined1 *)(param_1 + 0x76) = (undefined1)DAT_007ce850;
  *(undefined1 *)(param_1 + 0x77) = (undefined1)DAT_007ce784;
  *(undefined1 *)(param_1 + 0x78) = (undefined1)DAT_007ce7cc;
  *(undefined1 *)(param_1 + 0x79) = (undefined1)DAT_007ce6ac;
  *(undefined1 *)(param_1 + 0x7a) = (undefined1)DAT_007ce718;
  *(undefined1 *)(param_1 + 0x7b) = (undefined1)DAT_007ce760;
  *(undefined1 *)(param_1 + 0x7c) = (undefined1)DAT_007ce7a8;
  if (DAT_007ce874 == '\0') {
    *(uint *)(param_1 + 0x80) = -(uint)(DAT_007ce88c != '\0') & 2;
  }
  else {
    *(uint *)(param_1 + 0x80) = (uint)(DAT_007ce88c != '\0') * 2 + 1;
  }
  iVar2 = 0;
  do {
    cVar1 = FUN_004b15d0(iVar2);
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 0x72 + iVar2) = 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xb);
  if ((*(char *)(param_1 + 0x74) != '\0') || (*(char *)(param_1 + 0x7a) != '\0')) {
    *(undefined1 *)(param_1 + 0x73) = 2;
  }
  if (*(char *)(param_1 + 0x75) != '\0') {
    *(undefined1 *)(param_1 + 0x76) = 1;
  }
  *(double *)(param_1 + 0x9c) = (double)(_DAT_007ce934 * (float)_DAT_0059eb98);
  return;
}


