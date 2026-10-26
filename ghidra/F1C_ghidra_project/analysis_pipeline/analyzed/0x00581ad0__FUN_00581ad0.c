// Function: FUN_00581ad0 @ 00581ad0
// Size (bytes): 88


void __fastcall FUN_00581ad0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  BOOL BVar3;
  
  if ((*(char *)(param_1 + 6) != '\0') && (BVar3 = CloseHandle((HANDLE)param_1[4]), BVar3 != 0)) {
    param_1[4] = 0;
  }
  puVar2 = (undefined4 *)*param_1;
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar2[1];
    if (*(char *)(puVar2 + 2) != '\0') {
      FUN_00587bcf(*puVar2);
    }
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


