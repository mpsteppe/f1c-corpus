// Function: FUN_004fe820 @ 004fe820
// Strings:  [Could not write to file %s, D:\dev\F1_1999_2002\Source\weather.cpp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004fe820(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  float10 fVar9;
  float local_10;
  
  iVar6 = FUN_00587db0(param_2,&DAT_005c2ab0);
  if (iVar6 != 0) {
    FUN_005887b1(iVar6,s_Weather_005d7100);
    FUN_005887b1(iVar6,&DAT_005c4060);
    iVar8 = 0;
    do {
      uVar7 = FUN_0042ce30();
      FUN_005887b1(iVar6,&DAT_005d70f8,uVar7);
      FUN_005887b1(iVar6,&DAT_005d70f4);
      fVar9 = (float10)FUN_004fb910();
      fVar2 = DAT_0059e440;
      fVar1 = (float)fVar9;
      *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x3c);
      local_10 = 0.0;
      while (fVar2 < fVar1) {
        FUN_004fdeb0(0x41200000,local_10,0);
        local_10 = local_10 + _DAT_0059e5fc;
        fVar2 = local_10;
      }
      pfVar3 = *(float **)(param_1 + 0x38);
      pfVar4 = (float *)pfVar3[3];
      if ((pfVar4 == (float *)0x0) || (*pfVar4 < *pfVar3 != (*pfVar4 == *pfVar3))) {
        fVar2 = pfVar3[2];
      }
      else {
        fVar2 = (pfVar4[2] - pfVar3[2]) * ((fVar1 - *pfVar3) / (*pfVar4 - *pfVar3)) + pfVar3[2];
      }
      FUN_005887b1(iVar6,s_Conditions___2f_005d70e0,(double)(fVar2 * _DAT_0059e6f8));
      FUN_005887b1(iVar6,s_OnPathWetness___2f_005d70c8,
                   (double)(*(float *)(param_1 + 0x28) * _DAT_0059e6f8));
      FUN_005887b1(iVar6,s_OffPathWetness___2f_005d70b0,
                   (double)(*(float *)(param_1 + 0x2c) * _DAT_0059e6f8));
      FUN_005887b1(iVar6,s_AmbientTemp___2f_005d709c,(double)*(float *)(param_1 + 0x30));
      FUN_005887b1(iVar6,s_TrackTemp___2f_005d7088,(double)*(float *)(param_1 + 0x34));
      pfVar3 = *(float **)(*(int *)(param_1 + 0x38) + 0xc);
      *(float **)(param_1 + 0x38) = pfVar3;
      while ((pfVar3 != (float *)0x0 &&
             (fVar2 = (*pfVar3 - fVar1) * _DAT_0059e9c0, fVar2 <= _DAT_005acb08))) {
        FUN_005887b1(iVar6,s_Minute___2f_005d7078,(double)fVar2);
        FUN_005887b1(iVar6,&DAT_005d7070);
        FUN_005887b1(iVar6,s_Conditions___2f_005d705c,
                     (double)(*(float *)(*(int *)(param_1 + 0x38) + 8) * _DAT_0059e6f8));
        FUN_005887b1(iVar6,s_AmbientTemp___2f_005d7044,
                     (double)*(float *)(*(int *)(param_1 + 0x38) + 4));
        FUN_005887b1(iVar6,&DAT_005d703c);
        pfVar3 = *(float **)(*(int *)(param_1 + 0x38) + 0xc);
        *(float **)(param_1 + 0x38) = pfVar3;
      }
      FUN_005887b1();
      iVar8 = iVar8 + 1;
    } while (iVar8 < 8);
    FUN_005887b1(iVar6,&DAT_005d7034);
    FUN_00587d02(iVar6);
    return 0;
  }
  cVar5 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_weath_005d7128,0x836);
  if (cVar5 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Could_not_write_to_file__s_005d710c,param_2);
  }
  return 0xffffffff;
}


