// Function: FUN_004485d0 @ 004485d0
// Size (bytes): 198


float * __thiscall FUN_004485d0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  void *pvVar3;
  float *pfVar4;
  int iVar5;
  
  do {
    while ((pfVar4 = param_1, *param_2 != *pfVar4 || (param_2[3] != pfVar4[3]))) {
      fVar1 = param_2[3];
      fVar2 = pfVar4[3];
      if (*param_2 < *pfVar4 == (*param_2 == *pfVar4)) {
        if (fVar1 < fVar2 == (fVar1 == fVar2)) {
          iVar5 = 0;
        }
        else {
          iVar5 = 2;
        }
      }
      else if (fVar1 < fVar2 == (fVar1 == fVar2)) {
        iVar5 = 1;
      }
      else {
        iVar5 = 3;
      }
      param_1 = (float *)pfVar4[iVar5 + 0x13];
      if ((float *)pfVar4[iVar5 + 0x13] == (float *)0x0) {
        pvVar3 = operator_new(0x60);
        pfVar4[iVar5 + 0x13] = (float)pvVar3;
        FUN_00448510(param_2);
        return (float *)pfVar4[iVar5 + 0x13];
      }
    }
    if (*(double *)(param_2 + 1) == *(double *)(pfVar4 + 1)) {
      return pfVar4;
    }
    param_1 = (float *)pfVar4[0x17];
  } while ((float *)pfVar4[0x17] != (float *)0x0);
  pvVar3 = operator_new(0x60);
  pfVar4[0x17] = (float)pvVar3;
  FUN_00448510(param_2);
  return (float *)pfVar4[0x17];
}


