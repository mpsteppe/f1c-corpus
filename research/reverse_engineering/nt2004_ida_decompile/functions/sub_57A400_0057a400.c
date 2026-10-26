bool sub_57A400(int a1, char *Format, ...)
{
  unsigned int v3; // kr04_4
  char Buffer[2048]; // [esp+Ch] [ebp-800h] BYREF
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, Format);
  if ( !*(_DWORD *)(a1 + 16) )
  {
    vfprintf(*(FILE *const *)a1, Format, va);
    return 0;
  }
  vsprintf(Buffer, Format, va);
  v3 = strlen(Buffer) + 1;
  if ( (int)(v3 - 1) <= 0 )
    return 0;
  return sub_536830(*(_DWORD *)a1, (int)Buffer, v3 - 1) == v3 - 1;
}
