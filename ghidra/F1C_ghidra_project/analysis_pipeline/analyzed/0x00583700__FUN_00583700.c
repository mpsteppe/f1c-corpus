// Function: FUN_00583700 @ 00583700
// Size (bytes): 133


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall
FUN_00583700(uint *param_1,uint param_2,uint param_3,uint param_4,double param_5,uint *param_6,
            uint param_7)

{
  double dVar1;
  double dVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  if (param_2 == *param_1) {
    dVar1 = (double)CONCAT44(param_4,param_3) - *(double *)(param_1 + 1);
    dVar2 = (double)_DAT_0059e800;
    param_2 = CONCAT22((short)(param_2 >> 0x10),
                       (ushort)(dVar1 < dVar2) << 8 | (ushort)(NAN(dVar1) || NAN(dVar2)) << 10 |
                       (ushort)(dVar1 == dVar2) << 0xe);
    if (dVar1 < dVar2) {
      dVar1 = dVar1 * _DAT_0059e880;
      param_1[4] = param_3;
      uVar3 = CONCAT31((int3)(param_2 >> 8),1);
      *(undefined1 *)(param_1 + 3) = 1;
      param_1[5] = param_4;
      *(double *)(param_1 + 6) = dVar1 + param_5;
      if ((0 < (int)param_7) && ((int)param_7 < 0xff)) {
        param_1[0x48] = param_7;
        puVar5 = param_1 + 8;
        for (uVar4 = param_7 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar5 = *param_6;
          param_6 = param_6 + 1;
          puVar5 = puVar5 + 1;
        }
        for (param_7 = param_7 & 3; param_7 != 0; param_7 = param_7 - 1) {
          *(char *)puVar5 = (char)*param_6;
          param_6 = (uint *)((int)param_6 + 1);
          puVar5 = (uint *)((int)puVar5 + 1);
        }
        return uVar3;
      }
      param_1[0x48] = 0;
      return uVar3;
    }
  }
  return param_2 & 0xffffff00;
}


