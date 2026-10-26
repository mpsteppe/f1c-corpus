// Function: FUN_0047fb10 @ 0047fb10
// Size (bytes): 140


undefined4 * __thiscall FUN_0047fb10(undefined4 *param_1,byte param_2)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_005a7168;
  FUN_004c5de0();
  *param_1 = &PTR_LAB_005a4550;
  piVar2 = (int *)param_1[0x3c];
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[3] != '\0') && ((undefined4 *)*piVar2 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  FUN_00485eb0();
  if ((param_2 & 1) != 0) {
    FUN_00587bcf(param_1);
  }
  return param_1;
}


