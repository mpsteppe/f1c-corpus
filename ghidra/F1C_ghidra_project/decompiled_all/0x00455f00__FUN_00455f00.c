// Function: FUN_00455f00 @ 00455f00
// Strings:  [SUVWj, D:\dev\F1_1999_2002\Source\hwinput.cpp, Entered HWInput::Exit()]


void __fastcall FUN_00455f00(int *param_1)

{
  int *piVar1;
  char cVar2;
  
  cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_hwinp_005c56a4,0x14c9);
  if (cVar2 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_HWInput__Exit___005c5734);
  }
  FUN_0044fbe0();
  FUN_0044fbe0();
  FUN_0044f5f0();
  FUN_0044efe0();
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
  }
  if (DAT_007d13a0 == '\x01') {
    FUN_004f8c90();
    param_1[0x6c4] = -1;
  }
  return;
}


