// Function: FUN_00564dd0 @ 00564dd0
// Size (bytes): 310


uint __fastcall FUN_00564dd0(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = 0;
  uVar3 = 0x8000;
  iVar2 = 1;
  *(undefined4 *)(param_1 + 0x4c0) = 0;
  uVar4 = param_2;
  do {
    uVar1 = uVar1 + uVar4 + iVar2;
    uVar4 = uVar4 + iVar2 + uVar1;
    if ((param_3 & uVar3) == 0) {
      *(uint *)(param_1 + 0x400 + *(int *)(param_1 + 0x4c0) * 4) = uVar4;
      *(uint *)(param_1 + 0x440 + *(int *)(param_1 + 0x4c0) * 4) = uVar1;
      *(int *)(param_1 + 0x480 + *(int *)(param_1 + 0x4c0) * 4) = iVar2;
      *(int *)(param_1 + 0x4c0) = *(int *)(param_1 + 0x4c0) + 1;
      uVar4 = uVar4 ^ *(uint *)(param_1 + (uVar4 & 0xff) * 4);
      uVar1 = (uVar1 * 0x1000000 | uVar1 >> 8) ^ *(uint *)(param_1 + (uVar1 >> 8 & 0xff) * 4);
      uVar5 = uVar1 >> 8;
      uVar6 = uVar4 >> 0x18;
      uVar4 = (uVar6 | uVar4 << 8) ^ *(uint *)(param_1 + uVar6 * 4);
      uVar1 = (uVar1 << 0x18 | uVar5) ^ *(uint *)(param_1 + (uVar5 & 0xff) * 4);
      uVar4 = uVar4 >> 0x18 | uVar4 << 8;
      iVar2 = iVar2 * 2;
    }
    else {
      iVar2 = iVar2 * 2 + 1;
      uVar5 = ~uVar4 >> 8;
      uVar4 = (~uVar4 << 0x18 | uVar5) ^ *(uint *)(param_1 + (uVar5 & 0xff) * 4);
      uVar1 = uVar1 ^ *(uint *)(param_1 + (uVar1 & 0xff) * 4);
      uVar5 = uVar4 >> 8;
      uVar6 = uVar1 >> 0x18;
      uVar4 = (uVar4 << 0x18 | uVar5) ^ *(uint *)(param_1 + (uVar5 & 0xff) * 4);
      uVar1 = (uVar6 | uVar1 << 8) ^ *(uint *)(param_1 + uVar6 * 4);
      uVar1 = uVar1 >> 0x18 | uVar1 << 8;
    }
    uVar3 = (int)uVar3 >> 1;
  } while (uVar3 != 0);
  *(uint *)(param_1 + 0x4c8) = uVar1;
  *(uint *)(param_1 + 0x4c4) = uVar4;
  *(int *)(param_1 + 0x4cc) = iVar2;
  *(uint *)(param_1 + 0x4d0) = param_2;
  return uVar1 ^ uVar4;
}


