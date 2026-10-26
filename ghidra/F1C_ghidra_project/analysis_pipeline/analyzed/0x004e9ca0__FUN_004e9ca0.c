// Function: FUN_004e9ca0 @ 004e9ca0
// Size (bytes): 877


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e9ca0(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  char cVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int local_44;
  int local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined1 local_c [12];
  
  cVar4 = FUN_004bc340();
  if (cVar4 != '\0') {
    FUN_004efb20(&local_30,&local_18);
    FUN_004d1140(*param_1,&local_24,local_c);
    if (_DAT_0059e7f8 <=
        (local_24 - local_30) * (local_24 - local_30) +
        (local_20 - local_2c) * (local_20 - local_2c) +
        (local_1c - local_28) * (local_1c - local_28)) {
      iVar3 = DAT_005ea3f0 * 2;
      pfVar5 = (float *)FUN_00403640(param_1 + 0xd35,0);
      param_1[0xea7] = (int)pfVar5;
      fVar1 = pfVar5[0x11];
      iVar8 = 0;
      while (fVar1 != *(float *)(*param_1 + 0x4040)) {
        pfVar5 = (float *)pfVar5[0x43];
        if (iVar3 < iVar8) {
          return;
        }
        iVar8 = iVar8 + 1;
        fVar1 = pfVar5[0x11];
      }
      FUN_004d1140(*param_1,&local_30,&local_18);
      FUN_004ef6c0(&local_24,local_c,&local_3c);
      pfVar6 = (float *)FUN_00403640(&local_3c,0);
      pfVar7 = (float *)pfVar6[0x44];
      fVar1 = (*pfVar7 - *pfVar6) * (local_3c - *pfVar6) +
              (pfVar7[1] - pfVar6[1]) * (local_38 - pfVar6[1]) +
              (pfVar7[2] - pfVar6[2]) * (local_34 - pfVar6[2]);
      iVar8 = 0;
      while (fVar1 < DAT_0059e440) {
        pfVar6 = (float *)pfVar6[0x43];
        if (iVar3 < iVar8) {
          return;
        }
        pfVar7 = (float *)pfVar6[0x44];
        iVar8 = iVar8 + 1;
        fVar1 = (*pfVar7 - *pfVar6) * (local_3c - *pfVar6) +
                (pfVar7[1] - pfVar6[1]) * (local_38 - pfVar6[1]) +
                (pfVar7[2] - pfVar6[2]) * (local_34 - pfVar6[2]);
      }
      iVar8 = 0;
      pfVar7 = pfVar5;
      if ((char)param_1[0xd10] != '\0') {
        while (pfVar7 != pfVar6) {
          if (pfVar7[0x4b] == 0.0) {
            return;
          }
          bVar2 = iVar3 < iVar8;
          pfVar7 = (float *)pfVar7[0x44];
          iVar8 = iVar8 + 1;
          if (bVar2) {
            return;
          }
        }
      }
      param_1[0xd38] = local_18;
      param_1[0xd39] = local_14;
      param_1[0xd3a] = local_10;
      FUN_00566e40();
      local_44 = 1;
      local_40 = 0;
      do {
        param_1[0xd35] = (int)*pfVar5;
        param_1[0xd36] = (int)pfVar5[1];
        param_1[0xd37] = (int)pfVar5[2];
        FUN_004e9600();
        *(undefined4 *)(*param_1 + 0x4094) = 1;
        FUN_004e9a40(0);
        FUN_004e9bd0();
        FUN_0054fae0(0x8000000);
        if (DAT_008ad07c != 0) {
          FUN_0054fb40(1);
          FUN_0054f7a0(DAT_008ad07c,1);
          FUN_0054fb40(0);
        }
        if (DAT_008ad080 != 0) {
          FUN_0054fb40(1);
          FUN_0054f7a0(DAT_008ad080,1);
          FUN_0054fb40(0);
        }
        if (DAT_008ad084 != 0) {
          FUN_0054fb40(1);
          FUN_0054f7a0(DAT_008ad084,1);
          FUN_0054fb40(0);
        }
        if (local_44 == 1) {
          if (pfVar5 == pfVar6) {
            local_44 = 2;
          }
          pfVar7 = (float *)pfVar5[0x45];
          if ((pfVar7 == (float *)0x0) || (pfVar7[0x4b] != 1.4013e-45)) goto LAB_004e9fda;
        }
        else {
          if (pfVar5[0x11] == 0.0) break;
LAB_004e9fda:
          pfVar7 = (float *)pfVar5[0x44];
        }
        bVar2 = local_40 <= iVar3;
        pfVar5 = pfVar7;
        local_40 = local_40 + 1;
      } while (bVar2);
      FUN_0054fae0(0x8000000);
    }
  }
  return;
}


