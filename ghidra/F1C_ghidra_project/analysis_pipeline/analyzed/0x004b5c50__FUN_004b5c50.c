// Function: FUN_004b5c50 @ 004b5c50
// Size (bytes): 330


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b5c50(int param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int local_4;
  
  piVar5 = (int *)(param_1 + 0x44);
  local_4 = 0x68;
  do {
    piVar4 = (int *)*piVar5;
    piVar5[1] = (int)piVar4;
    if ((piVar4 == (int *)0x0) || (iVar6 = *piVar4, iVar6 == 0)) {
LAB_004b5cb3:
      if (*(int *)(param_2 + 13000) != -1) {
        piVar4 = *(int **)(param_1 + 0x10);
        iVar6 = 0;
        *(int **)(param_1 + 0x18) = piVar4;
        if (piVar4 != (int *)0x0) {
          iVar6 = *piVar4;
          *(undefined1 *)(piVar4 + 2) = 0;
          cVar1 = FUN_004ba830(iVar6,1);
          if (cVar1 == '\0') {
            iVar6 = 0;
          }
        }
        if (iVar6 == 0) {
          pvVar2 = operator_new(4);
          if (pvVar2 == (void *)0x0) {
            uVar3 = 0;
          }
          else {
            uVar3 = FUN_004baa50(0);
          }
          FUN_004baf10(uVar3,0);
          iVar6 = FUN_004bb0c0();
        }
        FUN_004b51e0(param_2);
        *(float *)(iVar6 + 0x84) = (float)_DAT_008afea0;
        piVar4 = operator_new(0xc);
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          *piVar4 = iVar6;
          piVar4[1] = 0;
          *(undefined1 *)(piVar4 + 2) = 0;
        }
        if (piVar5[-1] == 0) {
          piVar5[-1] = (int)piVar4;
          piVar5[1] = (int)piVar4;
        }
        else {
          *(int **)(*piVar5 + 4) = piVar4;
        }
        *piVar5 = (int)piVar4;
        piVar5[2] = piVar5[2] + 1;
      }
    }
    else {
      cVar1 = FUN_004b5120(param_2);
      if (cVar1 == '\0') {
        if (*(float *)(iVar6 + 0x88) == DAT_005acd10) {
          *(float *)(iVar6 + 0x88) = (float)_DAT_008afea0;
        }
        goto LAB_004b5cb3;
      }
    }
    param_2 = param_2 + 0x48c0;
    piVar5 = piVar5 + 4;
    local_4 = local_4 + -1;
    if (local_4 == 0) {
      return;
    }
  } while( true );
}


