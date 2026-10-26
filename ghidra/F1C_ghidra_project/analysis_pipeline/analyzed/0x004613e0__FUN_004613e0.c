// Function: FUN_004613e0 @ 004613e0
// Size (bytes): 88


void __fastcall FUN_004613e0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x3e14)) {
    puVar2 = (undefined4 *)(param_1 + 0x3c74);
    do {
      cVar1 = FUN_00461530(2);
      if (cVar1 == '\0') {
        FUN_00462940(*puVar2);
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x3e14));
  }
  return;
}


