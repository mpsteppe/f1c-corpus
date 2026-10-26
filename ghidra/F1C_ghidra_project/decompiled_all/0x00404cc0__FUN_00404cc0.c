// Function: FUN_00404cc0 @ 00404cc0
// Strings:  [QuickRace]


int FUN_00404cc0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_00588410(param_1,(&PTR_PTR_005be6c4)[iVar2]);
    if (iVar1 == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return 0;
}


