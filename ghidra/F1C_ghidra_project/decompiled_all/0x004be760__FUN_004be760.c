// Function: FUN_004be760 @ 004be760
// Strings:  [Race Laptime, Qualify Laptime]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004be760(int param_1,int param_2,int param_3,float param_4)

{
  float fVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  float10 fVar6;
  undefined *puVar7;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = _DAT_0059e5fc;
  *(undefined4 *)(param_1 + 0x34c) = DAT_005acdac;
  iVar5 = 0;
  local_c = 99999.9;
  local_4 = 0.0;
  local_8 = 0.0;
  if (0 < DAT_005c329c) {
    do {
      iVar2 = (&DAT_007c54f0)[iVar5];
      if (((_DAT_0059e43c < *(float *)(iVar2 + 0x409c)) && (*(float *)(iVar2 + 0x409c) < local_c))
         && (*(int *)(iVar2 + 13000) == 1)) {
        local_c = *(float *)(iVar2 + 0x409c);
        if (*(int *)(param_1 + 0x360) == 7) {
          local_4 = *(float *)(iVar2 + 0x44c4);
        }
        else {
          local_4 = *(float *)(iVar2 + 0x44c0);
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_005c329c);
    if (local_c < _DAT_005acdcc) {
      iVar5 = 0;
      do {
        iVar2 = (&DAT_007c54f0)[iVar5];
        if (((DAT_0059e440 < *(float *)(iVar2 + 0x409c)) && (local_8 < *(float *)(iVar2 + 0x409c)))
           && ((*(float *)(iVar2 + 0x409c) < local_c * _DAT_005acdc8 &&
               (*(int *)(iVar2 + 13000) == 1)))) {
          local_8 = *(float *)(iVar2 + 0x409c);
          if (*(int *)(param_1 + 0x360) == 7) {
            fVar1 = *(float *)(iVar2 + 0x44c4);
          }
          else {
            fVar1 = *(float *)(iVar2 + 0x44c0);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < DAT_005c329c);
      if ((_DAT_0059e43c < local_8) && (local_c != local_8)) {
        fVar3 = local_4 - fVar1;
        if (local_4 - fVar1 < _DAT_0059e444) {
          fVar3 = _DAT_0059e444;
        }
        *(undefined1 *)(param_1 + 0x342) = 1;
        fVar1 = local_c - (_DAT_0059e43c - local_4) * ((local_8 - local_c) / fVar3);
        *(float *)(param_1 + 0x34c) = fVar1;
        if (local_c * _DAT_005acdc4 <= fVar1) {
          return;
        }
        *(float *)(param_1 + 0x34c) = local_c * _DAT_005acdc4;
        return;
      }
    }
  }
  if ((param_3 != 0) && (iVar5 = FUN_004c5840(param_3), iVar5 != 0)) {
    puVar7 = PTR_s_Race_Laptime_005d2634;
    if ((2 < param_2) && (param_2 < 6)) {
      puVar7 = PTR_s_Qualify_Laptime_005d2630;
    }
    iVar5 = FUN_005679c0(puVar7);
    if (iVar5 != 0) {
      uVar4 = FUN_00567970();
      fVar6 = (float10)FUN_0058850f(uVar4);
      *(float *)(param_1 + 0x34c) = (float)fVar6;
    }
  }
  *(float *)(param_1 + 0x348) = param_4;
  fVar1 = _DAT_005acdb8 * *(float *)(param_1 + 0x34c);
  *(undefined1 *)(param_1 + 0x342) = 1;
  *(float *)(param_1 + 0x34c) = (_DAT_0059e43c - param_4) * fVar1 + *(float *)(param_1 + 0x34c);
  return;
}


