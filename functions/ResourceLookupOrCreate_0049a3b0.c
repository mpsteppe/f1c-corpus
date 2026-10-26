unsigned int __thiscall sub_49A3B0(_DWORD *this, LPCSTR lpSrcStr, int a3)
{
  unsigned int result; // eax
  unsigned int v5; // ebp
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // edi
  int i; // eax

  sub_589901(lpSrcStr);
  if ( sub_49A520(lpSrcStr) )
    return -1;
  result = CharToIndexConversion(lpSrcStr);
  v5 = result;
  if ( result != -1 )
  {
    v6 = this[result];
    v7 = (_DWORD *)OperatorNewNhMallocWrapper(28);
    if ( v7 )
      v8 = PatternedFieldInit(v7);
    else
      v8 = 0;
    ThunkToFUN00566650((int)lpSrcStr);
    FunctionCallWrapper_a2e0(a3);
    if ( v6 )
    {
      for ( i = *(_DWORD *)(v6 + 24); i; i = *(_DWORD *)(i + 24) )
        v6 = i;
      *(_DWORD *)(v6 + 24) = v8;
      return v5;
    }
    else
    {
      this[v5] = v8;
      return v5;
    }
  }
  return result;
}
