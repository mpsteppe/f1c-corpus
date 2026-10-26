// Function: FUN_004dba00 @ 004dba00
// Size (bytes): 162


void FUN_004dba00(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_8 [8];
  
  cVar1 = FUN_0049b9a0();
  if (cVar1 != '\0') {
    local_8[0] = 0x82;
  }
  uVar3 = (uint)(cVar1 != '\0');
  cVar1 = FUN_0049ba50();
  if (cVar1 != '\0') {
    local_8[uVar3] = 0x44;
    uVar3 = uVar3 + 1;
  }
  iVar2 = FUN_0049ba30();
  if (iVar2 == 1) {
    local_8[uVar3] = 0x8c;
  }
  else {
    iVar2 = FUN_0049ba30();
    if (iVar2 != 2) goto LAB_004dba60;
    local_8[uVar3] = 0x8d;
  }
  uVar3 = uVar3 + 1;
LAB_004dba60:
  if (uVar3 != 0) {
    local_8[uVar3] = 0;
    FUN_004d7e40(local_8,param_1 + 0x113,param_2,0xffffff,1,3,DAT_005acf50,DAT_005acf54);
  }
  return;
}


