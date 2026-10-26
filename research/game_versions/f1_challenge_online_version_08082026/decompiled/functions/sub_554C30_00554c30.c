int __thiscall sub_554C30(void *this, int a2)
{
  int result; // eax
  _DWORD *i; // edi
  int v5; // ebx
  int v6; // esi
  int v7; // eax

  result = a2;
  for ( i = *(_DWORD **)(a2 + 36); i; i = (_DWORD *)i[48] )
  {
    result = i[42];
    v5 = 0;
    if ( (int)i[41] > 0 )
    {
      v6 = result + 140;
      do
      {
        if ( (*(_BYTE *)(v6 - 76) & 2) != 0 )
        {
          v7 = *(_DWORD *)(*(_DWORD *)v6 + 84);
          if ( !*(_DWORD *)(v7 + 20) )
          {
            *(_DWORD *)(v7 + 24) &= ~1u;
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v6 + 84) + 24) |= 8u;
            sub_53F720((int)this, *(_DWORD **)(*(_DWORD *)v6 + 84), 0);
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v6 + 84) + 24) |= 1u;
          }
        }
        result = i[41];
        v6 += 148;
        ++v5;
      }
      while ( v5 < result );
    }
  }
  return result;
}
