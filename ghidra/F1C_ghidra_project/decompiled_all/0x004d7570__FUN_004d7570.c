// Function: FUN_004d7570 @ 004d7570
// Strings:  [D:\dev\F1_1999_2002\Source\tire_manager.cpp, Tire brand doesn't have compound index %d]


int __thiscall FUN_004d7570(int param_1,int param_2)

{
  char cVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x10))) {
    return param_2 * 0x2a8 + *(int *)(param_1 + 0x14);
  }
  cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x3ba);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Tire_brand_doesn_t_have_compound_005d4950,param_2);
  }
  return 0;
}


