// Function: FUN_0055be20 @ 0055be20
// Size (bytes): 62


void __thiscall FUN_0055be20(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  char cVar1;
  char *pcVar2;
  
  if (param_2 != 0) {
    pcVar2 = (char *)(param_1 + 4);
    param_2 = param_2 - (int)pcVar2;
    do {
      cVar1 = *pcVar2;
      pcVar2[param_2] = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x110);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x114);
  }
  return;
}


