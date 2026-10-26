// Function: FUN_00487400 @ 00487400
// Size (bytes): 96


void __thiscall FUN_00487400(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  
  cVar1 = FUN_00486710();
  if ((char)param_2 != cVar1) {
    (**(code **)(*param_1 + 0x2c))(1);
  }
  FUN_00486660(param_2);
  if ((char)param_2 == '\0') {
    uVar2 = FUN_00487740();
    FUN_00487330(uVar2);
  }
  else {
    (**(code **)(*param_1 + 0x40))(4);
  }
  piVar3 = (int *)param_1[0x24];
  while (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x38))(param_2);
    piVar3 = (int *)FUN_00486320();
  }
  return;
}


