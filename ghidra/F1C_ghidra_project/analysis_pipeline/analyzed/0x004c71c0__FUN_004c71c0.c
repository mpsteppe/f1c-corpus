// Function: FUN_004c71c0 @ 004c71c0
// Size (bytes): 553


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c71c0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *local_4;
  
  iVar1 = param_2;
  iVar4 = 0;
  FUN_004b33b0(1,0,0x34,*(undefined4 *)(param_1 + 0x4894),(float)_DAT_008afea0,0);
  FUN_004b2310(param_1 + 0x744,param_1 + 0x704);
  FUN_004b2480(param_1 + 0x34f8);
  FUN_004b25d0(param_1 + 0x3510);
  FUN_004b2750(param_1 + 0x3540);
  local_4 = (undefined4 *)(param_1 + 0x35bc);
  param_2 = 0;
  do {
    FUN_004b2840(param_2,*(float *)(iVar4 + param_1 + 0x83c) + *(float *)(param_1 + 0x73c),*local_4)
    ;
    param_2 = param_2 + 1;
    local_4 = local_4 + 0x3e;
    iVar4 = iVar4 + 0x128;
  } while (iVar4 < 0x4a0);
  FUN_004b2930(*(undefined4 *)(param_1 + 0x39a0));
  FUN_004b29b0(*(undefined4 *)(param_1 + 0x357c));
  FUN_004b2a10(*(undefined4 *)(param_1 + 0x39fc));
  if (*(char *)(param_1 + 0x1069) == '\0') {
    uVar2 = *(uint *)(iVar1 + 0x34) & 0xffffff7f;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x34) | 0x80;
  }
  *(uint *)(iVar1 + 0x34) = uVar2;
  FUN_004b2a40(*(undefined4 *)(param_1 + 0x3580));
  iVar4 = 0;
  do {
    uVar3 = FUN_004e18c0(iVar4);
    FUN_004b2aa0(iVar4,uVar3);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xe);
  if (*(char *)(param_1 + 0x105d) == '\0') {
    uVar2 = *(uint *)(iVar1 + 0x38) & 0xf7ffffff;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x38) | 0x8000000;
  }
  *(uint *)(iVar1 + 0x38) = uVar2;
  if (*(float *)(param_1 + 0x3584) <= _DAT_0059e444) {
    uVar2 = *(uint *)(iVar1 + 0x38) & 0xfbffffff;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x38) | 0x4000000;
  }
  *(uint *)(iVar1 + 0x38) = uVar2;
  if (*(char *)(param_1 + 0x1067) == '\0') {
    uVar2 = *(uint *)(iVar1 + 0x38) & 0xfdffffff;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x38) | 0x2000000;
  }
  *(uint *)(iVar1 + 0x38) = uVar2;
  if (*(char *)(param_1 + 0x344c) == '\0') {
    uVar2 = *(uint *)(iVar1 + 0x38) & 0x7fffffff;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x38) | 0x80000000;
  }
  *(uint *)(iVar1 + 0x38) = uVar2;
  if (*(char *)(param_1 + 0x4024) == '\0') {
    uVar2 = *(uint *)(iVar1 + 0x38) & 0xfeffffff;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x38) | 0x1000000;
  }
  *(uint *)(iVar1 + 0x38) = uVar2;
  FUN_004b2b10(*(undefined4 *)(param_1 + 0x4028));
  FUN_004b2b60(*(undefined4 *)((&DAT_007c54f0)[DAT_007c54dc] + 0x4894));
  uVar3 = FUN_004c7c00();
  FUN_004b2ae0(uVar3);
  return;
}


