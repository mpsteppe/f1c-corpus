
void FUN_0050cbb6(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float afStack_44 [16];
  
  if ((param_1 == param_2) || (pfVar2 = param_1, param_1 == param_3)) {
    pfVar2 = afStack_44;
  }
  *pfVar2 = param_3[4] * param_2[1] +
            param_2[2] * param_3[8] + *param_2 * *param_3 + param_2[3] * param_3[0xc];
  pfVar2[1] = param_3[1] * *param_2 +
              param_2[2] * param_3[9] + param_2[3] * param_3[0xd] + param_2[1] * param_3[5];
  pfVar2[2] = param_3[6] * param_2[1] +
              param_2[2] * param_3[10] + param_3[2] * *param_2 + param_2[3] * param_3[0xe];
  pfVar2[3] = param_3[7] * param_2[1] +
              *param_2 * param_3[3] + param_3[0xb] * param_2[2] + param_2[3] * param_3[0xf];
  pfVar2[4] = param_2[6] * param_3[8] +
              param_3[4] * param_2[5] + param_2[4] * *param_3 + param_2[7] * param_3[0xc];
  pfVar2[5] = param_3[1] * param_2[4] +
              param_3[5] * param_2[5] + param_2[7] * param_3[0xd] + param_2[6] * param_3[9];
  pfVar2[6] = param_2[6] * param_3[10] +
              param_3[2] * param_2[4] + param_2[7] * param_3[0xe] + param_3[6] * param_2[5];
  pfVar2[7] = param_2[4] * param_3[3] +
              param_2[6] * param_3[0xb] + param_2[7] * param_3[0xf] + param_3[7] * param_2[5];
  pfVar2[8] = param_2[10] * param_3[8] +
              param_3[4] * param_2[9] + param_2[8] * *param_3 + param_2[0xb] * param_3[0xc];
  pfVar2[9] = param_3[1] * param_2[8] +
              param_3[5] * param_2[9] + param_2[10] * param_3[9] + param_2[0xb] * param_3[0xd];
  pfVar2[10] = param_2[10] * param_3[10] +
               param_2[0xb] * param_3[0xe] + param_3[2] * param_2[8] + param_3[6] * param_2[9];
  pfVar2[0xb] = param_2[8] * param_3[3] +
                param_3[7] * param_2[9] + param_2[10] * param_3[0xb] + param_2[0xb] * param_3[0xf];
  pfVar2[0xc] = param_2[0xe] * param_3[8] +
                param_3[4] * param_2[0xd] + param_2[0xc] * *param_3 + param_2[0xf] * param_3[0xc];
  pfVar2[0xd] = param_3[1] * param_2[0xc] +
                param_3[5] * param_2[0xd] + param_2[0xe] * param_3[9] + param_2[0xf] * param_3[0xd];
  pfVar2[0xe] = param_2[0xe] * param_3[10] +
                param_2[0xf] * param_3[0xe] + param_3[2] * param_2[0xc] + param_3[6] * param_2[0xd];
  pfVar2[0xf] = param_2[0xc] * param_3[3] +
                param_3[7] * param_2[0xd] +
                param_2[0xe] * param_3[0xb] + param_2[0xf] * param_3[0xf];
  if (pfVar2 != param_1) {
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}

