// Function: FUN_004d0e20 @ 004d0e20
// Strings:  [D:\dev\F1_1999_2002\Source\steward.cpp, D:\dev\F1_1999_2002\Source\steward.cpp, Could not find glow "%s", Could not find light "%s"]


void __thiscall FUN_004d0e20(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_005453a0(param_2,0);
  *(int *)(param_1 + 4) = iVar2;
  if (iVar2 == 0) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x282);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Could_not_find_light___s__005d3bb0,param_2);
    }
  }
  iVar2 = FUN_005453a0(param_3,0);
  *(int *)(param_1 + 8) = iVar2;
  if (iVar2 == 0) {
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_stewa_005d3b6c,0x285);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Could_not_find_glow___s__005d3b94,param_3);
    }
  }
  return;
}


