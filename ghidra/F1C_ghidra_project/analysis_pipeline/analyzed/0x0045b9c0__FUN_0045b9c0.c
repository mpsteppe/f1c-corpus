// Function: FUN_0045b9c0 @ 0045b9c0
// Size (bytes): 160


undefined4 __thiscall
FUN_0045b9c0(int param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

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
      cVar1 = FUN_0045b480(param_2);
      if (cVar1 != '\0') {
        return 1;
      }
      iVar2 = FUN_0045b500(param_5);
      if (-1 < iVar2) {
        FUN_0045b430(iVar2);
        param_1 = iVar2 * 0x5c + param_1;
        _strncpy((char *)(param_1 + 0x3c),param_2,0x4f);
        *(undefined1 *)(param_1 + 0x8b) = 0;
        *(undefined4 *)(param_1 + 0x94) = param_5;
        *(undefined4 *)(param_1 + 0x8c) = param_3;
        *(undefined4 *)(param_1 + 0x90) = param_4;
        return 1;
      }
      return 0;
    }
  }
  return 0;
}


