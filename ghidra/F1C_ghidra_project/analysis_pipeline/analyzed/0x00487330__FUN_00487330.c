// Function: FUN_00487330 @ 00487330
// Size (bytes): 174


void FUN_00487330(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  
  uVar2 = FUN_00486720();
  switch(uVar2) {
  case 0:
    if (param_1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00487385. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 1:
    if (param_1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0048735b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 2:
    if (param_1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0048739a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 3:
    if (param_1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00487370. Too many branches */
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
                    /* WARNING: Could not recover jumptable at 0x004873d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*extraout_ECX_00 + 0x40))();
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x004873c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX_00 + 0x40))();
      return;
    }
  }
  return;
}


