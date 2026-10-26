// Function: FUN_00562010 @ 00562010
// Strings:  [255.255.255.255, 255.255.255.255]


undefined4 __fastcall
FUN_00562010(char *param_1,u_short param_2,hostent *param_3,undefined4 *param_4)

{
  u_short uVar1;
  char **ppcVar2;
  hostent *phVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  *(undefined2 *)&param_3->h_name = 2;
  uVar1 = htons(param_2);
  *(u_short *)((int)&param_3->h_name + 2) = uVar1;
  if (param_1 == (char *)0x0) {
    param_3->h_aliases = (char **)0x0;
  }
  else {
    ppcVar2 = (char **)inet_addr(param_1);
    param_3->h_aliases = ppcVar2;
  }
  if (param_3->h_aliases == (char **)0xffffffff) {
    iVar4 = 0x10;
    bVar7 = true;
    pcVar5 = param_1;
    pcVar6 = &DAT_005e4e80;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar7 = *pcVar5 == *pcVar6;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar7);
    if (!bVar7) {
      phVar3 = gethostbyname(param_1);
      if (phVar3 == (hostent *)0x0) {
        return 0;
      }
      param_3->h_aliases = *(char ***)*phVar3->h_addr_list;
      param_3 = phVar3;
    }
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = param_3;
  }
  return 1;
}


