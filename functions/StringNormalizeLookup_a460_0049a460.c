char *__thiscall sub_49A460(_DWORD *this, LPCSTR lpSrcStr)
{
  _DWORD *v3; // eax

  sub_589901(lpSrcStr);
  v3 = (_DWORD *)HashTableSearch(this, lpSrcStr);
  if ( v3 )
    return StringPointerAccessor_a2d0(v3);
  else
    return 0;
}
