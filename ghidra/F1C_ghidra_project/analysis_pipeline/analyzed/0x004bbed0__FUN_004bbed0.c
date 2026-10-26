// Function: FUN_004bbed0 @ 004bbed0
// Size (bytes): 69


void __thiscall FUN_004bbed0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  if (iVar2 < 4) {
    *(undefined4 *)(param_1 + 0x40 + iVar2 * 8) = 3;
    *(int *)(param_1 + 0x44 + *(int *)(param_1 + 0x3c) * 8) = (int)*(char *)(param_2 + 8);
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  }
  else {
    piVar1 = (int *)(param_1 + 0x3c + iVar2 * 8);
    *piVar1 = *piVar1 + (int)*(char *)(param_2 + 8);
  }
  FUN_004a5660();
  return;
}


