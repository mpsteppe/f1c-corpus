// Function: FUN_0058b59f @ 0058b59f
// Size (bytes): 53


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058b59f(void)

{
  longlong lVar1;
  _FILETIME local_c;
  
  GetSystemTimeAsFileTime(&local_c);
  lVar1 = __allmul(local_c.dwHighDateTime,0,0,1);
  _DAT_008d3ec0 = lVar1 + (ulonglong)local_c.dwLowDateTime;
  return;
}


