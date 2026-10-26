void __thiscall sub_59EA50(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *i; // ebp
  int *v5; // esi
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // edi
  int v10; // edx
  int v11; // eax
  int v12; // [esp+4h] [ebp-8h]

  for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)i[4] )
  {
    v5 = (int *)i[71];
    v12 = 0;
    if ( (int)i[70] > 0 )
    {
      v6 = a2 & 0x20;
      do
      {
        v7 = a2 | ~a3 & *v5;
        v8 = v5[14] | 0x400;
        *v5 = v7;
        v5[14] = v8;
        if ( v6 )
        {
          v9 = (((*(int *)(dword_7E8E5C + 448) >> 4) & 3)
              + ((((*(int *)(dword_7E8E5C + 448) >> 2) & 3) + ((*(_DWORD *)(dword_7E8E5C + 448) & 3) << 8)) << 8)) << 6;
          unknown_libname_158((int)v5, 6);
          v10 = 0;
          if ( v5[2] > 0 )
          {
            v11 = 0;
            do
            {
              *(_DWORD *)(v11 + v5[8] + 24) &= 0xFF000000;
              *(_DWORD *)(v11 + v5[8] + 24) |= v9;
              ++v10;
              v11 += 64;
            }
            while ( v10 < v5[2] );
          }
          ++*(_DWORD *)(dword_7E8E5C + 448);
          unknown_libname_159((int)v5, 4);
          v6 = a2 & 0x20;
        }
        else if ( (a3 & 0x20) != 0 )
        {
          if ( (v7 & 3) != 0 )
          {
            if ( (v7 & 1) != 0 )
              sub_5B6060(0);
            else
              sub_5B6930(0);
            if ( (i[5] & 0x400000) != 0 )
              sub_5B7170(v5);
          }
          else
          {
            sub_5B5F10(0);
          }
        }
        v5 += 16;
        ++v12;
      }
      while ( v12 < i[70] );
    }
  }
}
