// Function: FUN_0048b950 @ 0048b950
// Size (bytes): 100


void __thiscall FUN_0048b950(int *param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  if (param_2 == '\0') {
    pcVar3 = (char *)param_1[0xbc];
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    param_1[0xbd] = (int)((char *)param_1[0xbc] + (~uVar2 - 1));
                    /* WARNING: Could not recover jumptable at 0x0048b9b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x2c))();
    return;
  }
  param_1[0xbd] = param_1[0xbc];
  *(undefined1 *)param_1[0xbc] = 0;
  pcVar3 = (char *)((int)param_1 + 0x1e7);
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (uVar2 != 0xfffffffe) {
    FUN_0048b810((char *)((int)param_1 + 0x1e7));
  }
  return;
}


