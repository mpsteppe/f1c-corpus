// Function: FUN_00541a70 @ 00541a70
// Size (bytes): 245


void __fastcall FUN_00541a70(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  float *pfVar7;
  int iVar8;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  float fStack_44;
  undefined4 local_40 [16];
  
  puVar6 = local_40;
  puVar3 = (undefined4 *)(param_1 + 0x15c);
  iVar8 = 4;
  do {
    iVar5 = 4;
    puVar4 = puVar6;
    do {
      *puVar4 = *puVar3;
      puVar4 = puVar4 + 4;
      puVar3 = puVar3 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar6 = puVar6 + 1;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  pfVar7 = (float *)(param_1 + 0x104);
  do {
    (**(code **)*DAT_008b8f24)(DAT_008b8f24,pfVar7 + -0x1a,pfVar7 + -2,local_40);
    if (iVar8 < 4) {
      fVar2 = *pfVar7 * *(float *)(param_1 + 0x2c) + pfVar7[-1] * *(float *)(param_1 + 0x28);
      fVar1 = *(float *)(param_1 + 0x24);
    }
    else {
      fStack_44 = pfVar7[-0x17];
      uStack_48 = 0;
      uStack_4c = 0;
      (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,&uStack_4c,&fStack_58,local_40);
      fVar1 = fStack_58 + *(float *)(param_1 + 0x24);
      fStack_54 = fStack_54 + *(float *)(param_1 + 0x28);
      fStack_50 = fStack_50 + *(float *)(param_1 + 0x2c);
      fVar2 = fStack_50 * *pfVar7 + fStack_54 * pfVar7[-1];
      fStack_58 = fVar1;
    }
    iVar8 = iVar8 + 1;
    pfVar7[1] = fVar1 * pfVar7[-2] + fVar2;
    pfVar7 = pfVar7 + 4;
  } while (iVar8 < 6);
  return;
}


