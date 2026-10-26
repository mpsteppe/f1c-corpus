int __thiscall sub_546370(_DWORD *this)
{
  int v2; // ebp
  int v3; // ebx
  int v4; // ecx
  void *v5; // esi
  int v6; // ecx
  void *v7; // ebp
  int v8; // esi
  int v9; // ebx

  if ( this[42] )
  {
    v2 = 0;
    if ( (int)this[41] > 0 )
    {
      v3 = 0;
      do
      {
        if ( *(_DWORD *)(v3 + this[42] + 76) )
          FreeWrapper_7bcf(*(LPVOID *)(v3 + this[42] + 76));
        v4 = this[42];
        v5 = *(void **)(v3 + v4 + 144);
        if ( v5 )
        {
          EmptyStub_7470(*(_DWORD *)(v3 + v4 + 144));
          FreeWrapper_7bcf(v5);
        }
        ++v2;
        v3 += 148;
      }
      while ( v2 < this[41] );
    }
    v6 = this[42];
    if ( v6 )
    {
      v7 = (void *)(v6 - 4);
      v8 = v6 + 148 * *(_DWORD *)(v6 - 4);
      if ( *(_DWORD *)(v6 - 4) - 1 >= 0 )
      {
        v9 = *(_DWORD *)(v6 - 4);
        do
        {
          v8 -= 148;
          EmptyStub_7470(v8);
          --v9;
        }
        while ( v9 );
      }
      FreeWrapper_7bcf(v7);
    }
    this[42] = 0;
  }
  return 0;
}

