// Function: FUN_004cc840 @ 004cc840
// Size (bytes): 296


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004cc840(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  
  iVar6 = FUN_0040c870();
  fVar3 = *(float *)(iVar6 + 0x28);
  fVar4 = *(float *)(iVar6 + 0x24) * _DAT_005aceac;
  fVar5 = *(float *)(iVar6 + 0x2c) * _DAT_005aceac;
  pfVar7 = (float *)&DAT_008ac840;
  do {
    pfVar1 = pfVar7 + -1;
    pfVar7[-4] = fVar4;
    pfVar7[-3] = (pfVar7[-5] - fVar3) * _DAT_0059ed18;
    pfVar7[-2] = fVar5;
    *pfVar1 = pfVar7[-3] * pfVar7[-6] - pfVar7[-2] * pfVar7[-7];
    *pfVar7 = pfVar7[-2] * pfVar7[-8] - pfVar7[-4] * pfVar7[-6];
    pfVar7[1] = pfVar7[-4] * pfVar7[-7] - pfVar7[-3] * pfVar7[-8];
    fVar2 = pfVar7[1] * pfVar7[1] + *pfVar1 * *pfVar1 + *pfVar7 * *pfVar7;
    if (fVar2 < DAT_0059e440 == (fVar2 == DAT_0059e440)) {
      fVar2 = (*(float *)(param_1 + 0x10) * _DAT_0059e450) / SQRT(fVar2);
      *pfVar1 = fVar2 * *pfVar1;
      *pfVar7 = fVar2 * *pfVar7;
      pfVar7[1] = fVar2 * pfVar7[1];
    }
    else {
      fVar2 = *(float *)(param_1 + 0x10);
      *pfVar1 = 0.0;
      fVar2 = fVar2 * _DAT_0059e450;
      pfVar7[1] = 0.0;
      *pfVar7 = fVar2;
    }
    pfVar7 = pfVar7 + 10;
  } while ((int)pfVar7 < 0x8acac0);
  return;
}


