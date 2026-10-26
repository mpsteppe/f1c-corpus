// Function: FUN_00562ac0 @ 00562ac0
// Strings:  [\statechanged\%d, \heartbeat\%d\gamename\%s]


void __fastcall FUN_00562ac0(int param_1,int param_2)

{
  char cVar1;
  DWORD DVar2;
  uint uVar3;
  char *pcVar4;
  char local_100 [256];
  
  FUN_0058815f(local_100,s__heartbeat__d_gamename__s_005e4ed8,*(undefined4 *)(param_1 + 0xe4),
               param_1 + 8);
  if (param_2 != 0) {
    uVar3 = 0xffffffff;
    pcVar4 = local_100;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_0058815f(local_100 + (~uVar3 - 1),s__statechanged__d_005e4ec4,param_2);
  }
  uVar3 = 0xffffffff;
  pcVar4 = local_100;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  sendto(*(SOCKET *)(param_1 + 4),local_100,~uVar3 - 1,0,(sockaddr *)(param_1 + 0xec),0x10);
  DVar2 = GetTickCount();
  *(DWORD *)(param_1 + 0xd8) = DVar2;
  return;
}


