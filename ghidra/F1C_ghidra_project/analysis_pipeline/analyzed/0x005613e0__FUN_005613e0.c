// Function: FUN_005613e0 @ 005613e0
// Size (bytes): 566


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005613e0(float *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int *piVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  float10 fVar13;
  int iStack_28;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = *(int *)param_1[3];
  param_1[1] = 0.0;
  if (((uint)param_1[9] & 4) == 0) {
    fVar8 = param_1[6];
    if ((*(byte *)(*(int *)((int)fVar8 + 0x138) + 0x3c) & 2) == 0) {
      if ((*(uint *)((int)fVar8 + 0x14) & 0x20000000) == 0) {
        (**(code **)(*DAT_008b8f24 + 4))
                  (DAT_008b8f24,(int)fVar8 + 0xdc,(int)fVar8 + 0xe8,
                   *(int *)((int)fVar8 + 0x138) + 0x114);
        *(uint *)((int)param_1[6] + 0x14) = *(uint *)((int)param_1[6] + 0x14) | 0x20000000;
      }
      FUN_005414c0();
      fVar8 = (float)FUN_00541470();
      param_1[2] = fVar8;
      fVar13 = (float10)FUN_005565b0();
      if ((float10)*param_1 < fVar13 == ((float10)*param_1 == fVar13)) {
        fVar2 = param_1[3];
        fVar3 = *(float *)((int)fVar2 + 0xc);
        fVar4 = *(float *)((int)fVar2 + 0x14);
        fVar5 = _DAT_0059e43c / (float)*(int *)((int)fVar2 + 0x54);
        iStack_28 = 0;
        fVar6 = _DAT_0059e43c / (float)*(int *)((int)fVar2 + 0x58);
        fVar8 = *(float *)((int)fVar2 + 0x10);
        fVar2 = *(float *)((int)fVar2 + 0x18);
        piVar9 = (int *)param_1[8];
        if (0 < *piVar9) {
          do {
            iVar1 = *(int *)(piVar9[1] + iStack_28 * 4);
            iVar12 = 0;
            do {
              pfVar10 = (float *)((uint)*(ushort *)(iVar1 + iVar12 * 2) * 0x30 +
                                 *(int *)(*(int *)(iVar1 + 8) + 0xc));
              *(float *)param_1[2] = pfVar10[3] * _DAT_0059e448 + *pfVar10;
              *(float *)((int)param_1[2] + 4) = pfVar10[4] * _DAT_0059e448 + pfVar10[1];
              *(float *)((int)param_1[2] + 8) = pfVar10[5] * _DAT_0059e448 + pfVar10[2];
              *(float *)((int)param_1[2] + 0xc) = pfVar10[6];
              (**(code **)(*DAT_008b8f24 + 4))
                        (DAT_008b8f24,pfVar10,&fStack_c,(int)param_1[3] + 0x15c);
              fVar7 = _DAT_0059e43c / fStack_4;
              *(float *)((int)param_1[2] + 0x10) = (fStack_c * fVar7 * fVar3 + fVar4) * fVar5;
              *(float *)((int)param_1[2] + 0x14) = (fStack_8 * fVar7 * -fVar8 + fVar2) * fVar6;
              iVar12 = iVar12 + 1;
              param_1[2] = (float)((int)param_1[2] + 0x18);
            } while (iVar12 < 3);
            piVar9 = (int *)param_1[8];
            param_1[1] = (float)((int)param_1[1] + 3);
            iStack_28 = iStack_28 + 1;
          } while (iStack_28 < *piVar9);
        }
      }
      else {
        FUN_00556440();
        *(undefined4 *)param_1[8] = 0;
        iVar12 = 0;
        if (0 < *(int *)(iVar1 + 0x13c)) {
          iVar11 = 0;
          do {
            FUN_00561620(*(undefined4 *)(iVar11 + 0x10 + *(int *)(iVar1 + 0x140)));
            iVar12 = iVar12 + 1;
            iVar11 = iVar11 + 0x18;
          } while (iVar12 < *(int *)(iVar1 + 0x13c));
          FUN_005414a0();
          return;
        }
      }
      FUN_005414a0();
    }
  }
  return;
}


