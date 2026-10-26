// Function: FUN_00569de0 @ 00569de0
// Size (bytes): 878


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00569de0(int param_1,double param_2)

{
  double *pdVar1;
  double *pdVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  double local_38;
  double local_20;
  double local_18;
  double local_10;
  
  dVar4 = *(double *)(param_1 + 0x134) - *(double *)(param_1 + 500);
  dVar3 = *(double *)(param_1 + 0x13c) - *(double *)(param_1 + 0x1fc);
  local_38 = 1.0;
  dVar5 = *(double *)(param_1 + 0x144) - *(double *)(param_1 + 0x204);
  dVar4 = dVar4 * dVar4 + dVar3 * dVar3 + dVar5 * dVar5;
  dVar5 = *(double *)(param_1 + 0x204) * *(double *)(param_1 + 0x204) +
          *(double *)(param_1 + 0x1fc) * *(double *)(param_1 + 0x1fc) +
          *(double *)(param_1 + 500) * *(double *)(param_1 + 500);
  if (((_DAT_0059eb50 * dVar5 < dVar4) &&
      (dVar4 = SQRT(dVar4) / (*(double *)(param_1 + 0xac) * _DAT_005b89b8 + SQRT(dVar5)),
      _DAT_0059e880 < dVar4)) && (dVar4 = _DAT_0059e880 / dVar4, dVar4 < _DAT_0059e420)) {
    local_38 = dVar4;
  }
  dVar4 = *(double *)(param_1 + 0x14c) - *(double *)(param_1 + 0x20c);
  dVar3 = *(double *)(param_1 + 0x154) - *(double *)(param_1 + 0x214);
  dVar5 = *(double *)(param_1 + 0x15c) - *(double *)(param_1 + 0x21c);
  dVar4 = dVar4 * dVar4 + dVar3 * dVar3 + dVar5 * dVar5;
  dVar5 = *(double *)(param_1 + 0x21c) * *(double *)(param_1 + 0x21c) +
          *(double *)(param_1 + 0x214) * *(double *)(param_1 + 0x214) +
          *(double *)(param_1 + 0x20c) * *(double *)(param_1 + 0x20c);
  if (_DAT_0059eb50 * dVar5 < dVar4) {
    pdVar1 = (double *)(param_1 + 0xbc);
    dVar3 = *(double *)(param_1 + 0xcc);
    pdVar2 = (double *)(param_1 + 0xc4);
    if (*pdVar2 <= *pdVar1) {
      if (*pdVar2 < dVar3) {
        dVar3 = *pdVar2;
      }
    }
    else if (*pdVar1 < dVar3) {
      dVar3 = *pdVar1;
    }
    dVar4 = SQRT(dVar4) / (dVar3 * _DAT_005b89b8 + SQRT(dVar5));
    if ((_DAT_0059e880 < dVar4) && (dVar4 = _DAT_0059e880 / dVar4, dVar4 < local_38))
    goto LAB_00569fd1;
  }
  dVar4 = local_38;
LAB_00569fd1:
  local_38 = dVar4;
  *(double *)(param_1 + 4) = param_2 * *(double *)(param_1 + 100) + *(double *)(param_1 + 0x164);
  *(double *)(param_1 + 0xc) = param_2 * *(double *)(param_1 + 0x6c) + *(double *)(param_1 + 0x16c);
  *(double *)(param_1 + 0x14) = param_2 * *(double *)(param_1 + 0x74) + *(double *)(param_1 + 0x174)
  ;
  dVar4 = param_2 * *(double *)(param_1 + 0xb4);
  *(double *)(param_1 + 100) = dVar4 * *(double *)(param_1 + 0x134) + *(double *)(param_1 + 0x1c4);
  *(double *)(param_1 + 0x6c) = dVar4 * *(double *)(param_1 + 0x13c) + *(double *)(param_1 + 0x1cc);
  *(double *)(param_1 + 0x74) = dVar4 * *(double *)(param_1 + 0x144) + *(double *)(param_1 + 0x1d4);
  local_20 = param_2 * *(double *)(param_1 + 0x7c);
  local_18 = param_2 * *(double *)(param_1 + 0x84);
  local_10 = param_2 * *(double *)(param_1 + 0x8c);
  puVar7 = (undefined4 *)(param_1 + 0x17c);
  puVar8 = (undefined4 *)(param_1 + 0x1c);
  for (iVar6 = 0x12; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  FUN_0056c020(&local_20);
  *(double *)(param_1 + 0x94) =
       param_2 * *(double *)(param_1 + 0x14c) + *(double *)(param_1 + 0x1dc);
  *(double *)(param_1 + 0x9c) =
       param_2 * *(double *)(param_1 + 0x154) + *(double *)(param_1 + 0x1e4);
  *(double *)(param_1 + 0xa4) =
       param_2 * *(double *)(param_1 + 0x15c) + *(double *)(param_1 + 0x1ec);
  FUN_005692a0();
  *(double *)(param_1 + 0x7c) =
       *(double *)(param_1 + 0xec) * *(double *)(param_1 + 0x94) +
       *(double *)(param_1 + 0xf4) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 0xfc) * *(double *)(param_1 + 0xa4);
  *(double *)(param_1 + 0x84) =
       *(double *)(param_1 + 0x10c) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 0x114) * *(double *)(param_1 + 0xa4) +
       *(double *)(param_1 + 0x104) * *(double *)(param_1 + 0x94);
  *(double *)(param_1 + 0x8c) =
       *(double *)(param_1 + 0x124) * *(double *)(param_1 + 0x9c) +
       *(double *)(param_1 + 300) * *(double *)(param_1 + 0xa4) +
       *(double *)(param_1 + 0x11c) * *(double *)(param_1 + 0x94);
  return (float10)local_38;
}


