// Function: FUN_00498950 @ 00498950
// Size (bytes): 129


void __thiscall FUN_00498950(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 != 0) {
    iVar4 = 0;
    do {
      cVar1 = FUN_00499a50();
      if (cVar1 == '\0') break;
      uVar2 = FUN_0049a2b0();
      iVar3 = FUN_00588410(param_2,uVar2);
      if (iVar3 == 0) {
        return;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    if (iVar4 == 3) {
      FUN_00499a30(&DAT_005ea438,0);
      FUN_00495b60();
    }
    FUN_00499a30(param_2,*(undefined4 *)(param_1 + 0xd8));
  }
  return;
}


