// Function: FUN_0045cd70 @ 0045cd70
// Strings:  [f1comp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char __fastcall FUN_0045cd70(char *param_1)

{
  char cVar1;
  int iVar2;
  
  if (*param_1 != '\0') {
    return '\x01';
  }
  iVar2 = 0;
  _DAT_008d4680 = 0;
  _DAT_008d4684 = 0;
  _DAT_008d4688 = 0;
  _DAT_008d468c = 0;
  do {
    (&DAT_008d4680)[iVar2] = (&DAT_0059f0c4)[iVar2] ^ 0x3e;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  iVar2 = FUN_00561bf0(*(undefined4 *)(param_1 + 4),PTR_s_f1comp_005c5b68,&DAT_008d4680,
                       &LAB_0045cde0,&LAB_0045cf50,&LAB_0045d0d0,&LAB_0045d130,0);
  cVar1 = '\x01' - (iVar2 != 0);
  *param_1 = cVar1;
  return cVar1;
}


