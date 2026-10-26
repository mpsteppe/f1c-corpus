// Function: FUN_0057e0a0 @ 0057e0a0
// Strings:  [Drop Flag Set, Drop Flag Set, Maint Drop - conET=(%8.4f) lastActivity=(%8.4f) dt=(%8.4f)]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0057e0a0(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  float fVar4;
  DWORD DVar5;
  char *pcVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  float10 fVar10;
  char local_98 [132];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0059c9db;
  local_14 = ExceptionList;
  param_2 = *(float *)(param_1 + 0xaa4) - param_2;
  ExceptionList = &local_14;
  *(float *)(param_1 + 0xaa4) = param_2;
  if (param_2 <= DAT_0059e440) {
    *(undefined4 *)(param_1 + 0xaa4) = 0x3d4ccccd;
    fVar10 = (float10)FUN_00584f90();
    fVar1 = (float)fVar10;
    fVar2 = *(float *)(param_1 + 0xe8);
    piVar8 = (int *)(param_1 + 0xaac);
    if ((*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) ||
       ((DVar5 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xabc),*(DWORD *)(param_1 + 0xac0)),
        DVar5 != 0 && (DVar5 != 0x80)))) {
      piVar8 = (int *)0x0;
    }
    piVar7 = (int *)*piVar8;
    piVar8[2] = (int)piVar7;
    if (piVar7 != (int *)0x0) {
      iVar9 = *piVar7;
      while (iVar9 != 0) {
        fVar4 = fVar1 - *(float *)(iVar9 + 0x2c);
        local_c = 0;
        if (fVar4 <= fVar2) {
          if (*(char *)(iVar9 + 0x28) != '\0') {
            pcVar6 = s_Drop_Flag_Set_005e62e0;
            do {
              cVar3 = *pcVar6;
              (&stack0xffa19c88)[(int)pcVar6] = cVar3;
              pcVar6 = pcVar6 + 1;
            } while (cVar3 != '\0');
            goto LAB_0057e1b6;
          }
          if ((fVar2 * _DAT_0059e450 < fVar4) &&
             (fVar2 * _DAT_0059e7e8 < fVar1 - *(float *)(iVar9 + 0x30))) {
            FUN_004b3db0();
            FUN_0057dbb0();
            *(float *)(iVar9 + 0x30) = fVar1;
          }
          if (piVar8[2] != 0) {
            piVar7 = *(int **)(piVar8[2] + 4);
            piVar8[2] = (int)piVar7;
            goto LAB_0057e23a;
          }
LAB_0057e242:
          iVar9 = 0;
        }
        else {
          FUN_0058815f();
LAB_0057e1b6:
          FUN_0057de30();
          piVar7 = (int *)piVar8[2];
LAB_0057e23a:
          if (piVar7 == (int *)0x0) goto LAB_0057e242;
          iVar9 = *piVar7;
        }
        local_c = 0xffffffff;
      }
    }
    if (*(HANDLE *)(param_1 + 0xabc) != (HANDLE)0x0) {
      ReleaseMutex(*(HANDLE *)(param_1 + 0xabc));
    }
  }
  ExceptionList = local_14;
  return;
}


