// Function: FUN_004902c0 @ 004902c0
// Size (bytes): 102


void __fastcall FUN_004902c0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_005ac760;
  piVar2 = (int *)param_1[0x38];
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[3] != '\0') && ((undefined4 *)*piVar2 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  FUN_00485eb0();
  return;
}


