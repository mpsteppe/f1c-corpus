// Function: FUN_004ae490 @ 004ae490
// Size (bytes): 690


void __fastcall FUN_004ae490(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1ac8) == 1) {
    *(undefined4 *)(param_1 + 0xb10) = 0;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0xb1c));
    *(undefined4 *)(param_1 + 0xb34) = 0;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0xb40));
    *(undefined4 *)(param_1 + 0xb58) = 0;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0xb64));
    *(undefined4 *)(param_1 + 0x1c30) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0x1c3c));
    *(undefined4 *)(param_1 + 0x2348) = 0x3d4ccccd;
    FUN_004646c0(*(undefined4 *)(param_1 + 0x2350),*(undefined4 *)(param_1 + 0x2354));
    *(undefined4 *)(param_1 + 0x236c) = 0x3d4ccccd;
  }
  else {
    if (*(int *)(param_1 + 0x1ac8) != 2) goto LAB_004ae605;
    *(undefined4 *)(param_1 + 0xb10) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0xb1c));
    *(undefined4 *)(param_1 + 0xb34) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0xb40));
    *(undefined4 *)(param_1 + 0xb58) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0xb64));
    *(undefined4 *)(param_1 + 0x1c30) = 0;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0x1c3c));
    *(undefined4 *)(param_1 + 0x2348) = 0x3f000000;
    FUN_004646c0(*(undefined4 *)(param_1 + 0x2350),*(undefined4 *)(param_1 + 0x2354));
    *(undefined4 *)(param_1 + 0x236c) = 0x3f000000;
  }
  FUN_004646c0(*(undefined4 *)(param_1 + 0x2374),*(undefined4 *)(param_1 + 0x2378));
LAB_004ae605:
  if (*(int *)(param_1 + 0x1ac8) != 0) {
    *(undefined4 *)(param_1 + 0x26f0) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0x26fc));
    *(undefined4 *)(param_1 + 0x2714) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0x2720));
    *(undefined4 *)(param_1 + 0x2738) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0x2744));
    *(undefined4 *)(param_1 + 0x27ec) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0x27f8));
    *(undefined4 *)(param_1 + 0x2810) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0x281c));
    *(undefined4 *)(param_1 + 0x2834) = 1;
    FUN_0047f1f0(*(undefined4 *)(param_1 + 0x2840));
    FUN_004b20d0(2);
    FUN_004b20d0(2);
    FUN_004b20d0(2);
    iVar1 = FUN_00423060();
    FUN_004b20d0(iVar1 + -1);
    iVar1 = FUN_00423060();
    FUN_004b20d0(iVar1 + -1);
    iVar1 = FUN_00423060();
    FUN_004b20d0(iVar1 + -1);
    FUN_004b20d0(0x17);
  }
  return;
}


