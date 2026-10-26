// Function: FUN_004b8010 @ 004b8010
// Size (bytes): 128


bool FUN_004b8010(void)

{
  int iVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined1 *local_8;
  undefined4 local_4;
  
  cVar2 = '\0';
  local_8 = (undefined1 *)0x0;
  local_4 = 0xffffffff;
  FUN_004b9830(&local_8);
  puVar3 = local_8;
  if (local_8 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  iVar1 = FUN_00587db0(puVar3,&DAT_005be828);
  if (iVar1 != 0) {
    FUN_00587d02(iVar1);
    FUN_0058ba36(puVar3,0x180);
    iVar1 = FUN_0058986e(puVar3);
    cVar2 = '\x01' - (iVar1 != 0);
  }
  if (local_8 != (undefined1 *)0x0) {
    FUN_00587bcf(local_8);
  }
  return cVar2 == '\0';
}


