// Function: FUN_0040eec0 @ 0040eec0
// Size (bytes): 146


void __thiscall FUN_0040eec0(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double local_20;
  double local_18;
  double local_10;
  
  local_20 = (double)param_2[1];
  local_18 = (double)param_2[2];
  local_10 = (double)param_2[3];
  fVar1 = param_2[4];
  fVar2 = param_2[5];
  fVar3 = param_2[6];
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    FUN_00459950((double)*param_2,&local_20);
    FUN_00459990((double)fVar1,(double)fVar2,(double)fVar3);
  }
  return;
}


