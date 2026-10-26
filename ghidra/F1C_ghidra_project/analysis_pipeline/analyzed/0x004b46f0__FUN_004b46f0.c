// Function: FUN_004b46f0 @ 004b46f0
// Size (bytes): 111


void __fastcall FUN_004b46f0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_4;
  
  FUN_004b4e10();
  local_4 = 4;
  puVar3 = (undefined4 *)(param_1 + 0xb0);
  do {
    puVar2 = (undefined4 *)puVar3[-4];
    while (puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)puVar2[1];
      if (*(char *)(puVar2 + 2) != '\0') {
        FUN_00587bcf(*puVar2);
      }
      FUN_00587bcf(puVar2);
      puVar2 = puVar1;
    }
    local_4 = local_4 + -1;
    puVar3[-4] = 0;
    puVar3[-3] = 0;
    puVar3[-2] = 0;
    puVar3[-1] = 0;
    puVar3 = puVar3 + -4;
  } while (local_4 != 0);
  return;
}


