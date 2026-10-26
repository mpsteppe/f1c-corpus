// Function: FUN_004b8940 @ 004b8940
// Size (bytes): 414


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004b8940(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  float local_14;
  undefined4 *local_10;
  undefined4 local_c;
  int local_8;
  int local_4;
  
  *(undefined1 *)(param_1 + 0xf80) = 1;
  fVar2 = DAT_005acd1c * _DAT_0059e8a4;
  local_14 = 0.0;
  local_4 = param_1;
  FUN_00408450(fVar2);
  fVar3 = DAT_0059e440;
  while (fVar3 < fVar2) {
    local_c = 1;
    FUN_004b8ae0(&local_c);
    local_14 = (float)_DAT_008afe90 + local_14;
    fVar3 = local_14;
  }
  *(undefined1 *)(param_1 + 0xf80) = 1;
  local_c = 1;
  FUN_004b86e0((float)_DAT_008afea0);
  FUN_004b8ae0(&local_c);
  *(undefined1 *)(param_1 + 0xf81) = 0;
  local_8 = DAT_005c329c;
  if (0 < DAT_005c329c) {
    local_10 = (undefined4 *)(param_1 + 0x734);
    iVar4 = -0x93c - param_1;
    puVar6 = (undefined1 *)(param_1 + 0x93c);
    piVar5 = &DAT_007c54f0;
    do {
      iVar1 = *piVar5;
      FUN_004ef5a0(*local_10,0);
      FUN_004e19a0();
      if (*(char *)(iVar1 + 0x105d) != puVar6[-0x68]) {
        *(undefined1 *)(iVar1 + 0x105d) = puVar6[-0x68];
        FUN_004e0ed0(*(undefined4 *)(iVar1 + 0x1054));
      }
      FUN_004e3a50((float)_DAT_008afea0);
      FUN_004c7aa0(*puVar6);
      local_10 = local_10 + 1;
      piVar5 = piVar5 + 1;
      puVar6 = puVar6 + 1;
      param_1 = local_4;
    } while ((int)(puVar6 + iVar4) < local_8);
  }
  FUN_00411120();
  FUN_004c8dc0(0x3f800000);
  FUN_00566db0(*(undefined4 *)(param_1 + 0xf40));
  *(undefined4 *)(param_1 + 0xf40) = 0xffffffff;
  return 1;
}


