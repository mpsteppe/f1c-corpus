// Function: FUN_0055ee20 @ 0055ee20
// Size (bytes): 143


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0055ee20(undefined4 param_1,undefined4 param_2,int param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  bool bVar15;
  undefined4 in_EAX;
  int iVar16;
  int iVar17;
  float *pfVar18;
  float *pfVar19;
  
  _DAT_005dc470 = *(int *)(param_3 + 8);
  pfVar18 = *(float **)(param_3 + 0xc);
  pfVar19 = *(float **)(param_3 + 0x3c);
  iVar16 = _DAT_005dc470;
  do {
    fVar1 = param_4[1];
    fVar2 = *pfVar18;
    fVar3 = param_4[2];
    fVar4 = *pfVar18;
    fVar5 = param_4[5];
    fVar6 = pfVar18[1];
    fVar7 = param_4[6];
    fVar8 = pfVar18[1];
    fVar9 = param_4[9];
    fVar10 = pfVar18[2];
    fVar11 = param_4[10];
    fVar12 = pfVar18[2];
    fVar13 = param_4[0xd];
    fVar14 = param_4[0xe];
    *pfVar19 = param_4[8] * pfVar18[2] + param_4[4] * pfVar18[1] + *param_4 * *pfVar18 +
               param_4[0xc];
    pfVar19[2] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4 + fVar14;
    pfVar19[1] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2 + fVar13;
    pfVar18 = pfVar18 + 0xc;
    pfVar19 = pfVar19 + 6;
    iVar17 = iVar16 + -1;
    bVar15 = 0 < iVar16;
    iVar16 = iVar17;
  } while (iVar17 != 0 && bVar15);
  return CONCAT44(param_2,in_EAX);
}


