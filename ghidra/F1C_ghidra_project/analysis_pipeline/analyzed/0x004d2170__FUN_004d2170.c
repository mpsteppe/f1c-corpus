// Function: FUN_004d2170 @ 004d2170
// Size (bytes): 83


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004d2170(int param_1)

{
  double dVar1;
  char cVar2;
  int iVar3;
  
  dVar1 = (double)*(float *)(param_1 + 0xb4) + (double)_DAT_0059e468;
  if (dVar1 < _DAT_008afea0 == (dVar1 == _DAT_008afea0)) {
    return 0;
  }
  iVar3 = 0;
  if (0 < DAT_005c329c) {
    do {
      cVar2 = FUN_004bc9b0(0,0);
      if (cVar2 == '\0') {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_005c329c);
  }
  return 1;
}


