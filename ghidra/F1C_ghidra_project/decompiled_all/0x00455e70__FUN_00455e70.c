// Function: FUN_00455e70 @ 00455e70
// Strings:  [D:\dev\F1_1999_2002\Source\hwinput.cpp, Entered HWInput::Post()]


void __fastcall FUN_00455e70(int *param_1)

{
  int *piVar1;
  char cVar2;
  
  if (DAT_007c569c != 5) {
    cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_hwinp_005c56a4,0x14b3);
    if (cVar2 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Entered_HWInput__Post___005c571c);
    }
  }
  FUN_0044f070(1);
  if (param_1[0x665] != 0) {
    FUN_004526c0();
  }
  FUN_0044fbe0();
  FUN_0044fbe0();
  FUN_0044efe0();
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
  }
  return;
}


