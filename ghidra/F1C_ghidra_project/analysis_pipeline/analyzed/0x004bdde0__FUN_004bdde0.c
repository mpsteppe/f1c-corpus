// Function: FUN_004bdde0 @ 004bdde0
// Size (bytes): 52


void FUN_004bdde0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 8;
  do {
    iVar2 = 8;
    do {
      FUN_004bd800();
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004bd800();
  return;
}


