void __thiscall sub_54BDC0(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *i; // ebp
  int *v5; // esi
  int v6; // edi
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // eax
  int v11; // [esp+4h] [ebp-8h]

  for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)i[4] )
  {
    v5 = (int *)i[71];
    v11 = 0;
    if ( (int)i[70] > 0 )
    {
      v6 = a2 & 0x20;
      do
      {
        v7 = a2 | ~a3 & *v5;
        *v5 = v7;
        if ( v6 )
        {
          v8 = (((*(int *)(dword_8B8F28 + 432) >> 4) & 3)
              + ((((*(int *)(dword_8B8F28 + 432) >> 2) & 3) + ((*(_DWORD *)(dword_8B8F28 + 432) & 3) << 8)) << 8)) << 6;
          SingleCallWrapper_e0e0(v5, 6);
          v9 = 0;
          if ( v5[2] > 0 )
          {
            v10 = 0;
            do
            {
              *(_DWORD *)(v10 + v5[8] + 24) &= 0xFF000000;
              *(_DWORD *)(v10 + v5[8] + 24) |= v8;
              ++v9;
              v10 += 64;
            }
            while ( v9 < v5[2] );
          }
          ++*(_DWORD *)(dword_8B8F28 + 432);
          Wrapper_e0f0(v5, 4);
          v6 = a2 & 0x20;
        }
        else if ( (a3 & 0x20) != 0 )
        {
          if ( (v7 & 3) != 0 )
          {
            if ( (v7 & 1) != 0 )
              sub_55DA50(0);
            else
              sub_55E320(0);
            if ( (i[5] & 0x400000) != 0 )
              sub_55EB30(v5);
          }
          else
          {
            sub_55D900(0);
          }
        }
        v5 += 16;
        ++v11;
      }
      while ( v11 < i[70] );
    }
  }
}

