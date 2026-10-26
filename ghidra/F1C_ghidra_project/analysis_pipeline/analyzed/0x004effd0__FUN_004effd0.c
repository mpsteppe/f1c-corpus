// Function: FUN_004effd0 @ 004effd0
// Size (bytes): 118


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_004effd0(undefined4 *param_1)

{
  float fVar1;
  undefined2 extraout_var;
  uint3 uVar2;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  FUN_004efb20(&local_30,local_18);
  FUN_004d1140(*param_1,&local_24,local_c);
  fVar1 = (local_30 - local_24) * (local_30 - local_24) +
          (local_2c - local_20) * (local_2c - local_20) +
          (local_28 - local_1c) * (local_28 - local_1c);
  uVar2 = (uint3)(CONCAT22(extraout_var,
                           (ushort)(fVar1 < _DAT_0059e46c) << 8 |
                           (ushort)(NAN(fVar1) || NAN(_DAT_0059e46c)) << 10 |
                           (ushort)(fVar1 == _DAT_0059e46c) << 0xe) >> 8);
  if (fVar1 < _DAT_0059e46c) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


