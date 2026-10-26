void __thiscall sub_4F9040(int this)
{
  int i; // edx
  int v3; // edx
  char v4; // bl
  int j; // edx
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  _DWORD *v9; // ecx
  double v10; // st7
  unsigned int *v11; // esi
  int v12; // eax
  int k; // ebx
  int v14; // ebp
  int v15; // [esp+0h] [ebp-18h]
  int v16; // [esp+4h] [ebp-14h]

  for ( i = 0; i < *(_DWORD *)(this + 264); i = v3 + 1 )
    sub_4F8D70((_DWORD *)(*(_DWORD *)(this + 268) + 8 * i), 0);
  if ( dword_75CBB0 == 7
    && dword_6310D8[6326 * *(unsigned __int8 *)(this + 304)] < *(_DWORD *)(this + 144)
    && dword_767310 == 2 )
  {
    sub_4F93E0(this);
  }
  v4 = 0;
  for ( j = 0; j < *(_DWORD *)(this + 264); ++j )
  {
    v6 = *(_DWORD *)(this + 272);
    v7 = *(_DWORD *)(*(_DWORD *)(this + 268) + 8 * j);
    v8 = *(_DWORD *)(v6 + 4 * j);
    v9 = (_DWORD *)(v6 + 4 * j);
    if ( v8 != v7 )
    {
      *v9 = v7;
      v4 = 1;
    }
  }
  v10 = dbl_7DA9C8 + *(float *)(this + 276);
  *(float *)(this + 276) = v10;
  if ( v4 || v10 > 5.0 )
  {
    *(_DWORD *)(this + 276) = 0;
    v11 = (unsigned int *)dword_7D3C44;
    if ( dword_79FC40 < 1023 )
    {
      ++dword_79FC40;
      dword_7D3C44 += 208;
    }
    *(float *)&v16 = dbl_7DA9D0;
    sub_4D0D00(v11, 4, 10, 0, 63, v16, 0);
    v12 = 0;
    for ( k = 0; k < *(_DWORD *)(this + 264); ++k )
    {
      v14 = *(_DWORD *)(*(_DWORD *)(this + 268) + 8 * k);
      if ( v14 )
      {
        if ( v12 >= 16 )
        {
          v11 = (unsigned int *)dword_7D3C44;
          if ( dword_79FC40 < 1023 )
          {
            ++dword_79FC40;
            dword_7D3C44 += 208;
          }
          *(float *)&v15 = dbl_7DA9D0;
          sub_4D0D00(v11, 4, 11, 0, 63, v15, 0);
          v12 = 0;
        }
        *((_WORD *)v11 + v12++ + 4) = v14 + ((_WORD)k << 6);
        *v11 = (v12 << 7) | *v11 & 0xFFFF003F;
      }
    }
  }
}
