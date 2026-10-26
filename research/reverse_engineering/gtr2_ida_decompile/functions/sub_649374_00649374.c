int __stdcall sub_649374(char *Buffer, int a2, char *Format, va_list ArgList)
{
  int v4; // ebx
  unsigned int v5; // esi
  int v6; // eax

  v4 = 0;
  if ( a2 )
  {
    v5 = a2 - 1;
    v6 = _vsnprintf(Buffer, a2 - 1, Format, ArgList);
    if ( v6 < 0 || v6 > v5 )
    {
      v4 = -2147024774;
    }
    else if ( v6 != v5 )
    {
      return v4;
    }
    Buffer[v5] = 0;
    return v4;
  }
  return -2147024809;
}
