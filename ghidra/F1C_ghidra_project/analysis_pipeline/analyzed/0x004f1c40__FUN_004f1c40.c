// Function: FUN_004f1c40 @ 004f1c40
// Size (bytes): 921


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f1c40(int *param_1,float param_2)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined1 local_44 [12];
  undefined1 local_38 [4];
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_24;
  int local_20;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = param_1[0xcaf];
  if (((iVar4 == 1) || (iVar4 == 0)) && ((*(uint *)(*param_1 + 0x48bc) >> 3 & 1) != 0)) {
    if (DAT_007d0af8 == '\x01') {
      if (_DAT_005ad1c4 <= (float)param_1[0xd30]) {
        param_1[0xffd] = 0;
      }
      else {
        local_58 = param_2 + (float)param_1[0xffd];
        param_1[0xffd] = (int)local_58;
        if ((float)param_1[0xd3d] * (float)param_1[0xd3d] +
            (float)param_1[0xd3c] * (float)param_1[0xd3c] +
            (float)param_1[0xd3b] * (float)param_1[0xd3b] < _DAT_0059e8a0) {
          bVar1 = false;
          if ((iVar4 == 0) && ((DAT_007c749f != '\0' || (DAT_007c74a3 != '\0')))) {
            bVar1 = true;
          }
          if ((_DAT_0059e7ec < local_58) || ((bVar1 && (_DAT_0059e478 < local_58)))) {
            FUN_004f2320();
            fVar7 = (float10)fpatan((float10)(float)param_1[0xd2e],(float10)(float)param_1[0xd34]);
            param_1[0xd38] = 0;
            param_1[0xd3a] = 0;
            param_1[0xd39] = (int)(float)fVar7;
            FUN_00566e40();
            FUN_004efb20(local_44,&local_50);
            FUN_004ef7c0(local_44,&local_50);
          }
        }
      }
      iVar5 = 0;
      iVar6 = 0;
      piVar3 = param_1 + 0xd9a;
      piVar2 = param_1 + 0x20a;
      iVar4 = 4;
      do {
        if (((*piVar2 != 0) && ((char)piVar2[0x10] != '\0')) && (iVar6 = iVar6 + 1, *piVar3 == 0)) {
          iVar5 = iVar5 + 1;
        }
        piVar2 = piVar2 + 0x4a;
        piVar3 = piVar3 + 0x3e;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if ((iVar5 == 0) && (2 < iVar6)) {
        param_1[0x1002] = param_1[0xd35];
        param_1[0x1003] = param_1[0xd36];
        param_1[0x1004] = param_1[0xd37];
      }
      else if (iVar5 == iVar6) {
        FUN_004f2320();
        param_1[0xd35] = param_1[0x1002];
        param_1[0xd36] = param_1[0x1003];
        param_1[0xd37] = param_1[0x1004];
        FUN_004efb20(&local_50,local_44);
        FUN_004ef7c0(&local_50,local_44);
      }
      else if (1 < iVar5) {
        local_50 = (float)param_1[0x1002] - (float)param_1[0xd35];
        local_24 = (float)param_1[0xd35];
        local_20 = param_1[0xd36];
        local_1c = param_1[0xd37];
        local_4c = (float)param_1[0x1003] - (float)param_1[0xd36];
        local_48 = (float)param_1[0x1004] - (float)param_1[0xd37];
        local_8 = SQRT(local_50 * local_50 + local_48 * local_48) * _DAT_0059e84c + local_4c;
        if (((local_50 == DAT_0059e440) && (local_8 == DAT_0059e440)) && (local_48 == DAT_0059e440))
        {
          local_c = 0.0;
          local_8 = 1.0;
          local_4 = 0.0;
        }
        else {
          local_4 = _DAT_0059e43c /
                    SQRT(local_50 * local_50 + local_48 * local_48 + local_8 * local_8);
          local_c = local_50 * local_4;
          local_8 = local_4 * local_8;
          local_4 = local_4 * local_48;
        }
        local_18 = local_c;
        local_14 = local_8;
        local_10 = local_4;
        FUN_004ed420(&local_24,&local_c,&local_58,&local_54,0);
        if (DAT_0059e440 < local_58) {
          local_58 = 0.0;
        }
        local_30 = 0x3f000000;
        local_2c = 10;
        local_34 = -(local_58 / local_54);
        FUN_004ebc60(local_38,0);
        FUN_004ec080(local_38);
      }
    }
    FUN_004f1fe0(param_2);
  }
  return;
}


