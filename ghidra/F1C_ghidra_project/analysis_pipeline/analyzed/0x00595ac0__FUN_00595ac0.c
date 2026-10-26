// Function: FUN_00595ac0 @ 00595ac0
// Size (bytes): 34


void FUN_00595ac0(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_008d4920)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x24));
  return;
}


