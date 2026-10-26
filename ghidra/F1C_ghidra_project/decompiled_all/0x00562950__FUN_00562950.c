// Function: FUN_00562950 @ 00562950
// Strings:  [\echo\%s]


void FUN_00562950(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 local_578 [1400];
  
  uVar2 = 0xffffffff;
  pcVar3 = param_2;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (~uVar2 - 1 < 0x547) {
    FUN_0058815f(local_578,s__echo__s_005e4ea0,param_2);
    FUN_00562710(param_1,local_578);
  }
  return;
}


