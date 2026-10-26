int __thiscall sub_554CC0(int *this, int a2)
{
  int result; // eax
  _DWORD *v3; // ebp
  int *i; // edi
  int v5; // ebx
  _DWORD *v6; // esi
  int v7; // edx
  int v8; // ecx
  void *v9; // edi

  result = a2;
  v3 = *(_DWORD **)(a2 + 36);
  for ( i = this; v3; v3 = (_DWORD *)v3[48] )
  {
    result = v3[42];
    v5 = 0;
    if ( (int)v3[41] > 0 )
    {
      v6 = (_DWORD *)(result + 140);
      do
      {
        if ( (*(_BYTE *)(v6 - 19) & 2) != 0 )
        {
          v7 = *(_DWORD *)(*v6 + 84);
          if ( *(_DWORD *)(v7 + 4) )
          {
            sub_53F6E0(i, *(_DWORD *)(v7 + 4));
            v8 = *(_DWORD *)(*v6 + 84);
            v9 = *(void **)(v8 + 4);
            if ( v9 )
            {
              EmptyStub_7470(*(_DWORD *)(v8 + 4));
              FreeWrapper_7bcf(v9);
            }
            i = this;
            *(_DWORD *)(*(_DWORD *)(*v6 + 84) + 4) = 0;
          }
          UICleanupIterator(*v6);
        }
        result = v3[41];
        v6 += 37;
        ++v5;
      }
      while ( v5 < result );
    }
  }
  return result;
}

