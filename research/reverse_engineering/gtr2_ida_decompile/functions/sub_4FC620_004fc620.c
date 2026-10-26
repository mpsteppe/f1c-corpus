int __thiscall sub_4FC620(_DWORD *this)
{
  int result; // eax
  int v3; // eax
  int v4; // ecx
  double v5; // st7
  double v6; // st7
  int v7; // ebp
  int v8; // ecx
  int v9; // edi
  int v10; // esi
  int v11; // edx
  double v12; // st7
  double v13; // st7
  int v14; // edx
  double v15; // st7
  double v16; // st7
  int v17; // edx
  double v18; // st7
  double v19; // st7
  int v20; // edx
  double v21; // st7
  double v22; // st7
  int v23; // edx
  double v24; // st7
  double v25; // st7
  _DWORD *v26; // ecx
  bool v27; // [esp+7h] [ebp-1Dh]
  float v28; // [esp+8h] [ebp-1Ch]
  float v29; // [esp+Ch] [ebp-18h] BYREF
  float v30; // [esp+10h] [ebp-14h]
  float v31; // [esp+14h] [ebp-10h]
  float v32; // [esp+18h] [ebp-Ch]
  float v33; // [esp+1Ch] [ebp-8h]
  float v34; // [esp+20h] [ebp-4h]

  result = this[5];
  if ( result )
  {
    v27 = *(float *)(*this + 17228) > 0.0;
    v3 = sub_5761B0(*this + 16);
    v4 = *(_DWORD *)(v3 + 276);
    v5 = *(float *)(v4 + 4);
    v4 += 4;
    v32 = v5 - *(float *)(v3 + 4);
    v33 = *(float *)(v4 + 4) - *(float *)(v3 + 8);
    v6 = *(float *)(v4 + 8) - *(float *)(v3 + 12);
    v30 = v33;
    v34 = v6;
    v29 = v32;
    v31 = v34;
    sub_409390(&v29);
    v7 = dword_757C10;
    v8 = 0;
    v28 = v31 * *(float *)(*this + 15996) + v30 * *(float *)(*this + 15992) + v29 * *(float *)(*this + 15988);
    if ( dword_757C10 >= 4 )
    {
      v9 = this[1];
      v10 = 2;
      do
      {
        if ( v8 != v9 )
        {
          v11 = *(&dword_91E088 + v8);
          if ( *(_BYTE *)(v11 + 15572) )
          {
            v12 = v31 * *(float *)(v11 + 16020) + v30 * *(float *)(v11 + 16016) + v29 * *(float *)(v11 + 16012);
            if ( v12 != 0.0 )
            {
              v13 = (v28
                   - (v31 * *(float *)(v11 + 15996)
                    + v30 * *(float *)(v11 + 15992)
                    + v29 * *(float *)(v11 + 15988)))
                  / v12;
              if ( v13 > 0.0 && v13 < 5.5 )
                v27 = 0;
            }
          }
        }
        if ( v10 - 1 != v9 )
        {
          v14 = dword_91E08C[v8];
          if ( *(_BYTE *)(v14 + 15572) )
          {
            v15 = v31 * *(float *)(v14 + 16020) + v30 * *(float *)(v14 + 16016) + v29 * *(float *)(v14 + 16012);
            if ( v15 != 0.0 )
            {
              v16 = (v28
                   - (v31 * *(float *)(v14 + 15996)
                    + v30 * *(float *)(v14 + 15992)
                    + v29 * *(float *)(v14 + 15988)))
                  / v15;
              if ( v16 > 0.0 && v16 < 5.5 )
                v27 = 0;
            }
          }
        }
        if ( v10 != v9 )
        {
          v17 = dword_91E090[v8];
          if ( *(_BYTE *)(v17 + 15572) )
          {
            v18 = v31 * *(float *)(v17 + 16020) + v30 * *(float *)(v17 + 16016) + v29 * *(float *)(v17 + 16012);
            if ( v18 != 0.0 )
            {
              v19 = (v28
                   - (v31 * *(float *)(v17 + 15996)
                    + v30 * *(float *)(v17 + 15992)
                    + v29 * *(float *)(v17 + 15988)))
                  / v18;
              if ( v19 > 0.0 && v19 < 5.5 )
                v27 = 0;
            }
          }
        }
        if ( v10 + 1 != v9 )
        {
          v20 = dword_91E094[v8];
          if ( *(_BYTE *)(v20 + 15572) )
          {
            v21 = v31 * *(float *)(v20 + 16020) + v30 * *(float *)(v20 + 16016) + v29 * *(float *)(v20 + 16012);
            if ( v21 != 0.0 )
            {
              v22 = (v28
                   - (v31 * *(float *)(v20 + 15996)
                    + v30 * *(float *)(v20 + 15992)
                    + v29 * *(float *)(v20 + 15988)))
                  / v21;
              if ( v22 > 0.0 && v22 < 5.5 )
                v27 = 0;
            }
          }
        }
        v8 += 4;
        v10 += 4;
      }
      while ( v8 < dword_757C10 - 3 );
      v7 = dword_757C10;
    }
    if ( v8 < v7 )
    {
      do
      {
        if ( v8 != this[1] )
        {
          v23 = *(&dword_91E088 + v8);
          if ( *(_BYTE *)(v23 + 15572) )
          {
            v24 = v31 * *(float *)(v23 + 16020) + v30 * *(float *)(v23 + 16016) + v29 * *(float *)(v23 + 16012);
            if ( v24 != 0.0 )
            {
              v25 = (v28
                   - (v31 * *(float *)(v23 + 15996)
                    + v30 * *(float *)(v23 + 15992)
                    + v29 * *(float *)(v23 + 15988)))
                  / v24;
              if ( v25 > 0.0 && v25 < 5.5 )
                v27 = 0;
            }
          }
        }
        ++v8;
      }
      while ( v8 < dword_757C10 );
    }
    v26 = (_DWORD *)this[5];
    result = v26[192];
    if ( v27 )
    {
      if ( result == 1 )
        return sub_4F2190();
    }
    else if ( result == 2 )
    {
      return sub_4F2160(v26);
    }
  }
  return result;
}
