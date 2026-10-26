// Function: FUN_00592bad @ 00592bad
// Size (bytes): 153


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00592bad(void)

{
  void *pvVar1;
  char *pcVar2;
  int local_c;
  int local_8;
  
  if (DAT_008d5a4c == 0) {
    FUN_00597218();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_008d40a4,0x104);
  _DAT_008d3ea0 = &DAT_008d40a4;
  pcVar2 = &DAT_008d40a4;
  if (*DAT_008d5a44 != '\0') {
    pcVar2 = DAT_008d5a44;
  }
  FUN_00592c46(pcVar2,0,0,&local_8,&local_c);
  pvVar1 = _malloc(local_c + local_8 * 4);
  if (pvVar1 == (void *)0x0) {
    __amsg_exit(8);
  }
  FUN_00592c46(pcVar2,pvVar1,(void *)((int)pvVar1 + local_8 * 4),&local_8,&local_c);
  _DAT_008d3e88 = pvVar1;
  _DAT_008d3e84 = local_8 + -1;
  return;
}


