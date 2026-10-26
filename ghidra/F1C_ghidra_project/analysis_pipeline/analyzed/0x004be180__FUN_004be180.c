// Function: FUN_004be180 @ 004be180
// Size (bytes): 73


void FUN_004be180(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 8;
  do {
    iVar2 = 8;
    do {
      FUN_004bd970(param_1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004bd970(param_1);
  return;
}


