// Function: FUN_004b67d0 @ 004b67d0
// Size (bytes): 201


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short __thiscall FUN_004b67d0(int param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  float local_4;
  
  iVar4 = *(int *)(param_1 + 0x9ac) + -1;
  switch(iVar4) {
  case 0:
    local_4 = 0.049087387;
    break;
  case 1:
    local_4 = 0.024543693;
    break;
  case 2:
    local_4 = 0.016362462;
    break;
  case 3:
    local_4 = 0.012271847;
    break;
  default:
    local_4 = 0.09817477;
  }
  param_2 = ABS(param_2);
  if (param_2 < local_4 != (param_2 == local_4)) {
    return CONCAT11(param_2 < local_4 |
                    (byte)((ushort)((ushort)(NAN(param_2) || NAN(local_4)) << 10) >> 8) |
                    (byte)((ushort)((ushort)(param_2 == local_4) << 0xe) >> 8),1);
  }
  fVar2 = _DAT_0059e84c;
  switch(iVar4) {
  case 0:
    fVar2 = _DAT_005acd60;
    break;
  case 1:
    fVar2 = _DAT_005acd5c;
    break;
  case 2:
    fVar2 = _DAT_005acd58;
    break;
  case 3:
    fVar2 = _DAT_005acd44;
  }
  fVar1 = fVar2 * param_3;
  if (fVar2 * param_3 < local_4 + local_4) {
    fVar1 = local_4 + local_4;
  }
  bVar3 = param_2 < fVar1 | (byte)((ushort)((ushort)(NAN(param_2) || NAN(fVar1)) << 10) >> 8) |
          (byte)((ushort)((ushort)(param_2 == fVar1) << 0xe) >> 8);
  if ((NAN(param_2) || NAN(fVar1)) || param_2 < fVar1 == (param_2 == fVar1)) {
    return (ushort)bVar3 << 8;
  }
  return CONCAT11(bVar3,1);
}


