// Function: FUN_00495b60 @ 00495b60
// Size (bytes): 106


void __fastcall FUN_00495b60(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 + 0x15fc;
  iVar2 = 0;
  iVar4 = 0;
  do {
    FUN_00499a20(*(undefined4 *)(param_1 + 0xc0));
    cVar1 = FUN_00499a50();
    if (cVar1 != '\0') {
      if (iVar2 != iVar4) {
        FUN_00499a70(iVar3);
        FUN_00499a00();
      }
      iVar2 = iVar2 + 1;
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 0xc;
  } while (iVar4 < 4);
  return;
}


