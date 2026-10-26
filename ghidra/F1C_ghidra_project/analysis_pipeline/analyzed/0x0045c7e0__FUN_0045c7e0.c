// Function: FUN_0045c7e0 @ 0045c7e0
// Size (bytes): 101


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045c7e0(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int iVar4;
  
  fVar1 = _DAT_0059e43c;
  fVar2 = param_2 + *param_1;
  *param_1 = fVar2;
  if (fVar1 < fVar2) {
    fVar2 = _DAT_0059e43c / fVar2;
    *param_1 = 0.0;
    fVar1 = param_1[1];
    param_1[1] = 0.0;
    param_1[3] = (float)(int)fVar1 * fVar2;
    fVar1 = param_1[2];
    param_1[2] = 0.0;
    param_1[4] = (float)(int)fVar1 * fVar2;
  }
  iVar4 = 0x68;
  pfVar3 = param_1 + 0x6d;
  do {
    iVar4 = iVar4 + -1;
    pfVar3[-0x68] = param_2 + pfVar3[-0x68];
    *pfVar3 = param_2 + *pfVar3;
    pfVar3 = pfVar3 + 1;
  } while (iVar4 != 0);
  return;
}


