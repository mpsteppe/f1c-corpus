// Function: FUN_0042b0e0 @ 0042b0e0
// Size (bytes): 1959


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042b0e0(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  undefined4 uVar10;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined1 local_30 [12];
  undefined1 local_24 [12];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar6 = 0;
  if (DAT_007c56a8 == 3) {
    iVar5 = param_1[0x1018];
    iVar7 = 0;
    if (0 < DAT_005c329c) {
      do {
        if (*(int *)((&DAT_007c54f0)[iVar7] + 0x4060) == iVar5 + -1) {
          fVar9 = (float10)FUN_004f0050();
          local_7c = (float)fVar9;
          fVar8 = (float10)FUN_004f0050();
          fVar8 = fVar8 - (float10)local_7c;
          fVar9 = (float10)DAT_005ea3fc;
          if (fVar8 <= (float10)_DAT_0059e450 * fVar9) {
            if (fVar8 < (float10)_DAT_0059e99c * fVar9) {
              fVar8 = fVar9 + fVar8;
            }
          }
          else {
            fVar8 = fVar8 - fVar9;
          }
          if ((float10)_DAT_0059e998 < fVar8) {
            if ((float10)_DAT_0059e8d8 <= fVar8 + fVar8) {
              local_9c = (float)(fVar8 + fVar8);
            }
            else {
              local_9c = 15.0;
            }
            FUN_0042a740(local_9c);
            if ((((float)param_1[0x1110] < _DAT_0059e43c) &&
                (iVar2 = (&DAT_007c54f0)[iVar7],
                SQRT(*(float *)(iVar2 + 0x3500) * *(float *)(iVar2 + 0x3500) +
                     *(float *)(iVar2 + 0x34fc) * *(float *)(iVar2 + 0x34fc) +
                     *(float *)(iVar2 + 0x34f8) * *(float *)(iVar2 + 0x34f8)) < _DAT_0059e7e8)) &&
               (_DAT_008afea0 <
                ((double)(iVar5 + -1) + (double)_DAT_0059e7ec) * (double)_DAT_0059e8c8 +
                (double)_DAT_008acf94)) {
              param_1[0x110d] = 0;
            }
          }
          break;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < DAT_005c329c);
    }
    if (iVar7 == DAT_005c329c) {
      FUN_0042a740(0x42440000);
    }
    if (_DAT_0059e824 < (float)param_1[0x110d]) {
      param_1[0x110d] = 0x3f666666;
    }
  }
  if ((DAT_007c56a8 == 1) ||
     ((DAT_007c56a8 == 3 &&
      ((double)_DAT_008acf94 + (double)_DAT_0059e468 < _DAT_008afea0 !=
       ((double)_DAT_008acf94 + (double)_DAT_0059e468 == _DAT_008afea0))))) {
    if ((param_1[0xeaa] == 0) || (*(int *)(param_1[0xeaa] + 300) == 0)) {
      FUN_004d10e0(*param_1,&local_60,local_30);
      FUN_004efb20(&local_78,local_c);
      local_88 = local_60 - local_78;
      local_84 = local_5c - local_74;
      local_80 = local_58 - local_70;
      local_7c = SQRT(local_88 * local_88 + local_84 * local_84 + local_80 * local_80);
      FUN_0042a740(local_7c * _DAT_0059e8c8 + _DAT_0059e478);
      if (DAT_007cec18 != '\0') {
        local_9c = 3.4028235e+38;
        iVar5 = 0x68;
        if (DAT_005c329c + 2 < 0x69) {
          iVar5 = DAT_005c329c + 2;
        }
        iVar7 = 0;
        if (0 < iVar5) {
          do {
            FUN_00403cd0(iVar7,&local_94,&local_6c);
            local_94 = local_94 - local_78;
            local_90 = local_90 - local_74;
            local_8c = local_8c - local_70;
            fVar1 = SQRT(local_90 * local_90 + local_8c * local_8c + local_94 * local_94);
            if (fVar1 < local_9c) {
              iVar6 = iVar7;
              local_9c = fVar1;
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar5);
          if (local_9c < _DAT_0059e990) {
            local_98 = local_9c - _DAT_0059e8ec;
            if (local_98 < _DAT_0059e6a4) {
              local_98 = 35.0;
            }
            FUN_0042a740(local_98);
            if (local_9c < _DAT_0059e6a4) {
              if (iVar6 < 2) {
                iVar5 = 0;
              }
              else {
                iVar5 = iVar6 + -2;
              }
              FUN_00403cd0(iVar5,&local_6c,local_24);
              iVar5 = 1;
              if (0 < iVar6) {
                iVar5 = iVar6 + -1;
              }
              FUN_00403cd0(iVar5,&local_94,local_18);
              local_64 = local_8c + local_64;
              local_94 = (local_94 + local_6c) * _DAT_0059e450 - local_78;
              local_90 = (local_90 + local_68) * _DAT_0059e450 - local_74;
              fVar9 = (float10)local_64 * (float10)_DAT_0059e450 - (float10)local_70;
              fVar9 = (float10)fpatan(-((float10)local_94 * (float10)(float)param_1[0xd2f] +
                                       (float10)local_90 * (float10)(float)param_1[0xd32] +
                                       fVar9 * (float10)(float)param_1[0xd35]),
                                      -((float10)local_94 * (float10)(float)param_1[0xd31] +
                                       (float10)local_90 * (float10)(float)param_1[0xd34] +
                                       fVar9 * (float10)(float)param_1[0xd37]));
              param_1[0x110b] = (float)(fVar9 / (float10)(float)param_1[0x112d]);
              if (_DAT_0059e670 <= (float)param_1[0x110b]) {
                if (_DAT_0059e43c < (float)param_1[0x110b]) {
                  param_1[0x110b] = 0x3f800000;
                }
              }
              else {
                param_1[0x110b] = 0xbf800000;
              }
            }
          }
        }
      }
      if (local_7c < _DAT_0059e86c) {
        FUN_00566e40();
        fVar1 = (local_54 * DAT_0059e440 + local_4c * _DAT_0059e670 + local_50 * DAT_0059e440) *
                local_88 +
                (local_40 * _DAT_0059e670 + local_44 * DAT_0059e440 + local_48 * DAT_0059e440) *
                local_84 +
                (local_34 * _DAT_0059e670 + local_38 * DAT_0059e440 + local_3c * DAT_0059e440) *
                local_80;
        if (DAT_0059e440 <= fVar1) {
          if (fVar1 < _DAT_0059e8d8) {
            fVar9 = (float10)fpatan(-((float10)local_88 * (float10)(float)param_1[0xd2f] +
                                     (float10)local_84 * (float10)(float)param_1[0xd32] +
                                     (float10)local_80 * (float10)(float)param_1[0xd35]),
                                    -((float10)local_88 * (float10)(float)param_1[0xd31] +
                                     (float10)local_84 * (float10)(float)param_1[0xd34] +
                                     (float10)local_80 * (float10)(float)param_1[0xd37]));
            param_1[0x110b] = (float)(fVar9 / (float10)(float)param_1[0x112d]);
            if ((float)param_1[0x110b] < _DAT_0059e670) {
              param_1[0x110b] = 0xbf800000;
              return;
            }
            if (_DAT_0059e43c < (float)param_1[0x110b]) {
              param_1[0x110b] = 0x3f800000;
            }
          }
        }
        else {
          FUN_004f2320();
          FUN_004ef7c0(&local_60,local_30);
          *(undefined1 *)(param_1 + 0x117d) = 0;
          if (DAT_007c56a8 == 1) {
            FUN_004efac0();
            return;
          }
        }
      }
    }
    else if (((DAT_007c56a8 == 1) && (cVar3 = FUN_004effd0(), cVar3 != '\0')) &&
            (((float)param_1[0xe68] < (float)param_1[0xe6a] &&
             (fVar1 = (float)_DAT_008afea0, _DAT_0059e5fc < ABS(fVar1 - (float)param_1[0x1118])))))
    {
      fVar9 = (float10)FUN_0058957a();
      if ((float10)(float)param_1[0x1112] * (float10)_DAT_0059e8ec + (float10)_DAT_0059e43c + fVar9
          + (float10)_DAT_008acf90 < (float10)fVar1) {
        uVar10 = 1;
        uVar4 = FUN_00429fd0(1);
        FUN_004f1a60(uVar4,uVar10);
        fVar1 = (float)param_1[0x117a] * _DAT_0059e8a4 + (float)param_1[0xe61];
        if ((float)param_1[0xe62] <= fVar1) {
          fVar1 = (float)param_1[0xe62];
        }
        FUN_004f1890(fVar1);
        FUN_004efa40(0);
        fVar1 = (float)_DAT_008afea0;
        param_1[0x10d5] = 0;
        param_1[0x10d6] = 0;
        param_1[0x1118] = fVar1;
        param_1[0x1144] = 5;
        param_1[0x1154] = 1;
        param_1[0x114e] = _DAT_008acfb4;
        return;
      }
      param_1[0x110b] = 0;
      return;
    }
  }
  return;
}


