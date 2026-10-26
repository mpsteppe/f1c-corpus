// Function: FUN_0048ca50 @ 0048ca50
// Size (bytes): 167


/* WARNING: Removing unreachable block (ram,0x0048cab1) */
/* WARNING: Removing unreachable block (ram,0x0048cabb) */
/* WARNING: Removing unreachable block (ram,0x0048cac1) */
/* WARNING: Removing unreachable block (ram,0x0048cac7) */

void __fastcall FUN_0048ca50(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  
  *param_1 = &PTR_FUN_005ac048;
  piVar2 = (int *)param_1[199];
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[3] != '\0') && ((undefined4 *)*piVar2 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  param_1[199] = 0;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  param_1[199] = 0;
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0xca] = 0;
  FUN_0048c0d0();
  return;
}


