// Function: FUN_00498650 @ 00498650
// Size (bytes): 73


void __thiscall
FUN_00498650(int param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 != (char *)0x0) {
    iVar2 = -1;
    pcVar3 = param_2;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      FUN_00566650(param_2);
      *(undefined4 *)(param_1 + 0x1560) = param_3;
      *(undefined4 *)(param_1 + 0x1564) = param_4;
      *(undefined4 *)(param_1 + 0x1568) = param_5;
    }
  }
  return;
}


