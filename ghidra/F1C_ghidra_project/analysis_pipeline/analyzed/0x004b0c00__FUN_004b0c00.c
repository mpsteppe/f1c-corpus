// Function: FUN_004b0c00 @ 004b0c00
// Size (bytes): 546


undefined4 __fastcall FUN_004b0c00(int param_1)

{
  int iVar1;
  undefined3 uVar2;
  
  *(undefined4 *)(param_1 + 0x654) = *(undefined4 *)(param_1 + 0x496c);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x660));
  *(undefined4 *)(param_1 + 0x888) = *(undefined4 *)(param_1 + 0x4970);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x894));
  *(undefined4 *)(param_1 + 0x984) = *(undefined4 *)(param_1 + 0x4974);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x990));
  *(undefined4 *)(param_1 + 0xa80) = *(undefined4 *)(param_1 + 0x4978);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0xa8c));
  *(undefined4 *)(param_1 + 0xb7c) = *(undefined4 *)(param_1 + 0x497c);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0xb88));
  *(undefined4 *)(param_1 + 0xc78) = *(undefined4 *)(param_1 + 0x4980);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0xc84));
  *(undefined1 *)(param_1 + 0xd44) = *(undefined1 *)(param_1 + 0x4984);
  FUN_00464720(*(undefined1 *)(param_1 + 0xd47));
  *(undefined4 *)(param_1 + 0x209c) = *(undefined4 *)(param_1 + 0x4988);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x20a8));
  *(undefined4 *)(param_1 + 0x2198) = *(undefined4 *)(param_1 + 0x498c);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x21a4));
  *(undefined4 *)(param_1 + 0x2294) = *(undefined4 *)(param_1 + 0x4990);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x22a0));
  *(undefined4 *)(param_1 + 0x2390) = *(undefined4 *)(param_1 + 0x4994);
  FUN_004646c0(*(undefined4 *)(param_1 + 0x2398),*(undefined4 *)(param_1 + 0x239c));
  *(undefined4 *)(param_1 + 0x2588) = *(undefined4 *)(param_1 + 0x4998);
  FUN_0047f1f0(*(undefined4 *)(param_1 + 0x2594));
  *(undefined4 *)(param_1 + 0x275c) = *(undefined4 *)(param_1 + 0x499c);
  if (*(int *)(param_1 + 0x275c) < *(int *)(param_1 + 0x2764)) {
    *(int *)(param_1 + 0x275c) = *(int *)(param_1 + 0x2764);
  }
  else if (*(int *)(param_1 + 0x2768) < *(int *)(param_1 + 0x275c)) {
    *(int *)(param_1 + 0x275c) = *(int *)(param_1 + 0x2768);
  }
  iVar1 = *(int *)(param_1 + 0x49a0);
  *(int *)(param_1 + 0x2858) = iVar1;
  if (iVar1 < *(int *)(param_1 + 0x2860)) {
    *(int *)(param_1 + 0x2858) = *(int *)(param_1 + 0x2860);
  }
  else if (*(int *)(param_1 + 0x2864) < iVar1) {
    *(int *)(param_1 + 0x2858) = *(int *)(param_1 + 0x2864);
  }
  iVar1 = *(int *)(param_1 + 0x2494);
  *(undefined4 *)(param_1 + 0x248c) = *(undefined4 *)(param_1 + 0x49a4);
  uVar2 = (undefined3)((uint)iVar1 >> 8);
  if (*(int *)(param_1 + 0x248c) < iVar1) {
    *(int *)(param_1 + 0x248c) = iVar1;
    return CONCAT31(uVar2,1);
  }
  if (*(int *)(param_1 + 0x2498) < *(int *)(param_1 + 0x248c)) {
    *(int *)(param_1 + 0x248c) = *(int *)(param_1 + 0x2498);
  }
  return CONCAT31(uVar2,1);
}


