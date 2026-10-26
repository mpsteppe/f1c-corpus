// Function: FUN_004fc2f0 @ 004fc2f0
// Strings:  [CLOUDS, CLOUDR]


void __thiscall FUN_004fc2f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_80c;
  int local_804;
  int aiStack_800 [256];
  int aiStack_400 [256];
  
  local_804 = *(int *)(param_2 + 0x118);
  iVar3 = 0;
  iVar2 = 0;
  local_80c = 0;
  if (0 < local_804) {
    do {
      iVar4 = *(int *)(param_2 + 0x128) + iVar3;
      iVar1 = _strncmp((char *)(iVar4 + 0x14),s_CLOUDS_005d6f08,6);
      if ((iVar1 == 0) && (iVar2 < 0x100)) {
        aiStack_800[iVar2] = iVar4;
        iVar2 = iVar2 + 1;
      }
      iVar1 = _strncmp((char *)(iVar4 + 0x14),s_CLOUDR_005d6f30,6);
      if ((iVar1 == 0) && (local_80c < 0x100)) {
        aiStack_400[local_80c] = iVar4;
        local_80c = local_80c + 1;
      }
      iVar3 = iVar3 + 0x100;
      local_804 = local_804 + -1;
    } while (local_804 != 0);
    if (0 < iVar2) {
      iVar3 = _rand();
      _strncpy((char *)(param_1 + 0x50),(char *)(aiStack_800[iVar3 % iVar2] + 0x14),0x1f);
      *(undefined1 *)(param_1 + 0x6f) = 0;
    }
    if (0 < local_80c) {
      iVar2 = _rand();
      _strncpy((char *)(param_1 + 0x84),(char *)(aiStack_400[iVar2 % local_80c] + 0x14),0x1f);
      *(undefined1 *)(param_1 + 0xa3) = 0;
    }
  }
  return;
}


