// Function: FUN_004cc700 @ 004cc700
// Size (bytes): 305


void FUN_004cc700(undefined4 *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = *param_3;
  fVar2 = (float)param_1[0xb];
  fVar3 = (float)param_1[0xc];
  fVar4 = param_3[1];
  fVar5 = (float)param_1[0xd];
  fVar6 = param_3[2];
  FUN_00558e10(*param_1,1,fVar1 + fVar2,fVar3 + fVar4,fVar5 + fVar6,param_1[0x18]);
  FUN_00558e10(*param_1,2,(fVar1 + fVar2) - *param_2,(fVar3 + fVar4) - param_2[1],
               (fVar5 + fVar6) - param_2[2],param_1[0x18]);
  fVar1 = (float)param_1[0xb];
  fVar2 = *param_3;
  fVar3 = (float)param_1[0xc];
  fVar4 = param_3[1];
  fVar5 = (float)param_1[0xd];
  fVar6 = param_3[2];
  FUN_00558e10(*param_1,0,fVar1 - fVar2,fVar3 - fVar4,fVar5 - fVar6,param_1[0x18]);
  FUN_00558e10(*param_1,3,(fVar1 - fVar2) - *param_2,(fVar3 - fVar4) - param_2[1],
               (fVar5 - fVar6) - param_2[2],param_1[0x18]);
  return;
}


