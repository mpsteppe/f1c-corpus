int __cdecl sub_5984AA(PCNZCH lpString1, int cchCount1)
{
  char *v2; // esi
  const CHAR *v3; // eax
  char v4; // al

  v2 = (char *)dword_8D3E90;
  v3 = *(const CHAR **)dword_8D3E90;
  if ( !*(_DWORD *)dword_8D3E90 )
    return -((v2 - (_BYTE *)dword_8D3E90) >> 2);
  while ( 1 )
  {
    if ( !sub_597F6D(lpString1, v3, cchCount1) )
    {
      v4 = *(_BYTE *)(*(_DWORD *)v2 + cchCount1);
      if ( v4 == 61 || !v4 )
        break;
    }
    v3 = (const CHAR *)*((_DWORD *)v2 + 1);
    v2 += 4;
    if ( !v3 )
      return -((v2 - (_BYTE *)dword_8D3E90) >> 2);
  }
  return (v2 - (_BYTE *)dword_8D3E90) >> 2;
}
