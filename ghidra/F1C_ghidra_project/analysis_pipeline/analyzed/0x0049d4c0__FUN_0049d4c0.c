// Function: FUN_0049d4c0 @ 0049d4c0
// Size (bytes): 261


void __fastcall FUN_0049d4c0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = FUN_0049b9a0();
  if (cVar1 == '\0') {
    FUN_0049e4e0(0,*(undefined4 *)(param_1 + 0x30));
  }
  else {
    FUN_0049e520(*(undefined4 *)(param_1 + 0x30));
  }
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  iVar2 = FUN_0049ba30(uVar3);
  FUN_0049e4e0(iVar2 == 1,uVar3);
  uVar3 = *(undefined4 *)(param_1 + 0x38);
  iVar2 = FUN_0049ba30(uVar3);
  FUN_0049e4e0(iVar2 == 2,uVar3);
  cVar1 = FUN_0049ba50();
  if (cVar1 == '\0') {
    FUN_0049e4e0(0,*(undefined4 *)(param_1 + 0x3c));
  }
  else {
    FUN_0049e520(*(undefined4 *)(param_1 + 0x3c));
  }
  cVar1 = FUN_0049bab0();
  if (cVar1 == '\0') {
    cVar1 = FUN_0049ba90();
    if (cVar1 == '\0') {
      uVar3 = *(undefined4 *)(param_1 + 0x40);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x40);
    }
    FUN_0049e4e0(cVar1 != '\0',uVar3);
  }
  else {
    FUN_0049e520(*(undefined4 *)(param_1 + 0x40));
  }
  cVar1 = FUN_0049bad0();
  FUN_0049e4e0(cVar1 != '\0',*(undefined4 *)(param_1 + 0x44));
  uVar3 = *(undefined4 *)(param_1 + 0x48);
  cVar1 = FUN_0049bb20(uVar3);
  FUN_0049e4e0(cVar1 != '\0',uVar3);
  return;
}


