// Function: FUN_004b33b0 @ 004b33b0
// Size (bytes): 69


void __thiscall
FUN_004b33b0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  *param_1 = (((DAT_007c56a4 + (param_7 + param_2 * 4) * 8) * 0x40 + param_3) * 0x400 + param_4) *
             0x100 + param_5;
  param_1[1] = param_6;
  param_1[0x6b] = -1;
  return;
}


