// Function: FUN_005607c1 @ 005607c1
// Size (bytes): 309


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_005607c1(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,uint param_9,int param_10)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  undefined4 in_EAX;
  int iVar4;
  ushort *puVar5;
  
  _DAT_005dd878 = param_10 << 5;
  DAT_005dd814 = param_6;
  _DAT_005dd898 = param_10 << 6;
  puVar5 = (ushort *)(param_3 + param_5 * param_8 + param_4 * 2);
  _DAT_005dd81c = param_8 + param_6 * -2;
  _DAT_005dd818 = param_7;
  _DAT_005dd828 = ((param_9 & 0xff) >> 4) << 5;
  _DAT_005dd824 = ((param_9 >> 8 & 0xff) >> 3) << 6;
  _DAT_005dd820 = ((param_9 >> 0x10 & 0xff) >> 4) << 5;
  do {
    do {
      uVar1 = *puVar5;
      *puVar5 = (ushort)((ushort)(((uint)(byte)(&DAT_005deccc)
                                               [(uint)(byte)(&DAT_005dd8cc)
                                                            [(uVar1 & 0x1f) + _DAT_005dd828] +
                                                _DAT_005dd878] << 0x1b) >> 0x16) |
                        (ushort)(((uint)(byte)((byte)(&DAT_005deccc)
                                                     [(uint)(byte)(&DAT_005dd8cc)
                                                                  [(uVar1 & 0x1f) + _DAT_005dd828] +
                                                      _DAT_005dd878] >> 5 |
                                              (&DAT_005e0ccc)
                                              [(uint)(byte)(&DAT_005ddccc)
                                                           [(uVar1 >> 5 & 0x3f) + _DAT_005dd824] +
                                               _DAT_005dd898]) << 0x1a) >> 0x10)) >> 5 |
                (ushort)(byte)((byte)(&DAT_005e0ccc)
                                     [(uint)(byte)(&DAT_005ddccc)
                                                  [(uVar1 >> 5 & 0x3f) + _DAT_005dd824] +
                                      _DAT_005dd898] >> 6 |
                              (&DAT_005deccc)
                              [(uint)(byte)(&DAT_005dd8cc)[(uint)(uVar1 >> 0xb) + _DAT_005dd820] +
                               _DAT_005dd878]) << 0xb;
      iVar3 = _DAT_005dd818;
      puVar5 = puVar5 + 1;
      iVar4 = param_6 + -1;
      bVar2 = 0 < param_6;
      param_6 = iVar4;
    } while (iVar4 != 0 && bVar2);
    puVar5 = (ushort *)((int)puVar5 + _DAT_005dd81c);
    _DAT_005dd818 = _DAT_005dd818 + -1;
    param_6 = DAT_005dd814;
  } while (_DAT_005dd818 != 0 && 0 < iVar3);
  return CONCAT44(param_2,in_EAX);
}


