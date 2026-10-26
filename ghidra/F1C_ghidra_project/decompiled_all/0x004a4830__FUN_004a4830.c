// Function: FUN_004a4830 @ 004a4830
// Strings:  [Wet Compound, Monsoon Compound, Intermediate Compound, Soft Compound, Hard Compound]


int __fastcall FUN_004a4830(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00588410(param_1,s_Hard_Compound_005cd534);
  if (iVar1 == 0) {
    return 2;
  }
  iVar1 = FUN_00588410(param_1,s_Soft_Compound_005cd524);
  if (iVar1 == 0) {
    return 3;
  }
  iVar1 = FUN_00588410(param_1,s_Intermediate_Compound_005cd50c);
  if (iVar1 == 0) {
    return 4;
  }
  iVar1 = FUN_00588410(param_1,s_Wet_Compound_005c7224);
  if (iVar1 == 0) {
    return 5;
  }
  iVar1 = FUN_00588410(param_1,s_Monsoon_Compound_005cd4f8);
  return (-(uint)(iVar1 != 0) & 0xfffffffb) + 6;
}


