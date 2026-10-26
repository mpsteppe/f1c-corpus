// Function: FUN_0055be80 @ 0055be80
// Size (bytes): 232


void __thiscall FUN_0055be80(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  
  *param_1 = 0;
  param_1[1] = 0;
  FUN_0053d970(param_3);
  iVar7 = 0;
  iVar2 = FUN_0053d880();
  if (0 < iVar2) {
    piVar6 = param_1 + 2;
    while( true ) {
      pvVar3 = operator_new(0x124);
      if (pvVar3 == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_0055bb50(iVar7);
      }
      *piVar6 = iVar2;
      iVar2 = FUN_0055bb70();
      if (iVar2 != 0) break;
      iVar2 = FUN_0053d890(iVar7);
      pcVar4 = (char *)(iVar2 + 0x18);
      pcVar5 = (char *)(*piVar6 + 4);
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      *(int *)(*piVar6 + 0x104) = iVar7;
      *(undefined4 *)(*piVar6 + 0x108) = 0;
      *(undefined4 *)(*piVar6 + 0x10c) = 0;
      FUN_0055bbf0();
      param_1[1] = param_1[1] + 1;
      *param_1 = *param_1 + 1;
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 1;
      iVar2 = FUN_0053d880();
      if (iVar2 <= iVar7) {
        return;
      }
    }
    iVar2 = param_1[iVar7 + 2];
    if (iVar2 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar2);
    }
    param_1[iVar7 + 2] = 0;
  }
  return;
}


