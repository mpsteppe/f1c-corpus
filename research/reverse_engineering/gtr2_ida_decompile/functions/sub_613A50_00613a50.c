int __thiscall sub_613A50(_DWORD *this, int a2, int a3)
{
  int v3; // esi
  int v4; // edi
  int v5; // edi
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v10; // ebx
  int i; // edi
  int v12; // esi

  v3 = this[6];
  v4 = v3 / 4096;
  if ( v3 / 4096 == (v3 + a3 - 1) / 4096 && v4 < this[4] && v3 + a3 - 1 <= this[5] )
  {
    v5 = *(_DWORD *)(this[3] + 4 * v4);
    v6 = v3 % 4096;
    v7 = 0;
    if ( a3 > 0 )
    {
      v8 = v5 + v6;
      do
      {
        *(_BYTE *)(v7 + a2) = *((_BYTE *)this + 24) ^ *(_BYTE *)(v8 + v7);
        ++v7;
        ++this[6];
      }
      while ( v7 < a3 );
    }
    return a3;
  }
  else
  {
    v10 = 0;
    for ( i = 0; i < a3; ++this[6] )
    {
      v12 = this[6];
      if ( v12 >= this[5] )
        break;
      *(_BYTE *)(i + a2) = *((_BYTE *)this + 24) ^ *(_BYTE *)(*(_DWORD *)(this[3] + 4 * (v12 / 4096)) + v12 % 4096);
      ++v10;
      ++i;
    }
    return v10;
  }
}
