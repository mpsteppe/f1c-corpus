int __thiscall sub_6C3B64(_DWORD *this, unsigned int a2, unsigned int a3)
{
  int v3; // edi
  unsigned int v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // eax

  v3 = *(_DWORD *)(this[6] + 4 * a3);
  v4 = a3;
  if ( a3 >= a2 )
  {
    if ( a3 > a2 )
    {
      do
      {
        v6 = (_DWORD *)(this[6] + 4 * v4--);
        *v6 = *(v6 - 1);
      }
      while ( v4 > a2 );
    }
  }
  else
  {
    do
    {
      v5 = (_DWORD *)(this[6] + 4 * v4++);
      *v5 = v5[1];
    }
    while ( v4 < a2 );
  }
  *(_DWORD *)(this[6] + 4 * a2) = v3;
  return 0;
}
