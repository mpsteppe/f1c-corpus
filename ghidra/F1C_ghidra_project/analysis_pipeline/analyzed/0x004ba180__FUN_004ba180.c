// Function: FUN_004ba180 @ 004ba180
// Size (bytes): 81


void __fastcall FUN_004ba180(int *param_1)

{
  char cVar1;
  int iVar2;
  
  if (*param_1 != 2) {
    return;
  }
  cVar1 = FUN_004b9a00();
  if (cVar1 == '\0') {
    iVar2 = FUN_004b8bd0();
    if (iVar2 != 2) {
      FUN_004b8c40(iVar2,1);
      FUN_004b9d20();
      return;
    }
    FUN_004c8dc0(0x3f800000);
    FUN_004b9e40();
  }
  FUN_004b9d20();
  return;
}


