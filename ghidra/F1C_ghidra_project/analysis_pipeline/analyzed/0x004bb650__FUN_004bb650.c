// Function: FUN_004bb650 @ 004bb650
// Size (bytes): 83


void __fastcall FUN_004bb650(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (puVar2 = (undefined4 *)*piVar3, puVar2 != (undefined4 *)0x0))
    {
      FUN_00587bcf(*puVar2);
      FUN_00587bcf(puVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


