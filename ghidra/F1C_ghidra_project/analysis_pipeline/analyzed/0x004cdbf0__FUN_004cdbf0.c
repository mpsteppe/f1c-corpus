// Function: FUN_004cdbf0 @ 004cdbf0
// Size (bytes): 121


undefined4 __thiscall FUN_004cdbf0(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char local_100 [256];
  
  pcVar3 = (char *)*param_1;
  pcVar4 = local_100;
  if (pcVar3 == (char *)0x0) {
    pcVar3 = &DAT_005ea438;
    pcVar4 = local_100;
  }
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    *pcVar4 = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = FUN_005897ca(local_100,&DAT_005d251c);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = FUN_00587c20(param_2,iVar2);
    if (iVar2 == param_2) break;
    iVar2 = FUN_005897ca(0,&DAT_005d251c);
  }
  return 1;
}


