// Function: FUN_004b1780 @ 004b1780
// Size (bytes): 45


int __fastcall FUN_004b1780(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(param_1 + 0x2988);
  cVar2 = FUN_00461dc0();
  if (cVar2 != '\0') {
    if (iVar1 < -1) {
      return -1;
    }
    if (1 < iVar1) {
      return 1;
    }
  }
  return iVar1;
}


