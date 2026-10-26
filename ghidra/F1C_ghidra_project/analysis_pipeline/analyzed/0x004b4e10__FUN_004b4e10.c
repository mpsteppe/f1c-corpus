// Function: FUN_004b4e10 @ 004b4e10
// Size (bytes): 306


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b4e10(undefined1 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int local_4;
  
  *(float *)(param_1 + 0x6c) = (float)_DAT_008afea0;
  piVar9 = (int *)(param_1 + 0x70);
  local_4 = 4;
  do {
    piVar1 = (int *)*piVar9;
    piVar9[2] = (int)piVar1;
    if (piVar1 != (int *)0x0) {
      iVar7 = *piVar1;
      while (iVar7 != 0) {
        piVar5 = (int *)*piVar9;
        piVar1 = (int *)0x0;
        while (piVar2 = piVar5, piVar2 != (int *)0x0) {
          if (*piVar2 == iVar7) {
            if (piVar2 == (int *)piVar9[2]) {
              piVar9[2] = piVar2[1];
            }
            if (piVar1 == (int *)0x0) {
              *piVar9 = piVar2[1];
            }
            else {
              piVar1[1] = piVar2[1];
            }
            if ((int *)piVar9[1] == piVar2) {
              piVar9[1] = (int)piVar1;
            }
            piVar9[3] = piVar9[3] + -1;
            if ((char)piVar2[2] != '\0') {
              FUN_00587bcf(*piVar2);
            }
            FUN_00587bcf(piVar2);
            break;
          }
          piVar1 = piVar2;
          piVar5 = (int *)piVar2[1];
        }
        pvVar6 = operator_new(0xc);
        if (pvVar6 == (void *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar7 = FUN_004bac20(iVar7,0);
        }
        iVar3 = iVar7;
        iVar4 = iVar7;
        if (DAT_008ab700 != 0) {
          *(int *)(iVar7 + 4) = DAT_008ab700;
          iVar3 = _DAT_008ab704;
          iVar4 = DAT_008ab708;
        }
        DAT_008ab708 = iVar4;
        _DAT_008ab704 = iVar3;
        DAT_008ab70c = DAT_008ab70c + 1;
        piVar1 = (int *)*piVar9;
        DAT_008ab700 = iVar7;
        piVar9[2] = (int)piVar1;
        if (piVar1 == (int *)0x0) break;
        iVar7 = *piVar1;
      }
    }
    piVar9 = piVar9 + 4;
    local_4 = local_4 + -1;
    if (local_4 == 0) {
      iVar7 = 4;
      puVar8 = (undefined4 *)(param_1 + 0x35);
      do {
        puVar8[-0xd] = 0;
        puVar8[-0xc] = 0;
        puVar8[-0xb] = 0;
        *(undefined1 *)(puVar8 + -10) = 0;
        *puVar8 = 0;
        puVar8[1] = 0;
        puVar8[2] = 0;
        iVar7 = iVar7 + -1;
        *(undefined1 *)(puVar8 + 3) = 0;
        puVar8 = (undefined4 *)((int)puVar8 + 0xd);
      } while (iVar7 != 0);
      *param_1 = 1;
      return;
    }
  } while( true );
}


