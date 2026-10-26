int __thiscall sub_5FBDC0(_DWORD *this, int a2)
{
  _DWORD *v2; // edi
  int v3; // eax
  int v4; // ecx
  _DWORD *v5; // ebx
  _DWORD *v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // edx
  _DWORD *v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ebp
  int v15; // eax
  _DWORD *v16; // edx
  int v17; // eax
  int v18; // edi
  int v19; // eax
  _DWORD *v20; // ecx
  bool v21; // cc
  int v24; // [esp+8h] [ebp-8h]
  int v25; // [esp+Ch] [ebp-4h]

  v2 = this;
  if ( (int)*this > 0 )
  {
    if ( (_BYTE)a2 )
      sub_632C60(this[4], *this);
    v3 = 0;
    v25 = 0;
    if ( (int)*v2 > 0 )
    {
      v4 = dword_FB27A4;
      do
      {
        v5 = *(_DWORD **)(v2[4] + 8 * v3 + 4);
        if ( (*(int (__thiscall **)(int, _DWORD *))(*(_DWORD *)v4 + 396))(v4, v5) )
        {
          v6 = (_DWORD *)v5[91];
          v24 = 0;
          if ( (*v5 & 0x40000000) == 0 || *((_BYTE *)dword_FB27AC + 200) )
          {
            v4 = dword_FB27A4;
          }
          else
          {
            v7 = v6[22];
            v8 = *(_DWORD *)(v7 + 796);
            if ( !v8 )
            {
              v9 = *(_DWORD *)(dword_FB27A4 + 9100);
              v8 = *(_DWORD *)(dword_FB27A4 + 9124) + 4 * v9;
              *(_DWORD *)(dword_FB27A4 + 9100) = v9 + 1;
              *(_DWORD *)(v7 + 796) = v8;
            }
            if ( !*(_DWORD *)v8 )
              *(_DWORD *)v8 = v7;
            v10 = *(_DWORD **)(*(_DWORD *)v8 + 772);
            *(_DWORD *)(v10[1] + 4 * (*v10)++) = dword_FB27AC;
            *((_BYTE *)dword_FB27AC + 200) = 1;
            v4 = dword_FB27A4;
            if ( v8 != *(_DWORD *)(dword_FB27A4 + 9124) )
            {
              v11 = *(_DWORD *)v8;
              a2 = *(_DWORD *)v8;
              v12 = *(_DWORD *)(dword_FB27A4 + 9124);
              if ( v8 != v12 )
              {
                do
                {
                  v13 = *(_DWORD *)(v8 - 4);
                  *(_DWORD *)v8 = v13;
                  *(_DWORD *)(v13 + 796) = v8;
                  v8 -= 4;
                }
                while ( v8 != v12 );
                v11 = a2;
              }
              *(_DWORD *)v8 = v11;
              *(_DWORD *)(v11 + 796) = v8;
              nullsub_7(&a2);
              v4 = dword_FB27A4;
            }
            v2 = this;
          }
          if ( (int)v5[90] > 0 )
          {
            do
            {
              v14 = v6[22];
              v15 = v6[19];
              v16 = *(_DWORD **)(v14 + 4 * v15 + 780);
              if ( !v16 )
              {
                v17 = *(_DWORD *)(v4 + 4 * v15 + 9084);
                v18 = v6[19];
                v16 = (_DWORD *)(*(_DWORD *)(v4 + 4 * v18 + 9108) + 4 * v17);
                *(_DWORD *)(v4 + 4 * v18 + 9084) = v17 + 1;
                *(_DWORD *)(v14 + 4 * v6[19] + 780) = v16;
              }
              if ( !*v16 )
                *v16 = v6[22];
              v19 = v6[1];
              if ( !*(_BYTE *)(v19 + 200) )
              {
                v20 = *(_DWORD **)(*v16 + 4 * v6[19] + 756);
                *(_DWORD *)(v20[1] + 4 * (*v20)++) = v19;
                *(_BYTE *)(v19 + 200) = 1;
              }
              *(_DWORD *)(*(_DWORD *)(v19 + 212) + 4 * (*(_DWORD *)(v19 + 208))++) = v6;
              v6 += 27;
              v21 = v24 + 1 < v5[90];
              v4 = dword_FB27A4;
              ++v24;
            }
            while ( v21 );
            v2 = this;
          }
        }
        else
        {
          v4 = dword_FB27A4;
        }
        v3 = ++v25;
      }
      while ( v25 < *v2 );
    }
  }
  return *v2;
}
