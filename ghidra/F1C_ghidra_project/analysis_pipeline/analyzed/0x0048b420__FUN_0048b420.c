// Function: FUN_0048b420 @ 0048b420
// Size (bytes): 176


undefined4 * __thiscall
FUN_0048b420(undefined4 *param_1,int param_2,char *param_3,int param_4,undefined1 param_5,
            undefined4 param_6,undefined1 param_7)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  FUN_00485e30();
  *param_1 = &PTR_FUN_005abed0;
  if (param_2 == 0) {
    param_2 = (int)param_1 + 0xe6;
  }
  param_1[0xbc] = param_2;
  FUN_0048b4f0();
  if (0 < param_4) {
    FUN_0048b8f0(param_4);
  }
  param_1[0xbf] = 0;
  if (param_3 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar5 = param_3;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if ((int)(~uVar3 - 1) < param_4) {
      pcVar5 = (char *)param_1[0xbc];
      pcVar4 = param_3;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iVar2 = 0x1e7 - (int)param_3;
      do {
        cVar1 = *param_3;
        param_3[(int)param_1 + iVar2] = cVar1;
        param_3 = param_3 + 1;
      } while (cVar1 != '\0');
    }
  }
  *(undefined1 *)((int)param_1 + 0xe5) = param_7;
  *(undefined1 *)((int)param_1 + 0xe2) = param_5;
  param_1[0xba] = param_6;
  return param_1;
}


