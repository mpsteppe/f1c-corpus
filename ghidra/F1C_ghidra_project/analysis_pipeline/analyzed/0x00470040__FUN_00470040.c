// Function: FUN_00470040 @ 00470040
// Size (bytes): 109


void __fastcall FUN_00470040(int *param_1)

{
  undefined4 uVar1;
  
  if ((char *)param_1[0x3a] != (char *)0x0) {
    if ((DAT_007d0410 == 3) || (DAT_007d0410 == 5)) {
      if (*(char *)param_1[0x3a] == '\0') {
        param_1[0x38] = 1;
        uVar1 = 0;
      }
      else {
        param_1[0x38] = 0;
        uVar1 = 1;
      }
    }
    else {
      param_1[0x38] = 2;
      uVar1 = 2;
    }
    uVar1 = FUN_00487010(uVar1);
    FUN_00566650(uVar1);
    (**(code **)(*param_1 + 0x40))(param_1[0x38]);
  }
  return;
}


