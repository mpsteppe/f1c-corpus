// Function: FUN_004988d0 @ 004988d0
// Size (bytes): 100


void __thiscall FUN_004988d0(int param_1,char *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_2 != (char *)0x0) {
    iVar3 = -1;
    pcVar4 = param_2;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((iVar3 != -2) && (*(int *)(*(int *)(param_1 + 0x18) + 0x50) != 0)) {
      piVar2 = (int *)FUN_00497750(param_2);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x8c))();
        FUN_004979c0(piVar2);
        FUN_00553050(piVar2[3],piVar2[1]);
        (**(code **)(*piVar2 + 0x90))();
      }
    }
  }
  return;
}


