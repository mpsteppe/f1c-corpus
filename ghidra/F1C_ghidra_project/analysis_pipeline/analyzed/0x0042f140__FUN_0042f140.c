// Function: FUN_0042f140 @ 0042f140
// Size (bytes): 59


undefined1 * __thiscall FUN_0042f140(int param_1,char *param_2)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  
  puVar1 = (undefined1 *)(param_1 + 0xc);
  iVar3 = FUN_00423a00(param_2,puVar1);
  if (iVar3 != 0) {
    if (param_2 != (char *)0x0) {
      iVar3 = (int)puVar1 - (int)param_2;
      do {
        cVar2 = *param_2;
        param_2[iVar3] = cVar2;
        param_2 = param_2 + 1;
      } while (cVar2 != '\0');
      return puVar1;
    }
    *puVar1 = 0;
  }
  return puVar1;
}


