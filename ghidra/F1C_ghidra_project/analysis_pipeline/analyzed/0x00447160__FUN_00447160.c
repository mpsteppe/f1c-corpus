// Function: FUN_00447160 @ 00447160
// Size (bytes): 135


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_00447160(int param_1)

{
  double dVar1;
  int iVar2;
  undefined4 in_EAX;
  undefined2 uVar5;
  uint uVar3;
  undefined3 uVar4;
  
  dVar1 = *(double *)(param_1 + 0x1db4);
  uVar5 = (undefined2)((uint)in_EAX >> 0x10);
  uVar3 = CONCAT22(uVar5,(ushort)(dVar1 < _DAT_0059e430) << 8 |
                         (ushort)(NAN(dVar1) || NAN(_DAT_0059e430)) << 10 |
                         (ushort)(dVar1 == _DAT_0059e430) << 0xe);
  if (dVar1 < _DAT_0059e430 == (dVar1 == _DAT_0059e430)) {
    dVar1 = *(double *)(param_1 + 0x19c);
    uVar3 = CONCAT22(uVar5,(ushort)(dVar1 < _DAT_0059e430) << 8 |
                           (ushort)(NAN(dVar1) || NAN(_DAT_0059e430)) << 10 |
                           (ushort)(dVar1 == _DAT_0059e430) << 0xe);
    if (dVar1 < _DAT_0059e430 == (dVar1 == _DAT_0059e430)) {
      uVar4 = (undefined3)(uVar3 >> 8);
      uVar3 = CONCAT31(uVar4,*(char *)(param_1 + 0x1c59));
      if (*(char *)(param_1 + 0x1c59) != '\0') {
        if (*(char *)(param_1 + 0x1d0c) != '\0') {
          return CONCAT31(uVar4,1);
        }
        uVar3 = *(uint *)(param_1 + 0x1f00);
        if (*(char *)(uVar3 + 0x344c) != '\0') {
          iVar2 = *(int *)(param_1 + 0x15f0);
          dVar1 = *(double *)(iVar2 + 100);
          dVar1 = *(double *)(iVar2 + 0x74) * *(double *)(iVar2 + 0x74) +
                  *(double *)(iVar2 + 0x6c) * *(double *)(iVar2 + 0x6c) + dVar1 * dVar1;
          uVar3 = CONCAT22((short)((uint)(iVar2 + 100) >> 0x10),
                           (ushort)(dVar1 < _DAT_0059e420) << 8 |
                           (ushort)(NAN(dVar1) || NAN(_DAT_0059e420)) << 10 |
                           (ushort)(dVar1 == _DAT_0059e420) << 0xe);
          if (dVar1 < _DAT_0059e420) {
            return CONCAT31((int3)(uVar3 >> 8),1);
          }
        }
      }
    }
  }
  return uVar3 & 0xffffff00;
}


