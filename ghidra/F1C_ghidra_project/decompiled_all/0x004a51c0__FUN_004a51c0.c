// Function: FUN_004a51c0 @ 004a51c0
// Strings:  [INSTANCE]


void FUN_004a51c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_378;
  int local_374 [7];
  undefined1 local_358 [448];
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180 [96];
  
  FUN_005668b0();
  FUN_00566b20(param_1,1);
  if (local_374[0] == 0) {
    FUN_005668d0();
    return;
  }
  local_378 = 0;
  switch(DAT_007cf884) {
  case 0:
    local_378 = 0x40400000;
    break;
  case 1:
    local_378 = 0x40000000;
    break;
  case 2:
    local_378 = 0x3f800000;
    break;
  case 3:
    local_378 = 0;
  }
  puVar2 = local_180;
  for (iVar1 = 0x60; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  local_198 = 0;
  local_184 = 0;
  local_18c = 0;
  local_188 = 0;
  local_194 = 1;
  iVar1 = FUN_00566cc0(local_180,0x180);
  while (iVar1 != 0) {
    iVar1 = FUN_005651b0();
    if ((iVar1 == 0) && (iVar1 = FUN_00565520(s_INSTANCE_005cd620,local_358,0), iVar1 != 0)) {
      FUN_004a4ed0(local_374,local_358,param_2,local_378);
    }
    iVar1 = FUN_00566cc0(local_180,0x180);
  }
  FUN_00566b90();
  FUN_005668d0();
  return;
}


