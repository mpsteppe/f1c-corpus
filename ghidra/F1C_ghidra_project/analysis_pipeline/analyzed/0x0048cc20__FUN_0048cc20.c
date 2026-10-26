// Function: FUN_0048cc20 @ 0048cc20
// Size (bytes): 136


void __fastcall FUN_0048cc20(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x32c) = 5;
  *(undefined4 *)(param_1 + 0x330) = 5;
  piVar1 = *(int **)(param_1 + 0x31c);
  *(int **)(param_1 + 0x324) = piVar1;
  if ((piVar1 != (int *)0x0) && (iVar2 = *piVar1, iVar2 != 0)) {
    while( true ) {
      if ((*(int *)(iVar2 + 4) != 0) && (iVar3 = *(int *)(*(int *)(iVar2 + 4) + 0xc), iVar3 != 0)) {
        iVar3 = *(int *)(iVar3 + 0x1c) + 2;
        if (iVar3 <= *(int *)(param_1 + 0x32c)) {
          iVar3 = *(int *)(param_1 + 0x32c);
        }
        *(int *)(param_1 + 0x32c) = iVar3;
        iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 4) + 0xc) + 0x20);
        if (iVar2 <= *(int *)(param_1 + 0x330)) {
          iVar2 = *(int *)(param_1 + 0x330);
        }
        *(int *)(param_1 + 0x330) = iVar2;
      }
      if (*(int *)(param_1 + 0x324) == 0) break;
      piVar1 = *(int **)(*(int *)(param_1 + 0x324) + 4);
      *(int **)(param_1 + 0x324) = piVar1;
      if (piVar1 == (int *)0x0) {
        return;
      }
      iVar2 = *piVar1;
      if (iVar2 == 0) {
        return;
      }
    }
  }
  return;
}


