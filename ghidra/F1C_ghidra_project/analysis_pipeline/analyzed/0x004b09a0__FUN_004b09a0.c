// Function: FUN_004b09a0 @ 004b09a0
// Size (bytes): 360


undefined4 __thiscall FUN_004b09a0(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint _Count;
  char *pcVar6;
  undefined4 uVar7;
  char local_600 [1536];
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  FUN_004b0180(param_2,param_1 + 0x14);
  FUN_00568620(0x200);
  uVar5 = 0xffffffff;
  _Count = 0;
  pcVar6 = local_600;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar5 - 1)) {
    do {
      if (0x3ff < _Count) break;
      if (local_600[_Count] == '\\') {
        _strncpy(local_600 + 0x200,local_600,_Count);
        local_600[_Count + 0x200] = '\0';
        FUN_00589671(local_600 + 0x200);
      }
      _Count = _Count + 1;
    } while ((int)_Count < (int)(~uVar5 - 1));
  }
  FUN_00589671(local_600);
  FUN_004b01b0(param_2,param_1 + 0x14);
  if ((DAT_007cb710 & 1) == 0) {
    uVar7 = 1;
  }
  else {
    uVar7 = 2;
  }
  FUN_004ae750(uVar7);
  if (0 < DAT_008ac488) {
    FUN_004c54f0(param_1);
  }
  if (0 < DAT_008ac390) {
    puVar2 = (undefined4 *)FUN_004c4080();
    puVar3 = (undefined1 *)*puVar2;
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00566650(puVar3);
    iVar4 = FUN_004c4080();
    FUN_00566650(iVar4 + 0xbc);
    puVar3 = *(undefined1 **)(param_1 + 0x1b4);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_00415730(puVar3);
  }
  FUN_004add50();
  FUN_004ade20(1);
  FUN_004331a0();
  FUN_004b0770(1);
  return 0;
}


