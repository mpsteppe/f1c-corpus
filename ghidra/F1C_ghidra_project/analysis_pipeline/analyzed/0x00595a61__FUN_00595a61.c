// Function: FUN_00595a61 @ 00595a61
// Size (bytes): 95


void FUN_00595a61(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_008d4920)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_0058dfea(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_0058e04b(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_008d4920)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}


