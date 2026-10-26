int __thiscall sub_42C690(void *this)
{
  double v1; // st7
  int v2; // ebp
  int v3; // eax
  int i; // esi
  int v5; // esi
  int j; // esi
  int k; // esi
  int m; // esi
  int n; // esi
  float v11; // [esp+4h] [ebp-1Ch]
  float v12; // [esp+4h] [ebp-1Ch]
  float v13; // [esp+4h] [ebp-1Ch]
  double v15; // [esp+18h] [ebp-8h]

  if ( dword_8AB6E4 != 2 )
  {
    sub_42C440();
    v1 = dbl_8AFEA0 * 400.0;
    sub_5895A2(dbl_8AFEA0 * 400.0);
    v2 = sub_587BDC(v1);
    v3 = dword_7C5694;
    if ( v2 - dword_7C5694 > 201 )
    {
      v3 = v2 - 201;
      dword_7C5694 = v2 - 201;
    }
    v15 = (double)dword_7C5694 * 0.0025;
    if ( v3 < v2 )
    {
      do
      {
        v15 = v15 + 0.0025;
        if ( dword_7C5698 % 10 )
        {
          if ( !*(_DWORD *)(dword_7C54E8 + 13000)
            && (!dword_7CE958 || (dword_7C5698 & 1) == 0)
            && (*(_DWORD *)(dword_7C54E8 + 18620) & 8) != 0 )
          {
            v12 = v15;
            sub_4E4930(v12);
          }
        }
        else
        {
          for ( i = 0; i < dword_5C329C; ++i )
            sub_424E70(dword_7C54F0[i]);
          v11 = v15;
          sub_410980(dword_5EA560, v11);
          v5 = 0;
          dword_7C932C = 0;
          dword_7C9330 = 0;
          dword_7C9334 = 0;
          dword_7C9338 = 0;
          dword_7C933C = 0;
          dword_7C9340 = 0;
          dword_7C9344 = 0;
          dword_7C9348 = 0;
          dword_7C934C = 0;
          dword_7C9350 = 0;
          dword_7C9354 = 0;
          for ( dword_7C9358 = 0; v5 < dword_5C329C; ++v5 )
            sub_4EB430(dword_7C54F0[v5] + 12);
          for ( j = 0; j < dword_5C329C; ++j )
            sub_4EE2D0(dword_7C54F0[j] + 12);
          if ( !(dword_7C5698 % 400) )
          {
            for ( k = 0; k < dword_5C329C; ++k )
            {
              if ( *(_DWORD *)(dword_7C54F0[k] + 13000) == 1 )
                sub_4ED960(1.0);
            }
          }
          if ( !(dword_7C5698 % 50) )
          {
            sub_42CAA0(this);
            for ( m = 0; m < dword_5C329C; ++m )
              sub_4F1C40(0.125);
            for ( n = 0; n < dword_5C329C; ++n )
            {
              if ( *(_DWORD *)(dword_7C54F0[n] + 13000) == 1 )
                sub_4ED810(0.125);
            }
          }
          if ( !*(_DWORD *)(dword_7C54E8 + 13000) )
            sub_4BCCC0(0.025);
          if ( !(dword_7C5698 % dword_8AD23C) )
          {
            if ( dword_8AD238 )
              sub_4D5960(&dword_8AD238);
            if ( !dword_7C5698 && dword_8AD238 )
              sub_4D59B0(&dword_8AD238);
          }
        }
        if ( ++dword_7C5698 >= 400 )
          dword_7C5698 = 0;
        ++dword_7C5694;
      }
      while ( dword_7C5694 < v2 );
    }
    if ( dword_7CBF24 )
      sub_451720(&unk_7CBB10);
  }
  v13 = dbl_8AFEA0;
  return sub_4109D0(dword_5EA560, v13);
}
