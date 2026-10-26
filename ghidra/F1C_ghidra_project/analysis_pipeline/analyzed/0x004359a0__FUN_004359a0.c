// Function: FUN_004359a0 @ 004359a0
// Size (bytes): 1110


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004359a0(int *param_1,int param_2)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int *piVar4;
  double *pdVar5;
  double *pdVar6;
  int local_154;
  double local_150;
  double local_148;
  double local_140;
  int local_138;
  int *local_134;
  double local_130;
  double local_128;
  double local_120;
  double local_118;
  double local_110;
  double local_108;
  double local_100;
  double local_f8;
  double local_f0;
  double local_e8;
  double local_e0;
  double local_d8;
  double local_d0;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_30;
  double local_28;
  double local_10;
  
  if ((*param_1 != 0) && (local_138 = 0, 0 < param_1[0x26])) {
    local_154 = 0;
    local_134 = param_1;
    do {
      piVar4 = (int *)(param_1[0x27] + local_154);
      FUN_00435e00(piVar4 + 7,&local_110);
      iVar3 = *param_1;
      local_c8 = (local_100 * *(double *)(iVar3 + 0x84) - local_108 * *(double *)(iVar3 + 0x8c)) +
                 *(double *)(iVar3 + 100);
      local_c0 = (local_110 * *(double *)(iVar3 + 0x8c) - local_100 * *(double *)(iVar3 + 0x7c)) +
                 *(double *)(iVar3 + 0x6c);
      local_b8 = (local_108 * *(double *)(iVar3 + 0x7c) - local_110 * *(double *)(iVar3 + 0x84)) +
                 *(double *)(iVar3 + 0x74);
      local_b0 = local_110 + *(double *)(iVar3 + 4);
      local_a8 = local_108 + *(double *)(iVar3 + 0xc);
      local_a0 = local_100 + *(double *)(iVar3 + 0x14);
      FUN_00435e00(piVar4 + 0xd,&local_f8);
      local_70 = local_f0 * *(double *)(param_2 + 0x7c) - local_f8 * *(double *)(param_2 + 0x84);
      local_80 = (local_e8 * *(double *)(param_2 + 0x84) - local_f0 * *(double *)(param_2 + 0x8c)) +
                 *(double *)(param_2 + 100);
      local_10 = local_e8 + *(double *)(param_2 + 0x14);
      local_128 = (local_f8 + *(double *)(param_2 + 4)) - local_b0;
      dVar2 = (local_f0 + *(double *)(param_2 + 0xc)) - local_a8;
      local_120 = dVar2;
      dVar1 = local_10 - local_a0;
      local_118 = dVar1;
      local_e0 = local_80 - local_c8;
      local_d8 = ((local_f8 * *(double *)(param_2 + 0x8c) - local_e8 * *(double *)(param_2 + 0x7c))
                 + *(double *)(param_2 + 0x6c)) - local_c0;
      local_d0 = (local_70 + *(double *)(param_2 + 0x74)) - local_b8;
      if (*piVar4 == 0) {
        FUN_00435e00(piVar4 + 1,&local_150);
      }
      else {
        pdVar5 = &local_128;
        pdVar6 = &local_150;
        for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
          *(undefined4 *)pdVar6 = *(undefined4 *)pdVar5;
          pdVar5 = (double *)((int)pdVar5 + 4);
          pdVar6 = (double *)((int)pdVar6 + 4);
        }
        dVar2 = local_128 * local_128 + dVar2 * dVar2 + dVar1 * dVar1;
        param_1 = local_134;
        if (dVar2 < _DAT_0059e430 == (dVar2 == _DAT_0059e430)) {
          dVar2 = _DAT_0059e420 / SQRT(dVar2);
          local_150 = local_128 * dVar2;
          local_148 = local_148 * dVar2;
          local_140 = local_140 * dVar2;
        }
      }
      dVar2 = local_150 * local_128 + local_148 * local_120 + local_140 * local_118;
      if ((*(double *)(piVar4 + 0x13) <= _DAT_0059e430) ||
         (*(double *)(piVar4 + 0x13) <= ABS(dVar2))) {
        if (*piVar4 == 2) {
          dVar1 = *(double *)(piVar4 + 0x17);
          pdVar5 = &local_68;
          local_30 = local_d8 * dVar1;
          local_28 = local_d0 * dVar1;
          dVar2 = dVar2 * *(double *)(piVar4 + 0x15);
          local_98 = local_150 * dVar2;
          local_90 = local_148 * dVar2;
          local_88 = local_140 * dVar2;
          local_68 = local_98 + local_e0 * dVar1;
          local_60 = local_90 + local_30;
          local_58 = local_88 + local_28;
        }
        else {
          local_130 = dVar2 * *(double *)(piVar4 + 0x15) +
                      (local_150 * local_e0 + local_d8 * local_148 + local_d0 * local_140) *
                      *(double *)(piVar4 + 0x17);
          if ((_DAT_0059e430 < *(double *)(piVar4 + 0x13)) &&
             (((_DAT_0059e430 < dVar2 && (local_130 < _DAT_0059e430)) ||
              ((dVar2 < _DAT_0059e430 && (_DAT_0059e430 < local_130)))))) goto LAB_00435dcb;
          pdVar5 = &local_50;
          local_50 = local_150 * local_130;
          local_48 = local_148 * local_130;
          local_40 = local_140 * local_130;
        }
        FUN_00569ad0(&local_110,pdVar5);
      }
LAB_00435dcb:
      local_138 = local_138 + 1;
      local_154 = local_154 + 100;
    } while (local_138 < param_1[0x26]);
  }
  return;
}


