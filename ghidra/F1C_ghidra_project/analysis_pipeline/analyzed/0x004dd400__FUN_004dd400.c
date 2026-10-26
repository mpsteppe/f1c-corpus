// Function: FUN_004dd400 @ 004dd400
// Size (bytes): 78


void FUN_004dd400(undefined4 param_1,undefined4 param_2,int param_3,float *param_4,float *param_5,
                 int param_6)

{
  FUN_004dd3a0(param_1,param_2,param_3,&param_6,&param_3,param_6);
  if (param_4 != (float *)0x0) {
    *param_4 = (float)param_6 / (float)DAT_005d6d60;
  }
  if (param_5 != (float *)0x0) {
    *param_5 = (float)param_3 / (float)DAT_005d6d64;
  }
  return;
}


