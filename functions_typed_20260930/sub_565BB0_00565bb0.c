bool __thiscall sub_565BB0(void *this, int a2)
{
  int v2; // kr00_4
  int v4; // kr04_4

  switch ( *(_DWORD *)(*(_DWORD *)this + 544) )
  {
    case 1:
      v4 = strcmp((const char *)this + 48, (const char *)(a2 + 48));
      return v4 && -(v4 < 0) - ((v4 < 0) - 1) > 0;
    case 2:
      return CompareFileTime((const FILETIME *)this + 3, (const FILETIME *)(a2 + 24)) > 0;
    case 3:
      return CompareFileTime((const FILETIME *)this + 3, (const FILETIME *)(a2 + 24)) < 0;
    default:
      v2 = strcmp((const char *)this + 48, (const char *)(a2 + 48));
      return v2 && -(v2 < 0) - ((v2 < 0) - 1) < 0;
  }
}

