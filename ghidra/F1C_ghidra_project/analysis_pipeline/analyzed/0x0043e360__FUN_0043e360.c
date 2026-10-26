// Function: FUN_0043e360 @ 0043e360
// Size (bytes): 325


void __fastcall FUN_0043e360(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_24;
  undefined4 local_20 [7];
  
  iVar3 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  if (0 < *(int *)(param_1 + 0x15ac)) {
    local_24 = 0;
    do {
      puVar1 = local_20;
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x15b0) + local_24 + 100);
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar4 = puVar4 + 1;
      }
      FUN_00569280(local_20);
      iVar3 = iVar3 + 1;
      local_24 = local_24 + 0x244;
    } while (iVar3 < *(int *)(param_1 + 0x15ac));
  }
  puVar1 = (undefined4 *)(param_1 + 0x348);
  iVar3 = 4;
  do {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1 = puVar1 + 0x119;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(param_1 + 0x1f04) = 0;
  *(undefined4 *)(param_1 + 0x1f08) = 0;
  *(undefined4 *)(param_1 + 0x1f0c) = 0;
  *(undefined4 *)(param_1 + 0x1f10) = 0;
  *(undefined4 *)(param_1 + 0x1f14) = 0;
  *(undefined4 *)(param_1 + 0x1f18) = 0;
  *(undefined4 *)(param_1 + 0x1f1c) = 0;
  *(undefined4 *)(param_1 + 0x1f20) = 0;
  *(undefined4 *)(param_1 + 0x1f24) = 0;
  *(undefined4 *)(param_1 + 0x1f28) = 0;
  *(undefined4 *)(param_1 + 0x1f2c) = 0;
  *(undefined4 *)(param_1 + 0x1f30) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  return;
}


