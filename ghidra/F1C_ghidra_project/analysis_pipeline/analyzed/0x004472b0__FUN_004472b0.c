// Function: FUN_004472b0 @ 004472b0
// Size (bytes): 1220


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004472b0(int param_1,int param_2)

{
  int iVar1;
  double dVar2;
  float fVar3;
  float *pfVar4;
  double *pdVar5;
  int *piVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  double *local_68;
  int *local_64;
  int local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  piVar6 = &DAT_007c7810;
  pfVar4 = (float *)(param_2 + 0xf4);
  local_60 = 4;
  do {
    if (*(double *)(piVar6 + -8) <= _DAT_0059e430) {
      fVar8 = (float10)DAT_0059e440;
LAB_00447313:
      pfVar4[-1] = 0.0;
    }
    else {
      fVar8 = (float10)_DAT_0059e420 - (float10)*(double *)(piVar6 + -4);
      if (fVar8 <= (float10)_DAT_0059e974) goto LAB_00447313;
      pfVar4[-1] = (float)((fVar8 - (float10)_DAT_0059e974) * (float10)_DAT_0059eee8);
    }
    if (fVar8 <= (float10)_DAT_0059eee0) {
      *pfVar4 = 0.0;
    }
    else {
      *pfVar4 = (float)((fVar8 - (float10)_DAT_0059eee0) * (float10)_DAT_0059eed8);
    }
    pfVar4[3] = *pfVar4;
    pfVar4[2] = pfVar4[-1];
    fVar3 = (float)__ftol();
    pfVar4[5] = fVar3;
    dVar2 = _DAT_0059e430;
    if (_DAT_0059e430 < *(double *)(piVar6 + -8)) {
      dVar2 = *(double *)(piVar6 + 0x45);
    }
    pfVar4[1] = (float)dVar2;
    fVar3 = DAT_0059e440;
    pfVar4[4] = 0.0;
    if (fVar3 < (float)dVar2) {
      pfVar4[-1] = 0.0;
      pfVar4[2] = 0.0;
      pfVar4[3] = 0.0;
    }
    if (piVar6[0x42] != 0) {
      iVar7 = *piVar6;
      local_48 = (float)*(double *)(iVar7 + 0x14);
      local_4c = (float)*(double *)(iVar7 + 0xc);
      local_50 = (float)*(double *)(iVar7 + 4);
      local_54 = (float)*(double *)(iVar7 + 0x74);
      local_58 = (float)*(double *)(iVar7 + 0x6c);
      local_5c = (float)*(double *)(iVar7 + 100);
      FUN_004ce3e0(pfVar4 + -8,(float)*(double *)(param_1 + 0x60),&local_50,&local_5c,piVar6[0x42],
                   *(undefined4 *)(*(int *)(param_1 + 0x1f00) + 0x4894));
    }
    piVar6 = piVar6 + 0x119;
    pfVar4 = pfVar4 + 0x4a;
    local_60 = local_60 + -1;
    if (local_60 == 0) {
      if (((*(double *)(param_1 + 0x1de4) == _DAT_0059e430) &&
          (*(double *)(param_1 + 0x1dec) == _DAT_0059e430)) &&
         (*(double *)(param_1 + 0x1df4) == _DAT_0059e430)) {
        *(undefined4 *)(param_2 + 0x98) = 0;
        *(undefined4 *)(param_2 + 0xac) = 0;
        *(undefined4 *)(param_2 + 0xc0) = 0;
      }
      else {
        iVar7 = *(int *)(param_1 + 0x15f0);
        FUN_0043aee0(iVar7 + 4,param_1 + 0x1dfc,&local_38);
        local_50 = (float)local_38;
        local_4c = (float)local_30;
        local_48 = (float)local_28;
        local_54 = (float)*(double *)(iVar7 + 0x74);
        local_58 = (float)*(double *)(iVar7 + 0x6c);
        local_5c = (float)*(double *)(iVar7 + 100);
        fVar8 = ((float10)_DAT_0059e428 / (float10)*(double *)(param_1 + 0x1cdc)) *
                (float10)*(double *)(param_1 + 0x1c5c) * (float10)*(double *)(param_1 + 8);
        if ((float10)_DAT_0059e428 <= fVar8) {
          if ((float10)_DAT_0059e430 < fVar8) {
            fVar8 = (float10)_DAT_0059e430;
          }
        }
        else {
          fVar8 = (float10)_DAT_0059e428;
        }
        if (*(double *)(param_1 + 0x1de4) <= _DAT_0059e430) {
          fVar9 = fVar8 * (float10)*(double *)(param_1 + 0x1de4);
        }
        else {
          fVar9 = (float10)*(double *)(param_1 + 0x1de4);
        }
        *(float *)(param_2 + 0x98) = (float)fVar9;
        if (*(double *)(param_1 + 0x1dec) <= _DAT_0059e430) {
          fVar9 = fVar8 * (float10)*(double *)(param_1 + 0x1dec);
        }
        else {
          fVar9 = (float10)*(double *)(param_1 + 0x1dec);
        }
        *(float *)(param_2 + 0xac) = (float)fVar9;
        if (*(double *)(param_1 + 0x1df4) <= _DAT_0059e430) {
          fVar8 = fVar8 * (float10)*(double *)(param_1 + 0x1df4);
        }
        else {
          fVar8 = (float10)*(double *)(param_1 + 0x1df4);
        }
        *(float *)(param_2 + 0xc0) = (float)fVar8;
        FUN_004ce930((float *)(param_2 + 0x98),(float)*(double *)(param_1 + 0x60),&local_50,
                     &local_5c,*(undefined4 *)(*(int *)(param_1 + 0x1f00) + 0x4894));
      }
      local_60 = param_1 + 0x1660;
      local_64 = (int *)(param_1 + 0x16e0);
      local_68 = (double *)(param_1 + 0x16f0);
      iVar7 = 0;
      do {
        if (((*local_68 < _DAT_0059e430) && (*local_64 != 0)) &&
           (*(int *)(*(int *)(*local_64 + 0x54) + 0x28) != 0)) {
          iVar1 = *(int *)(param_1 + 0x15f0);
          FUN_0043aee0(iVar1 + 4,local_60,&local_20);
          fVar8 = (float10)local_20 - (float10)*(double *)(iVar1 + 4);
          fVar9 = (float10)local_18 - (float10)*(double *)(iVar1 + 0xc);
          fVar10 = (float10)local_10 - (float10)*(double *)(iVar1 + 0x14);
          local_38 = (double)(fVar10 * (float10)*(double *)(iVar1 + 0x84) -
                             fVar9 * (float10)*(double *)(iVar1 + 0x8c)) + *(double *)(iVar1 + 100);
          local_30 = (double)(fVar8 * (float10)*(double *)(iVar1 + 0x8c) -
                             fVar10 * (float10)*(double *)(iVar1 + 0x7c)) +
                     *(double *)(iVar1 + 0x6c);
          fVar8 = (fVar9 * (float10)*(double *)(iVar1 + 0x7c) -
                  fVar8 * (float10)*(double *)(iVar1 + 0x84)) + (float10)*(double *)(iVar1 + 0x74);
          if ((float10)_DAT_0059eca8 <
              fVar8 * fVar8 +
              (float10)local_30 * (float10)local_30 + (float10)local_38 * (float10)local_38) {
            local_44 = (float)((float10)local_38 * (float10)_DAT_0059e880);
            local_40 = (float)((float10)local_30 * (float10)_DAT_0059e880 + (float10)_DAT_0059e7e0);
            local_3c = (float)(fVar8 * (float10)_DAT_0059e880);
            FUN_004ef560(iVar7,0xf,10,&local_44);
          }
        }
        iVar7 = iVar7 + 1;
        local_68 = local_68 + 1;
        local_64 = local_64 + 1;
        local_60 = local_60 + 0x18;
      } while (iVar7 < 4);
      pfVar4 = (float *)(param_2 + 0x1e8);
      pdVar5 = (double *)(param_1 + 0x690);
      iVar7 = 4;
      do {
        fVar8 = ((float10)*pdVar5 - (float10)_DAT_0059eec8) * (float10)_DAT_0059eec0;
        if ((float10)DAT_0059e440 <= fVar8) {
          if ((float10)_DAT_0059e43c < fVar8) {
            fVar8 = (float10)_DAT_0059e43c;
          }
        }
        else {
          fVar8 = (float10)DAT_0059e440;
        }
        *pfVar4 = (float)fVar8;
        pdVar5 = (double *)((int)pdVar5 + 0x464);
        pfVar4 = pfVar4 + 0x4a;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      return;
    }
  } while( true );
}


