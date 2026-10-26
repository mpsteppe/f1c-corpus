// Function: FUN_004ef6c0 @ 004ef6c0
// Size (bytes): 242


void __thiscall FUN_004ef6c0(int param_1,float *param_2,undefined4 param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_3c;
  float local_38;
  float local_34;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_00566e40();
  FUN_004ef680(&local_3c);
  fVar1 = *(float *)(param_1 + 0x34d8);
  fVar2 = *(float *)(param_1 + 0x34dc);
  fVar3 = *(float *)(param_1 + 0x34d8);
  fVar4 = param_2[1];
  fVar5 = *(float *)(param_1 + 0x34dc);
  fVar6 = param_2[2];
  *param_4 = (*(float *)(param_1 + 0x34d4) + *param_2) -
             (local_24 * local_3c + local_20 * local_38 + local_1c * local_34 +
             *(float *)(param_1 + 0x34d4));
  param_4[1] = (fVar3 + fVar4) -
               (local_18 * local_3c + local_14 * local_38 + local_10 * local_34 + fVar1);
  param_4[2] = (fVar5 + fVar6) -
               (local_c * local_3c + local_8 * local_38 + local_4 * local_34 + fVar2);
  return;
}


