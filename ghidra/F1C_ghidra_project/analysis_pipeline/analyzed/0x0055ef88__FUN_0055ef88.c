// Function: FUN_0055ef88 @ 0055ef88
// Size (bytes): 206


undefined8 __fastcall
FUN_0055ef88(undefined4 param_1,undefined4 param_2,float *param_3,float *param_4,float *param_5)

{
  int iVar1;
  bool bVar2;
  undefined4 in_EAX;
  int local_8;
  
  local_8 = 4;
  do {
    *param_5 = param_3[1] * param_4[4] + param_3[2] * param_4[8] + param_3[3] * param_4[0xc] +
               *param_3 * *param_4;
    param_5[1] = param_3[1] * param_4[5] + param_3[2] * param_4[9] + param_3[3] * param_4[0xd] +
                 *param_3 * param_4[1];
    param_5[2] = param_3[1] * param_4[6] + param_3[2] * param_4[10] + param_3[3] * param_4[0xe] +
                 *param_3 * param_4[2];
    param_5[3] = param_3[1] * param_4[7] + param_3[2] * param_4[0xb] + param_3[3] * param_4[0xf] +
                 *param_3 * param_4[3];
    param_3 = param_3 + 4;
    param_5 = param_5 + 4;
    iVar1 = local_8 + -1;
    bVar2 = 0 < local_8;
    local_8 = iVar1;
  } while (iVar1 != 0 && bVar2);
  return CONCAT44(param_2,in_EAX);
}


