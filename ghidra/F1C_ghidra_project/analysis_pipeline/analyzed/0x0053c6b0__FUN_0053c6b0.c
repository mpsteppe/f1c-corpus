// Function: FUN_0053c6b0 @ 0053c6b0
// Size (bytes): 51


void __thiscall FUN_0053c6b0(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    pcVar3 = (char *)(param_2 + 1);
    iVar2 = 4 - (int)pcVar3;
    do {
      cVar1 = *pcVar3;
      pcVar3[(int)param_1 + iVar2] = cVar1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    *param_1 = *param_2;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = 0;
  return;
}


