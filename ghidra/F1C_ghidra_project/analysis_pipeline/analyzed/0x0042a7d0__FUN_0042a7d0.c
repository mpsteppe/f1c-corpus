// Function: FUN_0042a7d0 @ 0042a7d0
// Size (bytes): 1170


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0042a7d0(int *param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  
  piVar4 = param_1 + 0x106d;
  piVar6 = param_1 + 0x10b3;
  iVar8 = 5;
  do {
    piVar4[-3] = 0x497423f0;
    *piVar6 = 0;
    *piVar4 = -1;
    piVar4[-0x10] = 0;
    piVar6 = piVar6 + 7;
    piVar4 = piVar4 + 0x11;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  piVar4 = (int *)FUN_004a4710(param_1[1]);
  if (piVar4 == (int *)0x0) {
    if (0 < DAT_005c329c) {
      iVar8 = 0;
      do {
        iVar5 = (&DAT_007c54f0)[iVar8];
        if (*param_1 != iVar5) {
          if (*(int *)(iVar5 + 0x4550) < DAT_005ea2cc) {
            fVar1 = *(float *)(iVar5 + 0x34e0) - (float)param_1[0xd38];
            fVar2 = *(float *)(iVar5 + 0x34e8) - (float)param_1[0xd3a];
            fVar1 = fVar1 * fVar1 + fVar2 * fVar2;
            cVar3 = FUN_004c7bd0();
            if ((((cVar3 != '\0') && (fVar1 < _DAT_0059e988)) && (DAT_007c56a4 == 7)) &&
               (param_1[0x100f] < *(int *)((&DAT_007c54f0)[iVar8] + 0x403c))) {
              param_1[0x117f] = (&DAT_007c54f0)[iVar8];
              if ((*(float *)((&DAT_007c54f0)[iVar8] + 0x34e8) - (float)param_1[0xd3a]) *
                  (float)param_1[0x1123] -
                  (*(float *)((&DAT_007c54f0)[iVar8] + 0x34e0) - (float)param_1[0xd38]) *
                  (float)param_1[0x1125] <= DAT_0059e440) {
                param_1[0x1108] = -0x3fe00000;
              }
              else {
                param_1[0x1108] = 0x40200000;
              }
            }
            if (((float)param_1[0x10ae] <= fVar1) ||
               (fVar9 = (float10)FUN_00423ad0(), (float10)_DAT_0059e984 <= fVar9)) {
              if ((float)param_1[0x106a] <= fVar1) {
                if ((float)param_1[0x107b] <= fVar1) {
                  if ((float)param_1[0x108c] <= fVar1) {
                    if ((float)param_1[0x109d] <= fVar1) {
                      if (fVar1 < (float)param_1[0x10ae]) {
                        param_1[0x10ae] = (int)fVar1;
                        param_1[0x10a1] = (&DAT_007c54f0)[iVar8];
                      }
                    }
                    else {
                      param_1[0x10ae] = param_1[0x109d];
                      param_1[0x10a1] = param_1[0x1090];
                      param_1[0x109d] = (int)fVar1;
                      param_1[0x1090] = (&DAT_007c54f0)[iVar8];
                    }
                  }
                  else {
                    param_1[0x10ae] = param_1[0x109d];
                    param_1[0x10a1] = param_1[0x1090];
                    param_1[0x109d] = param_1[0x108c];
                    param_1[0x1090] = param_1[0x107f];
                    param_1[0x108c] = (int)fVar1;
                    param_1[0x107f] = (&DAT_007c54f0)[iVar8];
                  }
                }
                else {
                  param_1[0x10ae] = param_1[0x109d];
                  param_1[0x10a1] = param_1[0x1090];
                  param_1[0x109d] = param_1[0x108c];
                  param_1[0x1090] = param_1[0x107f];
                  param_1[0x108c] = param_1[0x107b];
                  param_1[0x107f] = param_1[0x106e];
                  param_1[0x107b] = (int)fVar1;
                  param_1[0x106e] = (&DAT_007c54f0)[iVar8];
                }
              }
              else {
                param_1[0x10ae] = param_1[0x109d];
                param_1[0x10a1] = param_1[0x1090];
                param_1[0x109d] = param_1[0x108c];
                param_1[0x1090] = param_1[0x107f];
                param_1[0x108c] = param_1[0x107b];
                param_1[0x107f] = param_1[0x106e];
                param_1[0x107b] = param_1[0x106a];
                param_1[0x106e] = param_1[0x105d];
                param_1[0x106a] = (int)fVar1;
                param_1[0x105d] = (&DAT_007c54f0)[iVar8];
              }
            }
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < DAT_005c329c);
    }
  }
  else {
    param_1[0x106a] = 0x3f800000;
    param_1[0x105d] = *piVar4;
  }
  piVar4 = param_1 + 0x105d;
  iVar8 = 5;
  do {
    if ((*piVar4 != 0) && ((float)piVar4[0xd] < _DAT_0059e980)) {
      iVar5 = 0;
      piVar6 = param_1 + 0x10b4;
      do {
        if (*(int *)(*piVar4 + 0x4894) == *piVar6) {
          param_1[iVar5 * 7 + 0x10b3] = 1;
          piVar4[0x10] = iVar5;
          break;
        }
        iVar5 = iVar5 + 1;
        piVar6 = piVar6 + 7;
      } while (iVar5 < 5);
    }
    piVar4 = piVar4 + 0x11;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  piVar4 = param_1 + 0x106d;
  iVar8 = 5;
  do {
    if (((float)piVar4[-3] <= _DAT_0059e980) && (*piVar4 == -1)) {
      iVar5 = *(int *)(piVar4[-0x10] + 0x4894);
      iVar7 = 0;
      piVar6 = param_1 + 0x10b3;
      do {
        if (*piVar6 == 0) {
          param_1[iVar7 * 7 + 0x10b6] = -0x39e3c400;
          param_1[iVar7 * 7 + 0x10b2] = -1;
          param_1[iVar7 * 7 + 0x10b7] = 0;
          param_1[iVar7 * 7 + 0x10b4] = iVar5;
          param_1[iVar7 * 7 + 0x10b3] = 1;
          *piVar4 = iVar7;
          break;
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 7;
      } while (iVar7 < 5);
    }
    piVar4 = piVar4 + 0x11;
    iVar8 = iVar8 + -1;
    if (iVar8 == 0) {
      if ((char)param_1[0x115e] != '\0') {
        *(undefined1 *)(param_1 + 0x115e) = 0;
        param_1 = param_1 + 0x10b7;
        iVar8 = 5;
        do {
          *param_1 = 0x43fa0000;
          param_1 = param_1 + 7;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      return;
    }
  } while( true );
}


