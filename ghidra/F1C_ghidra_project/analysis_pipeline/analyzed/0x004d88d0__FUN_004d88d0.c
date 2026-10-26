// Function: FUN_004d88d0 @ 004d88d0
// Size (bytes): 128


undefined4 __fastcall FUN_004d88d0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar3 = DAT_007d0410;
  iVar4 = 0;
  puVar5 = (undefined4 *)(param_1 + 0x10);
  do {
    cVar1 = FUN_004d9290(iVar4,uVar3);
    if (cVar1 != '\0') {
      uVar2 = FUN_004daea0();
      *puVar5 = uVar2;
    }
    iVar4 = iVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar4 < 0x19);
  iVar4 = 0;
  puVar5 = (undefined4 *)(param_1 + 0x74);
  do {
    uVar2 = FUN_004db420();
    *puVar5 = uVar2;
    iVar4 = iVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar4 < 3);
  cVar1 = FUN_004d93e0(0,uVar3);
  if (cVar1 != '\0') {
    uVar3 = FUN_004dc220();
    *(undefined4 *)(param_1 + 0xc) = uVar3;
  }
  uVar3 = FUN_004dc290();
  *(undefined4 *)(param_1 + 0xd8) = uVar3;
  return 0;
}


