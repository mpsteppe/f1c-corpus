// Function: FUN_00487760 @ 00487760
// Size (bytes): 173


void FUN_00487760(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int *extraout_ECX_00;
  
  uVar2 = FUN_00486720();
  switch(uVar2) {
  case 0:
    if (param_1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x004877b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 1:
    if (param_1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x0048778d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 2:
    if (param_1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x004877cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 3:
    if (param_1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x004877a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX + 0x40))();
      return;
    }
    break;
  case 4:
    cVar1 = FUN_00486710();
    if (cVar1 == '\0') {
      cVar1 = FUN_00487740();
      if (cVar1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00487806. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*extraout_ECX_00 + 0x40))();
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x004877f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*extraout_ECX_00 + 0x40))();
      return;
    }
  }
  return;
}


