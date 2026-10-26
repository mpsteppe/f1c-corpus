int __thiscall sub_42E720(void *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // ecx
  bool v5; // zf
  signed int v6; // ecx
  int v7; // edi
  int v8; // esi
  signed int i; // esi
  char *v10; // esi
  int v11; // edi
  int v12; // esi
  signed int j; // esi
  int v14; // esi
  int v15; // edi
  int v16; // edi
  signed int k; // esi
  int v18; // esi
  int v19; // edi
  signed int v20; // esi
  int m; // esi
  signed int v22; // eax
  signed int n; // esi
  signed int ii; // esi
  int v25; // ecx
  int v26; // ecx
  float X_4; // [esp+4h] [ebp-24h]
  float X_4a; // [esp+4h] [ebp-24h]
  float X_4b; // [esp+4h] [ebp-24h]
  int v31; // [esp+1Ch] [ebp-Ch]
  double v32; // [esp+20h] [ebp-8h]

  if ( dword_7D5DA4 != 2 )
  {
    sub_42E4B0();
    v2 = (__int64)floor(dbl_7DA9D0 * 320.0);
    v3 = dword_75AB94;
    v31 = v2;
    if ( v2 - dword_75AB94 > 161 )
    {
      v3 = v2 - 161;
      dword_75AB94 = v2 - 161;
    }
    v32 = (double)dword_75AB94 * 0.003125;
    if ( v3 < v2 )
    {
      v4 = dword_75AB98;
      do
      {
        v6 = v4 & 0x80000007;
        v5 = v6 == 0;
        v32 = v32 + 0.003125;
        if ( v6 < 0 )
          v5 = (((_BYTE)v6 - 1) | 0xFFFFFFF8) == -1;
        if ( v5 )
        {
          v7 = 0;
          if ( dword_5FD344 > 0 )
          {
            v8 = 0;
            do
            {
              sub_423870((int)off_5FD348 + v8);
              ++v7;
              v8 += 25304;
            }
            while ( v7 < dword_5FD344 );
          }
          for ( i = 0; i < (int)NumOfElements; ++i )
            sub_423870(dword_75AAD0[i]);
          sub_41F410(flt_62BC28);
          v10 = byte_62A3C0;
          do
          {
            sub_41F550(v10);
            v10 += 128;
          }
          while ( (int)v10 < (int)&flt_62BBC0 );
          v11 = 0;
          if ( dword_5FD344 > 0 )
          {
            v12 = 0;
            do
            {
              sub_421970((int)off_5FD348 + v12);
              ++v11;
              v12 += 25304;
            }
            while ( v11 < dword_5FD344 );
          }
          for ( j = 0; j < (int)NumOfElements; ++j )
            sub_421970(dword_75AAD0[j]);
          X_4 = v32;
          sub_417A50(dword_6291D0, X_4);
          v14 = 0;
          dword_760AE0 = 0;
          dword_760AE4 = 0;
          dword_760AE8 = 0;
          dword_760AEC = 0;
          dword_760AF0 = 0;
          dword_760AF4 = 0;
          dword_760AF8 = 0;
          dword_760AFC = 0;
          dword_760B00 = 0;
          dword_760B04 = 0;
          dword_760B08 = 0;
          dword_760B0C = 0;
          if ( dword_5FD344 > 0 )
          {
            v15 = 0;
            do
            {
              sub_516FF0((int)off_5FD348 + v15 + 84);
              ++v14;
              v15 += 25304;
            }
            while ( v14 < dword_5FD344 );
          }
          v16 = NumOfElements;
          for ( k = 0; k < (int)NumOfElements; ++k )
          {
            sub_516FF0(dword_75AAD0[k] + 84);
            v16 = NumOfElements;
          }
          v18 = 0;
          if ( dword_5FD344 > 0 )
          {
            v19 = 0;
            do
            {
              sub_51A8C0((char *)off_5FD348 + v19 + 84);
              ++v18;
              v19 += 25304;
            }
            while ( v18 < dword_5FD344 );
            v16 = NumOfElements;
          }
          v20 = 0;
          if ( v16 > 0 )
          {
            do
            {
              sub_51A8C0(dword_75AAD0[v20] + 84);
              v16 = NumOfElements;
              ++v20;
            }
            while ( v20 < (int)NumOfElements );
          }
          if ( !(dword_75AB98 % 320) )
          {
            for ( m = 0; m < v16; ++m )
            {
              if ( *(_DWORD *)(dword_75AAD0[m] + 16584) == 1 )
              {
                sub_519DE0(1.0);
                v16 = NumOfElements;
              }
            }
          }
          if ( !(dword_75AB98 % 40) )
          {
            sub_42EDE0(this);
            v22 = NumOfElements;
            for ( n = 0; n < (int)NumOfElements; ++n )
            {
              sub_51E840(0.125);
              v22 = NumOfElements;
            }
            for ( ii = 0; ii < v22; ++ii )
            {
              if ( *(_DWORD *)(dword_75AAD0[ii] + 16584) == 1 )
              {
                sub_519C90(0.125);
                v22 = NumOfElements;
              }
            }
          }
          if ( sub_42DBC0() )
          {
            v25 = *(_DWORD *)(dword_75AACC + 16584);
            if ( v25 )
            {
              if ( v25 == 1 )
                sub_4DDB70(0.025, 1);
            }
            else
            {
              sub_4DDB70(0.025, 0);
            }
          }
          v26 = dword_75AB98;
          if ( !(dword_75AB98 % dword_7D7900) )
          {
            if ( dword_7D78FC )
            {
              sub_4FE790(&dword_7D78FC);
              v26 = dword_75AB98;
            }
            if ( !v26 && dword_7D78FC )
            {
              sub_4FE7E0(&dword_7D78FC);
              v26 = dword_75AB98;
            }
          }
          v2 = v31;
          goto LABEL_56;
        }
        if ( sub_42DBC0() && !*(_DWORD *)(dword_75AACC + 16584) )
        {
          v26 = dword_75AB98;
          if ( *(_DWORD *)dword_766AA4 && (dword_75AB98 & 1) != 0 || (*(_DWORD *)(dword_75AACC + 25296) & 8) == 0 )
            goto LABEL_56;
          X_4b = v32;
          sub_50FD30(X_4b);
        }
        v26 = dword_75AB98;
LABEL_56:
        v4 = v26 + 1;
        dword_75AB98 = v4;
        if ( v4 >= 320 )
        {
          v4 = 0;
          dword_75AB98 = 0;
        }
        ++dword_75AB94;
      }
      while ( dword_75AB94 < v2 );
    }
  }
  if ( dword_763714 )
    sub_453D00(&unk_763300);
  X_4a = dbl_7DA9D0;
  return sub_417AA0((float *)dword_6291D0, X_4a);
}
