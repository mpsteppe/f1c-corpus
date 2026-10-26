// Function: FUN_004b66e0 @ 004b66e0
// Size (bytes): 204


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort __thiscall FUN_004b66e0(int param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  ushort uVar4;
  
  iVar3 = *(int *)(param_1 + 0x9ac) + -1;
  fVar1 = _DAT_005acd4c;
  switch(iVar3) {
  case 0:
    fVar1 = _DAT_0059e44c;
    break;
  case 1:
    fVar1 = _DAT_005acd54;
    break;
  case 2:
    fVar1 = _DAT_0059e444;
    break;
  case 3:
    fVar1 = _DAT_005acd50;
  }
  param_2 = ABS(param_2);
  if (param_2 < fVar1 != (param_2 == fVar1)) {
    return CONCAT11(param_2 < fVar1 |
                    (byte)((ushort)((ushort)(NAN(param_2) || NAN(fVar1)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == fVar1) << 0xe) >> 8),1);
  }
  param_3 = ABS(param_3);
  fVar1 = _DAT_0059e8f4;
  if ((_DAT_0059e8f4 < param_3) ||
     (uVar4 = (ushort)(param_3 < _DAT_0059e800) << 8 |
              (ushort)(NAN(param_3) || NAN(_DAT_0059e800)) << 10 |
              (ushort)(param_3 == _DAT_0059e800) << 0xe, fVar1 = param_3, param_3 >= _DAT_0059e800))
  {
    fVar2 = _DAT_0059e44c;
    switch(iVar3) {
    case 0:
      fVar2 = _DAT_005acd48;
      break;
    case 1:
      fVar2 = _DAT_005acd44;
      break;
    case 2:
      fVar2 = _DAT_005acd40;
      break;
    case 3:
      fVar2 = _DAT_005acd3c;
    }
    fVar2 = fVar2 * fVar1;
    uVar4 = (ushort)(param_2 < fVar2) << 8 | (ushort)(NAN(param_2) || NAN(fVar2)) << 10 |
            (ushort)(param_2 == fVar2) << 0xe;
    if (param_2 < fVar2 != (param_2 == fVar2)) {
      return CONCAT11((char)(uVar4 >> 8),1);
    }
  }
  return uVar4;
}


