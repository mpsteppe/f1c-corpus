// Function: FUN_00461900 @ 00461900
// Size (bytes): 878


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00461900(int param_1)

{
  FUN_004c5690(param_1 + 0x20);
  FUN_004c54f0(0);
  FUN_004b1410(param_1 + 0x40);
  _DAT_007d0a44 = (int)*(char *)(param_1 + 100);
  FUN_0047f1f0(DAT_007d0a50);
  _DAT_007d0fc4 = (int)*(char *)(param_1 + 0x66);
  FUN_0047f1f0(DAT_007d0fd0);
  DAT_007d0c18 = (int)*(char *)(param_1 + 0x67);
  FUN_0047f1f0(DAT_007d0c24);
  DAT_007d0d14 = (int)*(char *)(param_1 + 0x68);
  FUN_0047f1f0(DAT_007d0d20);
  DAT_007d0014 = (int)*(char *)(param_1 + 0x69);
  FUN_0047f1f0(DAT_007d0020);
  DAT_007ceb10 = (int)*(char *)(param_1 + 0x6a);
  FUN_0047f1f0(DAT_007ceb1c);
  DAT_007d0ebc = (int)*(char *)(param_1 + 0x6b);
  FUN_0047f1f0(DAT_007d0ec8);
  DAT_007cf134 = (int)*(char *)(param_1 + 0x6c);
  FUN_0047f1f0(DAT_007cf140);
  DAT_007cf038 = (int)*(char *)(param_1 + 0x6d);
  FUN_0047f1f0(DAT_007cf044);
  DAT_007d084c = *(undefined4 *)(param_1 + 0x60);
  FUN_004646c0(DAT_007d0854,DAT_007d0858);
  DAT_007d0f4c = (int)*(short *)(param_1 + 0x74);
  FUN_0047f1f0(DAT_007d0f58);
  if ((*(ushort *)(param_1 + 0x76) & 1) != 0) {
    DAT_007ce874 = (byte)(*(ushort *)(param_1 + 0x76) >> 6) & 1;
    FUN_00464720(DAT_007ce877);
  }
  if ((*(ushort *)(param_1 + 0x76) & 2) != 0) {
    DAT_007ce88c = (byte)(*(ushort *)(param_1 + 0x76) >> 7) & 1;
    FUN_00464720(DAT_007ce88f);
  }
  if ((*(ushort *)(param_1 + 0x76) & 4) != 0) {
    DAT_007ce958 = (*(ushort *)(param_1 + 0x76) & 0x100) >> 8;
    FUN_0047f1f0(DAT_007ce964);
  }
  if ((*(ushort *)(param_1 + 0x76) & 8) != 0) {
    DAT_007ce97c = (byte)(*(ushort *)(param_1 + 0x76) >> 9) & 1;
    FUN_00464720(DAT_007ce97f);
  }
  if ((*(byte *)(param_1 + 0x76) & 0x10) != 0) {
    DAT_007d108c = (float)*(ushort *)(param_1 + 0x7c) * _DAT_0059e600;
    FUN_004646c0(DAT_007d1094,DAT_007d1098);
  }
  _DAT_007ced44 = (*(ushort *)(param_1 + 0x76) & 0x400) >> 10;
  FUN_0047f1f0(DAT_007ced50);
  _DAT_007cee40 = (*(ushort *)(param_1 + 0x76) & 0x800) >> 0xb;
  FUN_0047f1f0(DAT_007cee4c);
  _DAT_007cef3c = (*(ushort *)(param_1 + 0x76) & 0x1000) >> 0xc;
  FUN_0047f1f0(DAT_007cef48);
  _DAT_007cec30 = (int)*(short *)(param_1 + 0x78);
  FUN_0047f1f0(DAT_007cec3c);
  _DAT_007cec54 = (int)*(short *)(param_1 + 0x7a);
  FUN_0047f1f0(DAT_007cec60);
  DAT_007d0134 = FUN_004615f0(1);
  FUN_0047f1f0(DAT_007d0140);
  FUN_004b0ef0(5);
  return;
}


