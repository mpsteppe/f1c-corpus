// Function: FUN_005853b0 @ 005853b0
// Size (bytes): 77


undefined4 __fastcall FUN_005853b0(int *param_1)

{
  int *piVar1;
  char cVar2;
  int *piStack_4;
  
  piStack_4 = param_1;
  (**(code **)(*param_1 + 0x3c))();
  FUN_00585de0(0);
  cVar2 = FUN_00584e30(&piStack_4);
  piVar1 = piStack_4;
  if (cVar2 != '\0') {
    FUN_00586e50(piStack_4);
    (**(code **)(*param_1 + 0x5c))(piVar1);
    return 1;
  }
  return 0;
}


