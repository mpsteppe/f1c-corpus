// Function: FUN_005692a0 @ 005692a0
// Size (bytes): 354


void __fastcall FUN_005692a0(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar1 = *(double *)(param_1 + 0x1c) * *(double *)(param_1 + 0xd4);
  dVar2 = *(double *)(param_1 + 0xdc) * *(double *)(param_1 + 0x24);
  dVar3 = *(double *)(param_1 + 0x2c) * *(double *)(param_1 + 0xe4);
  dVar4 = *(double *)(param_1 + 0x34) * *(double *)(param_1 + 0xd4);
  dVar5 = *(double *)(param_1 + 0xdc) * *(double *)(param_1 + 0x3c);
  dVar6 = *(double *)(param_1 + 0x44) * *(double *)(param_1 + 0xe4);
  *(double *)(param_1 + 0xec) =
       dVar2 * *(double *)(param_1 + 0x24) +
       dVar1 * *(double *)(param_1 + 0x1c) + dVar3 * *(double *)(param_1 + 0x2c);
  *(double *)(param_1 + 0xf4) =
       dVar1 * *(double *)(param_1 + 0x34) +
       dVar3 * *(double *)(param_1 + 0x44) + dVar2 * *(double *)(param_1 + 0x3c);
  *(double *)(param_1 + 0xfc) =
       dVar2 * *(double *)(param_1 + 0x54) +
       dVar1 * *(double *)(param_1 + 0x4c) + dVar3 * *(double *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xf4);
  *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)(param_1 + 0xf8);
  *(double *)(param_1 + 0x10c) =
       dVar4 * *(double *)(param_1 + 0x34) +
       dVar6 * *(double *)(param_1 + 0x44) + dVar5 * *(double *)(param_1 + 0x3c);
  *(double *)(param_1 + 0x114) =
       dVar5 * *(double *)(param_1 + 0x54) +
       dVar4 * *(double *)(param_1 + 0x4c) + dVar6 * *(double *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0xfc);
  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x100);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x114);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x118);
  *(double *)(param_1 + 300) =
       *(double *)(param_1 + 0xdc) * *(double *)(param_1 + 0x54) * *(double *)(param_1 + 0x54) +
       *(double *)(param_1 + 0x4c) * *(double *)(param_1 + 0xd4) * *(double *)(param_1 + 0x4c) +
       *(double *)(param_1 + 0x5c) * *(double *)(param_1 + 0xe4) * *(double *)(param_1 + 0x5c);
  return;
}


