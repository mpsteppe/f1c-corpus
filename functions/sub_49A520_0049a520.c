unsigned int __thiscall sub_49A520(_DWORD *this, LPCSTR lpSrcStr)
{
  unsigned int result; // eax
  int v4; // esi
  char *v5; // eax

  sub_589901(lpSrcStr);
  result = CharToIndexConversion(lpSrcStr);
  if ( result != -1 )
  {
    v4 = this[result];
    if ( v4 )
    {
      while ( 1 )
      {
        v5 = StringPointerDereference((char **)v4);
        if ( !sub_588410(lpSrcStr, v5) )
          break;
        v4 = *(_DWORD *)(v4 + 24);
        if ( !v4 )
          return 0;
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
