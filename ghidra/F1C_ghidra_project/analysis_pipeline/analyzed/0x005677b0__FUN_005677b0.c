// Function: FUN_005677b0 @ 005677b0
// Size (bytes): 314


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_005677b0(int param_1,int param_2)

{
  undefined8 uVar1;
  double dVar2;
  undefined8 *puVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = 0;
  if (0 < param_2) {
    do {
      iVar7 = *(int *)(param_1 + iVar6 * 4);
      iVar4 = iVar6;
      if (*(double *)(iVar7 + iVar6 * 8) == _DAT_0059e430) {
        do {
          iVar4 = iVar4 + 1;
          if (param_2 <= iVar4) break;
        } while (*(double *)(*(int *)(param_1 + iVar4 * 4) + iVar6 * 8) == _DAT_0059e430);
        if (iVar4 == param_2) {
          return 0xffffffff;
        }
        iVar4 = *(int *)(param_1 + iVar4 * 4);
        if (iVar6 <= param_2) {
          puVar3 = (undefined8 *)(iVar4 + iVar6 * 8);
          iVar7 = iVar7 - iVar4;
          iVar4 = (param_2 - iVar6) + 1;
          do {
            uVar1 = *(undefined8 *)(iVar7 + (int)puVar3);
            *(undefined4 *)(iVar7 + (int)puVar3) = *(undefined4 *)puVar3;
            *(undefined4 *)(iVar7 + 4 + (int)puVar3) = *(undefined4 *)((int)puVar3 + 4);
            *puVar3 = uVar1;
            puVar3 = puVar3 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
      iVar7 = *(int *)(param_1 + iVar6 * 4);
      if ((*(int *)(iVar7 + iVar6 * 8) != 0) || (*(int *)(iVar7 + 4 + iVar6 * 8) != 0x3ff00000)) {
        dVar2 = _DAT_0059e420 / *(double *)(iVar7 + iVar6 * 8);
        iVar4 = iVar6 + 1;
        while (iVar4 <= param_2) {
          iVar8 = iVar4 * 8;
          iVar4 = iVar4 + 1;
          *(double *)(iVar7 + -8 + iVar4 * 8) = dVar2 * *(double *)(iVar7 + iVar8);
        }
      }
      iVar7 = 0;
      do {
        if ((iVar6 != iVar7) &&
           (iVar4 = *(int *)(param_1 + iVar7 * 4), *(double *)(iVar4 + iVar6 * 8) != _DAT_0059e430))
        {
          dVar2 = *(double *)(iVar4 + iVar6 * 8);
          iVar8 = iVar6 + 1;
          if (iVar8 <= param_2) {
            pdVar5 = (double *)(iVar4 + iVar8 * 8);
            iVar4 = *(int *)(param_1 + iVar6 * 4) - iVar4;
            iVar8 = (param_2 - iVar8) + 1;
            do {
              if (*(double *)((int)pdVar5 + iVar4) != _DAT_0059e430) {
                *pdVar5 = -dVar2 * *(double *)((int)pdVar5 + iVar4) + *pdVar5;
              }
              pdVar5 = pdVar5 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_2);
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_2);
  }
  return 0;
}


