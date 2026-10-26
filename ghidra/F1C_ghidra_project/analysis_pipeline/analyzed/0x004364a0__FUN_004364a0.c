// Function: FUN_004364a0 @ 004364a0
// Size (bytes): 363


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_004364a0(double *param_1,double param_2,double param_3,double param_4,double *param_5,
            double param_6,double param_7,double param_8,double param_9,double param_10,
            double param_11,double param_12,double param_13)

{
  double dVar1;
  
  *param_1 = param_3 * param_6;
  param_8 = param_4 * param_8;
  param_1[1] = param_8;
  param_9 = param_9 * param_4;
  param_1[2] = param_9;
  dVar1 = param_5[6];
  param_1[3] = param_2 * dVar1;
  param_1[4] = (param_9 - param_8) * param_2 * dVar1;
  param_10 = param_10 * param_4;
  param_1[5] = param_10;
  param_11 = param_4 * param_11;
  param_1[6] = param_11;
  dVar1 = param_5[7];
  param_1[7] = param_2 * dVar1;
  param_1[8] = (param_11 - param_10) * param_2 * dVar1;
  param_1[9] = param_3 * param_5[2];
  param_1[10] = param_3 * param_5[3];
  param_1[0xb] = param_4 * param_5[4];
  param_1[0xc] = param_4 * param_5[5];
  dVar1 = _DAT_0059e420 / SQRT(param_2);
  param_1[0xd] = ((param_12 + *param_5 + param_13) - param_7) * dVar1;
  param_1[0xe] = (param_12 + param_5[1] + param_13) * dVar1;
  if ((((((param_3 * param_6 == _DAT_0059e430) && (param_8 == _DAT_0059e430)) &&
        (param_9 == _DAT_0059e430)) && ((param_10 == _DAT_0059e430 && (param_11 == _DAT_0059e430))))
      && ((param_1[9] == _DAT_0059e430 &&
          ((param_1[10] == _DAT_0059e430 && (param_1[0xb] == _DAT_0059e430)))))) &&
     (param_1[0xc] == _DAT_0059e430)) {
    return 0;
  }
  return 1;
}


