void __thiscall sub_4EE4E0(_DWORD *this, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // [esp+4h] [ebp-18h] BYREF
  int v13; // [esp+8h] [ebp-14h]
  int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch] BYREF
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]

  if ( flt_B70A44 != 0.0
    && this[106] == 2139095039
    && rand() % 2 != 1
    && this[96] == 2139095039
    && this[97] == 2139095039
    && this[98] == 2139095039
    && this[99] == 2139095039
    && this[102] == 2139095039
    && this[103] == 2139095039
    && this[104] == 2139095039
    && this[105] == 2139095039
    && this[100] == 2139095039
    && this[101] == 2139095039 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = this[v4];
      if ( v5 )
      {
        if ( (*(int (**)(void))(*(_DWORD *)v5 + 28))() != 2 )
          break;
      }
      if ( ++v4 >= 93 )
      {
        if ( !sub_4EE100(&dbl_B66040)
          && !dword_FADE9C
          && (a3 != 2 || sub_41FE50((float *)(dword_91E084 + 16)) * 2.2369363 >= 30.0) )
        {
          if ( a2 )
          {
            if ( a2 == 1 )
            {
              if ( a3 == 2
                && this[107] != 2
                && !byte_B6F118
                && flt_B70A44 != 0.0
                && *(_DWORD *)dword_B72314 != 7
                && *(_DWORD *)dword_B72314 != 8
                && flt_B6F370 == 3.4028235e38 )
              {
                v8 = 0;
                while ( 1 )
                {
                  v9 = dword_B6F1C8[v8];
                  if ( v9 )
                  {
                    if ( (*(int (**)(void))(*(_DWORD *)v9 + 28))() != 2 )
                      break;
                  }
                  if ( ++v8 >= 81 )
                  {
                    if ( dword_B6F264 )
                    {
                      v12 = 0;
                      v13 = 0;
                      v14 = 0;
                      v15 = 0;
                      v16 = 0;
                      v17 = 0;
                      (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F264 + 4))(
                        dword_B6F264,
                        2,
                        &v12,
                        &v15,
                        LODWORD(flt_B70A44),
                        1065353216,
                        0);
                    }
                    break;
                  }
                }
              }
              this[107] = a3;
            }
            else if ( a2 == 2 )
            {
              if ( a3 == 2
                && this[108] != 2
                && !byte_B6F118
                && flt_B70A44 != 0.0
                && *(_DWORD *)dword_B72314 != 7
                && *(_DWORD *)dword_B72314 != 8
                && flt_B6F370 == 3.4028235e38 )
              {
                v6 = 0;
                while ( 1 )
                {
                  v7 = dword_B6F1C8[v6];
                  if ( v7 )
                  {
                    if ( (*(int (**)(void))(*(_DWORD *)v7 + 28))() != 2 )
                      break;
                  }
                  if ( ++v6 >= 81 )
                  {
                    if ( dword_B6F268 )
                    {
                      v15 = 0;
                      v16 = 0;
                      v17 = 0;
                      v12 = 0;
                      v13 = 0;
                      v14 = 0;
                      (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F268 + 4))(
                        dword_B6F268,
                        2,
                        &v15,
                        &v12,
                        LODWORD(flt_B70A44),
                        1065353216,
                        0);
                    }
                    break;
                  }
                }
              }
              this[108] = a3;
            }
          }
          else
          {
            if ( a3 == 2
              && this[109] != 2
              && !byte_B6F118
              && flt_B70A44 != 0.0
              && *(_DWORD *)dword_B72314 != 7
              && *(_DWORD *)dword_B72314 != 8
              && flt_B6F370 == 3.4028235e38 )
            {
              v10 = 0;
              while ( 1 )
              {
                v11 = dword_B6F1C8[v10];
                if ( v11 )
                {
                  if ( (*(int (**)(void))(*(_DWORD *)v11 + 28))() != 2 )
                    break;
                }
                if ( ++v10 >= 81 )
                {
                  if ( dword_B6F26C )
                  {
                    v12 = 0;
                    v13 = 0;
                    v14 = 0;
                    v15 = 0;
                    v16 = 0;
                    v17 = 0;
                    (*(void (__thiscall **)(int, int, int *, int *, _DWORD, int, _DWORD))(*(_DWORD *)dword_B6F26C + 4))(
                      dword_B6F26C,
                      2,
                      &v12,
                      &v15,
                      LODWORD(flt_B70A44),
                      1065353216,
                      0);
                  }
                  break;
                }
              }
            }
            this[109] = a3;
          }
        }
        return;
      }
    }
  }
}
