// Function: FUN_0040cce0 @ 0040cce0
// Strings:  [D:\dev\F1_1999_2002\Source\camera.cpp, Entered CamMan::Post()]


void __fastcall FUN_0040cce0(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_camer_005be958,0xec9);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_CamMan__Post___005be99c);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  FUN_004083e0();
  if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x18))(1);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x1c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x1c))(1);
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x20))(1);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  *(undefined1 *)(param_1 + 0x2e) = 0;
  return;
}


