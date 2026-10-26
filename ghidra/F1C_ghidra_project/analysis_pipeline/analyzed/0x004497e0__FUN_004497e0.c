// Function: FUN_004497e0 @ 004497e0
// Size (bytes): 483


void __fastcall FUN_004497e0(int *param_1)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  bool bVar4;
  char cVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  int local_10;
  
  pvVar6 = operator_new(*param_1 * 0x14);
  iVar8 = 0;
  local_10 = 0;
  if (0 < *param_1) {
    pfVar10 = (float *)((int)pvVar6 + 8);
    do {
      puVar7 = (undefined4 *)(param_1[2] + iVar8);
      *(undefined1 *)(puVar7 + 6) = 0;
      pfVar9 = (float *)*puVar7;
      pfVar2 = (float *)puVar7[2];
      pfVar3 = (float *)puVar7[4];
      pfVar10[-2] = (float)puVar7;
      if (*pfVar9 <= *pfVar2) {
        if (*pfVar3 <= *pfVar9) {
          fVar1 = *pfVar3;
        }
        else {
          fVar1 = *pfVar9;
        }
        pfVar10[-1] = fVar1;
        if (*pfVar2 <= *pfVar3) goto LAB_0044987c;
        fVar1 = *pfVar2;
      }
      else {
        if (*pfVar3 <= *pfVar2) {
          fVar1 = *pfVar3;
        }
        else {
          fVar1 = *pfVar2;
        }
        pfVar10[-1] = fVar1;
        if (*pfVar9 <= *pfVar3) {
LAB_0044987c:
          fVar1 = *pfVar3;
        }
        else {
          fVar1 = *pfVar9;
        }
      }
      *pfVar10 = fVar1;
      if (pfVar9[3] <= pfVar2[3]) {
        if (pfVar3[3] <= pfVar9[3]) {
          fVar1 = pfVar3[3];
        }
        else {
          fVar1 = pfVar9[3];
        }
        pfVar10[1] = fVar1;
        if (pfVar2[3] <= pfVar3[3]) goto LAB_004498e9;
        fVar1 = pfVar2[3];
      }
      else {
        if (pfVar3[3] <= pfVar2[3]) {
          fVar1 = pfVar3[3];
        }
        else {
          fVar1 = pfVar2[3];
        }
        pfVar10[1] = fVar1;
        if (pfVar9[3] <= pfVar3[3]) {
LAB_004498e9:
          fVar1 = pfVar3[3];
        }
        else {
          fVar1 = pfVar9[3];
        }
      }
      pfVar10[2] = fVar1;
      local_10 = local_10 + 1;
      iVar8 = iVar8 + 0x20;
      pfVar10 = pfVar10 + 5;
    } while (local_10 < *param_1);
  }
  FUN_005890aa(pvVar6,*param_1,0x14,&LAB_00448440);
  iVar8 = *param_1;
  if (0 < iVar8) {
    local_10 = 1;
    pfVar10 = (float *)((int)pvVar6 + 8);
    do {
      fVar1 = *pfVar10;
      if (local_10 < iVar8) {
        pfVar9 = pfVar10 + 6;
        iVar8 = local_10;
        do {
          if (fVar1 < pfVar9[-2]) break;
          if (((*pfVar9 < pfVar10[2]) && (pfVar10[1] < pfVar9[1])) &&
             (cVar5 = FUN_004491c0(pfVar9[-3]), cVar5 != '\0')) {
            *(undefined1 *)((int)pfVar10[-2] + 0x18) = 1;
            *(undefined1 *)((int)pfVar9[-3] + 0x18) = 1;
          }
          iVar8 = iVar8 + 1;
          pfVar9 = pfVar9 + 5;
        } while (iVar8 < *param_1);
      }
      iVar8 = *param_1;
      pfVar10 = pfVar10 + 5;
      bVar4 = local_10 < iVar8;
      local_10 = local_10 + 1;
    } while (bVar4);
  }
  if (pvVar6 != (void *)0x0) {
    FUN_00587bcf(pvVar6);
  }
  return;
}


