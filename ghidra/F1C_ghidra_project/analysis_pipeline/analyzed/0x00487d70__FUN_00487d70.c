// Function: FUN_00487d70 @ 00487d70
// Size (bytes): 103


void __fastcall FUN_00487d70(int *param_1)

{
  char cVar1;
  int *piVar2;
  char extraout_DL;
  bool bVar3;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0xac))();
  if (piVar2 == (int *)0x0) {
    (**(code **)(*param_1 + 0x38))(1);
    return;
  }
  (**(code **)(*param_1 + 0x38))(0);
  if ((char)param_1[0x39] == '\0') {
    bVar3 = *piVar2 != 0;
  }
  else {
    bVar3 = *piVar2 == 0;
  }
  cVar1 = FUN_00487720();
  if (cVar1 != extraout_DL) {
    FUN_00487260(bVar3);
    (**(code **)(*param_1 + 0x2c))(1);
  }
  return;
}


