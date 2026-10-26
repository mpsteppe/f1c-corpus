_BYTE *__usercall shortsort@<eax>(
        _BYTE *result@<eax>,
        unsigned int a2,
        int a3,
        int (__cdecl *a4)(unsigned int, unsigned int))
{
  unsigned int v4; // ecx
  unsigned int i; // edi
  unsigned int v6; // esi
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  int v9; // esi
  char v10; // dl

  v4 = a2;
  for ( i = (unsigned int)result; i > v4; i -= a3 )
  {
    v6 = v4 + a3;
    v7 = v4;
    if ( v4 + a3 <= i )
    {
      do
      {
        if ( a4(v6, v7) > 0 )
          v7 = v6;
        v6 += a3;
      }
      while ( v6 <= i );
      v4 = a2;
    }
    result = (_BYTE *)i;
    if ( v7 != i && a3 )
    {
      v8 = v7 - i;
      v9 = a3;
      do
      {
        v10 = result[v8];
        result[v8] = *result;
        *result++ = v10;
        --v9;
      }
      while ( v9 );
      v4 = a2;
    }
  }
  return result;
}
