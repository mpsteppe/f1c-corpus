// Function: FUN_0042ec00 @ 0042ec00
// Size (bytes): 96


void __thiscall FUN_0042ec00(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = &DAT_005c3738;
  if (*(int *)(param_1 + 4) != 1) {
    pcVar3 = &DAT_005c3734;
  }
  iVar2 = FUN_00423a00(pcVar3,&DAT_005ec4cc);
  if (iVar2 != 0) {
    if (pcVar3 == (char *)0x0) {
      DAT_005ec4cc = 0;
    }
    else {
      iVar2 = (int)&DAT_005ec4cc - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
    }
  }
  FUN_0058815f(param_2,&PTR_DAT_005c3730,&DAT_005ec4cc);
  return;
}


