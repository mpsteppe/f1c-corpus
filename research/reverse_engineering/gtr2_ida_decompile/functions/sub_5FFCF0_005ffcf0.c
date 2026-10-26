int __thiscall sub_5FFCF0(int this, int a2, int a3, int a4, char a5)
{
  int v7; // eax
  bool v8; // zf
  int i; // ecx
  _DWORD *v10; // eax
  int v11; // edx
  int j; // ecx
  _DWORD *v13; // eax
  int v14; // ecx
  _DWORD **v15; // eax
  _DWORD *k; // eax
  int v17; // eax
  _DWORD **v18; // eax
  _DWORD **v19; // eax
  _DWORD *m; // eax
  int v21; // eax
  _DWORD **v22; // eax
  _DWORD **v23; // eax
  _DWORD *n; // eax
  int v25; // eax
  _DWORD **v26; // eax
  int v27; // eax
  int ii; // ecx
  _DWORD *v29; // eax
  unsigned int v30; // eax
  size_t v31; // [esp-10h] [ebp-14h]
  size_t v32; // [esp-Ch] [ebp-10h]

  if ( (*(_BYTE *)this & 2) == 0 )
    return 16;
  v7 = *(_DWORD *)(this + 180);
  if ( v7 > 0 )
  {
    v8 = *(_DWORD *)(this + 184) == 0;
    *(_DWORD *)(this + 176) += v7;
    *(_DWORD *)(this + 180) = 0;
    if ( !v8 )
    {
      for ( i = 0; i < *(_DWORD *)(this + 172); ++i )
      {
        v10 = *(_DWORD **)(*(_DWORD *)(this + 184) + 4 * i);
        if ( v10 )
          *v10 &= ~0x40000000u;
      }
      j__free(*(void **)(this + 184));
    }
    v32 = 4 * *(_DWORD *)(this + 176);
    *(_DWORD *)(this + 172) = 0;
    *(_DWORD *)(this + 184) = operator new(v32);
    *(_DWORD *)this |= 4u;
  }
  if ( *(float *)(this + 292) <= sub_5F5900(*(_DWORD *)(this + 296)) )
  {
    for ( j = 0; j < *(_DWORD *)(this + 172); ++j )
    {
      v13 = *(_DWORD **)(*(_DWORD *)(this + 184) + 4 * j);
      if ( v13 )
        *v13 &= ~0x40000000u;
    }
    v8 = (*(_BYTE *)this & 4) == 0;
    *(_DWORD *)(this + 172) = 0;
    if ( !v8 )
    {
      do
      {
        v14 = a2;
        if ( a2 )
        {
          v15 = *(_DWORD ***)a2;
          v8 = *(_DWORD *)a2 == 0;
          *(_DWORD *)(a2 + 8) = *(_DWORD *)a2;
          if ( !v8 )
          {
            for ( k = *v15; k; k = *v18 )
            {
              if ( k != *(_DWORD **)(this + 276) )
              {
                sub_5FF6F0(this, v11, k);
                v14 = a2;
              }
              v17 = *(_DWORD *)(v14 + 8);
              if ( !v17 )
                break;
              v18 = *(_DWORD ***)(v17 + 4);
              *(_DWORD *)(v14 + 8) = v18;
              if ( !v18 )
                break;
            }
          }
        }
        if ( a3 )
        {
          v19 = *(_DWORD ***)a3;
          v8 = *(_DWORD *)a3 == 0;
          *(_DWORD *)(a3 + 8) = *(_DWORD *)a3;
          if ( !v8 )
          {
            for ( m = *v19; m; m = *v22 )
            {
              if ( m != *(_DWORD **)(this + 276) )
                sub_5FF6F0(this, v11, m);
              v21 = *(_DWORD *)(a3 + 8);
              if ( !v21 )
                break;
              v22 = *(_DWORD ***)(v21 + 4);
              *(_DWORD *)(a3 + 8) = v22;
              if ( !v22 )
                break;
            }
          }
        }
        if ( a4 )
        {
          v23 = *(_DWORD ***)a4;
          v8 = *(_DWORD *)a4 == 0;
          *(_DWORD *)(a4 + 8) = *(_DWORD *)a4;
          if ( !v8 )
          {
            for ( n = *v23; n; n = *v26 )
            {
              if ( n != *(_DWORD **)(this + 276) )
                sub_5FF6F0(this, v11, n);
              v25 = *(_DWORD *)(a4 + 8);
              if ( !v25 )
                break;
              v26 = *(_DWORD ***)(v25 + 4);
              *(_DWORD *)(a4 + 8) = v26;
              if ( !v26 )
                break;
            }
          }
        }
        v27 = *(_DWORD *)(this + 180);
        if ( v27 <= 0 )
        {
          v30 = *(_DWORD *)this & 0xFFFFFFFB;
        }
        else
        {
          v8 = *(_DWORD *)(this + 184) == 0;
          *(_DWORD *)(this + 176) += v27;
          *(_DWORD *)(this + 180) = 0;
          if ( !v8 )
          {
            for ( ii = 0; ii < *(_DWORD *)(this + 172); ++ii )
            {
              v29 = *(_DWORD **)(*(_DWORD *)(this + 184) + 4 * ii);
              if ( v29 )
                *v29 &= ~0x40000000u;
            }
            j__free(*(void **)(this + 184));
          }
          v31 = 4 * *(_DWORD *)(this + 176);
          *(_DWORD *)(this + 172) = 0;
          *(_DWORD *)(this + 184) = operator new(v31);
          v30 = *(_DWORD *)this | 4;
        }
        *(_DWORD *)this = v30;
      }
      while ( (v30 & 4) != 0 );
    }
    if ( !a5 )
      sub_5F5A20(*(_DWORD *)(this + 296));
  }
  return *(_DWORD *)(this + 172) != 0 ? 0 : 0x10;
}
