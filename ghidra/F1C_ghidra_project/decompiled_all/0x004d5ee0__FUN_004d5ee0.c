// Function: FUN_004d5ee0 @ 004d5ee0
// Strings:  [Tire load factor should be positive, D:\dev\F1_1999_2002\Source\tire_manager.cpp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_004d5ee0(double *param_1,double param_2,double param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  
  if (((double)CONCAT44(param_5,param_4) < _DAT_0059e430 !=
       ((double)CONCAT44(param_5,param_4) == _DAT_0059e430)) && (DAT_007c569c != 5)) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0xc5);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Tire_load_factor_should_be_posit_005d45c0);
    }
  }
  *(undefined4 *)(param_1 + 2) = param_4;
  *(undefined4 *)((int)param_1 + 0x14) = param_5;
  *param_1 = (param_2 + param_3) * _DAT_0059e880;
  param_1[1] = (param_2 - param_3) * _DAT_0059e880;
  param_1[3] = _DAT_0059e420 / (double)CONCAT44(param_5,param_4);
  return;
}


