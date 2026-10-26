// Function: FUN_00487830 @ 00487830
// Size (bytes): 174


void FUN_00487830(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  
  uVar2 = FUN_00486720();
  switch(uVar2) {
  case 0:
    if (param_1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00487885. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 1:
    if (param_1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0048785b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 2:
    if (param_1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0048789a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 3:
    if (param_1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00487870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 4:
    cVar1 = FUN_00486710();
    if (cVar1 == '\0') {
      cVar1 = FUN_00487720();
      if (cVar1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x004878d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*extraout_ECX_00 + 0x40))();
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x004878c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX_00 + 0x40))();
      return;
    }
  }
  return;
}


