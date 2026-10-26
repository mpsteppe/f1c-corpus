// Function: FUN_0046bf10 @ 0046bf10
// Size (bytes): 274


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046bf10(char param_1)

{
  float fVar1;
  char cVar2;
  char local_369;
  float local_368;
  
  FUN_004be6f0();
  local_369 = '\0';
  FUN_004c8d80();
  if (0 < DAT_007c56a4) {
    if (DAT_007c56a4 < 7) {
      local_368 = _DAT_008acf94 - _DAT_008acf90;
    }
    else if (DAT_007c56a4 == 7) {
      local_368 = 1e+09;
    }
  }
  FUN_004988c0(0);
  fVar1 = local_368;
  cVar2 = FUN_004beb10(&local_369,local_368);
  while ((cVar2 != '\0' && (local_369 == '\0'))) {
    FUN_004a1830();
    if (param_1 != '\0') {
      FUN_00496880();
      FUN_00497250(1);
      FUN_00496e90(1);
    }
    cVar2 = FUN_004beb10(&local_369,fVar1);
  }
  if (DAT_007c56a4 == 7) {
    if (DAT_005eb10c != (int *)0x0) {
      (**(code **)(*DAT_005eb10c + 0xc))();
    }
    FUN_004186a0();
    FUN_0041d630();
  }
  FUN_004988c0(1);
  FUN_00497250(1);
  FUN_004b0170();
  return;
}


