// Function: FUN_00566650 @ 00566650
// Size (bytes): 94


undefined4 __thiscall FUN_00566650(int *param_1,char *param_2)

{
  char cVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
  if (param_2 == (char *)0x0) {
    return 0xffffffff;
  }
  uVar3 = 0xffffffff;
  pcVar5 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  if (*param_1 != 0) {
    if (iVar4 <= param_1[1]) goto LAB_00566698;
    FUN_00587bcf(*param_1);
  }
  pvVar2 = operator_new(~uVar3);
  *param_1 = (int)pvVar2;
  param_1[1] = iVar4;
LAB_00566698:
  pcVar5 = (char *)*param_1;
  do {
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    *pcVar5 = cVar1;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  return 0;
}


