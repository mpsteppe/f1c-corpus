// Function: FUN_004651c0 @ 004651c0
// Size (bytes): 268


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004651c0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  float10 fVar4;
  float local_8;
  
  fVar4 = (float10)FUN_00568cf0();
  local_8 = (float)fVar4;
  if ((float10)_DAT_0059e600 <= fVar4) {
    if (_DAT_0059e43c < local_8) {
      local_8 = 1.0;
    }
  }
  else {
    local_8 = 0.001;
  }
  FUN_00464ef0(local_8);
  *(float *)(*param_1 + 0x60) = local_8;
  iVar3 = *param_1;
  puVar2 = *(undefined4 **)(iVar3 + 0x6c);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(iVar3 + 0x6c) = 0;
  *(undefined4 *)(iVar3 + 0x70) = 0;
  *(undefined4 *)(iVar3 + 0x74) = 0;
  *(undefined4 *)(iVar3 + 0x78) = 0;
  iVar3 = *param_1;
  puVar2 = *(undefined4 **)(iVar3 + 0x7c);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(iVar3 + 0x7c) = 0;
  *(undefined4 *)(iVar3 + 0x80) = 0;
  *(undefined4 *)(iVar3 + 0x84) = 0;
  *(undefined4 *)(iVar3 + 0x88) = 0;
  iVar3 = 0;
  do {
    *(undefined1 *)(iVar3 + 0xf8 + *param_1) = 0;
    iVar3 = iVar3 + 0x230;
  } while (iVar3 < 0xe380);
  *(undefined4 *)(*param_1 + 0xe40c) = 0;
  return;
}


