bool sub_613D30(int a1, char *Format, ...)
{
  int v3; // kr00_4
  char Buffer[2048]; // [esp+8h] [ebp-800h] BYREF
  va_list va; // [esp+814h] [ebp+Ch] BYREF

  va_start(va, Format);
  if ( *(_DWORD *)(a1 + 20) )
  {
    vsprintf(Buffer, Format, va);
    v3 = strlen(Buffer);
    if ( v3 <= 0 )
    {
      return 0;
    }
    else if ( *(_DWORD *)(a1 + 20) == 5 )
    {
      sub_613900(*(_DWORD *)(a1 + 4), (int)Buffer, v3);
      return 1;
    }
    else
    {
      return sub_62A860(v3) == v3;
    }
  }
  else
  {
    vfprintf(*(FILE *const *)(a1 + 4), Format, va);
    return 0;
  }
}
