// Function: FUN_004f1650 @ 004f1650
// Size (bytes): 334


void __thiscall
FUN_004f1650(int param_1,undefined4 *param_2,undefined4 *param_3,float *param_4,float *param_5,
            undefined4 *param_6,float *param_7,undefined4 param_8)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  
  *(undefined4 *)(param_1 + 0x34d4) = *param_2;
  *(undefined4 *)(param_1 + 0x34d8) = param_2[1];
  *(undefined4 *)(param_1 + 0x34dc) = param_2[2];
  *(undefined4 *)(param_1 + 0x34e0) = *param_3;
  *(undefined4 *)(param_1 + 0x34e4) = param_3[1];
  *(undefined4 *)(param_1 + 0x34e8) = param_3[2];
  pfVar1 = (float *)(param_1 + 0x34b0);
  pfVar3 = pfVar1;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = *param_4;
    param_4 = param_4 + 1;
    pfVar3 = pfVar3 + 1;
  }
  pfVar3 = (float *)(param_1 + 0x34ec);
  *pfVar3 = *param_5;
  *(float *)(param_1 + 0x34f0) = param_5[1];
  *(float *)(param_1 + 0x34f4) = param_5[2];
  *(float *)(param_1 + 0x34f8) =
       *pfVar3 * *pfVar1 +
       *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x34f4);
  *(float *)(param_1 + 0x34fc) =
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x34f4) +
       *(float *)(param_1 + 0x34b4) * *pfVar3;
  *(float *)(param_1 + 0x3500) =
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x34f4) +
       *(float *)(param_1 + 0x34b8) * *pfVar3;
  *(undefined4 *)(param_1 + 0x3504) = *param_6;
  *(undefined4 *)(param_1 + 0x3508) = param_6[1];
  *(undefined4 *)(param_1 + 0x350c) = param_6[2];
  pfVar3 = (float *)(param_1 + 0x3534);
  *pfVar3 = *param_7;
  *(float *)(param_1 + 0x3538) = param_7[1];
  *(float *)(param_1 + 0x353c) = param_7[2];
  *(float *)(param_1 + 0x3540) =
       *pfVar3 * *pfVar1 +
       *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x3538) +
       *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x353c);
  *(float *)(param_1 + 0x3544) =
       *(float *)(param_1 + 0x34b4) * *pfVar3 +
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3538) +
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x353c);
  *(float *)(param_1 + 0x3548) =
       *(float *)(param_1 + 0x34b8) * *pfVar3 +
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3538) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x353c);
  *(undefined4 *)(param_1 + 0x39f0) = param_8;
  return;
}


