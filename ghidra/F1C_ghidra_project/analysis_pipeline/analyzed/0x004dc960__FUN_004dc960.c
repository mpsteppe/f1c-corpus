// Function: FUN_004dc960 @ 004dc960
// Size (bytes): 284


undefined2 __fastcall
FUN_004dc960(undefined4 param_1,float *param_2,float *param_3,float *param_4,float param_5)

{
  undefined1 auStack_6c [4];
  int iStack_68;
  float local_64;
  int iStack_60;
  int iStack_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined1 local_4c [8];
  float fStack_44;
  undefined1 local_40 [64];
  
  FUN_00542460(&local_58,&local_54,&local_50);
  local_64 = (-local_58 - *param_2) * (-local_58 - *param_2) +
             (-local_54 - param_2[1]) * (-local_54 - param_2[1]) +
             (-local_50 - param_2[2]) * (-local_50 - param_2[2]);
  if (param_5 * param_5 < local_64) {
    return 0;
  }
  FUN_00542400(local_40);
  (**(code **)(*DAT_008b8f24 + 4))(DAT_008b8f24,param_2,local_4c,local_40);
  if (fStack_44 < DAT_0059e440 != (fStack_44 == DAT_0059e440)) {
    return 0;
  }
  FUN_005425a0(param_2,&iStack_60);
  iStack_68 = 0;
  FUN_005424e0(auStack_6c,auStack_6c,auStack_6c,&iStack_68);
  *param_4 = SQRT(local_64);
  *param_3 = (float)iStack_60;
  param_3[1] = (float)(iStack_68 - iStack_5c);
  param_3[2] = 0.0;
  return 1;
}


