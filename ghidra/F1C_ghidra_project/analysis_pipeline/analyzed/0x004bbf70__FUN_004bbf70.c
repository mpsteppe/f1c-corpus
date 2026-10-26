// Function: FUN_004bbf70 @ 004bbf70
// Size (bytes): 75


void __fastcall FUN_004bbf70(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (0 < *(int *)(param_1 + 0x3c)) {
    iVar1 = *(int *)(param_1 + 0x3c) + -1;
    iVar3 = 0;
    *(int *)(param_1 + 0x3c) = iVar1;
    if (0 < iVar1) {
      puVar2 = (undefined4 *)(param_1 + 0x40);
      do {
        *puVar2 = puVar2[2];
        puVar2[1] = puVar2[3];
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 2;
      } while (iVar3 < *(int *)(param_1 + 0x3c));
    }
  }
  if (*(int *)(param_1 + 0x3c) < 1) {
    FUN_004a5660(0);
    return;
  }
  FUN_004a5660(1);
  return;
}


