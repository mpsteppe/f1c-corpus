void __thiscall sub_550650(float *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // ebp
  float v5; // ebx
  int v6; // esi
  int v7; // eax
  long double v8; // st7
  _DWORD *v9; // esi
  int v10; // [esp-4h] [ebp-90h]
  int v11; // [esp+0h] [ebp-8Ch]
  float v12; // [esp+14h] [ebp-78h]
  float v13; // [esp+18h] [ebp-74h]
  float v14; // [esp+18h] [ebp-74h]
  float v15; // [esp+20h] [ebp-6Ch] BYREF
  float v16; // [esp+24h] [ebp-68h] BYREF
  float v17[7]; // [esp+28h] [ebp-64h] BYREF
  float v18; // [esp+44h] [ebp-48h] BYREF
  float v19; // [esp+48h] [ebp-44h]
  float v20; // [esp+4Ch] [ebp-40h]
  float v21; // [esp+50h] [ebp-3Ch] BYREF
  float v22; // [esp+54h] [ebp-38h]
  float v23; // [esp+58h] [ebp-34h]
  float v24; // [esp+5Ch] [ebp-30h]
  float v25; // [esp+60h] [ebp-2Ch]
  float v26; // [esp+64h] [ebp-28h]
  float v27; // [esp+68h] [ebp-24h]
  float v28; // [esp+6Ch] [ebp-20h]
  float v29; // [esp+70h] [ebp-1Ch]
  _DWORD v30[3]; // [esp+74h] [ebp-18h] BYREF
  _DWORD v31[3]; // [esp+80h] [ebp-Ch] BYREF

  v18 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  memset(v30, 0, sizeof(v30));
  sub_4013C0(&flt_91BCA0, 0, &v18, v30);
  if ( v18 != 0.0 || v19 != 0.0 || v20 != 0.0 )
  {
    v13 = this[69] * 0.75;
    if ( (_BYTE)dword_757C1C )
    {
      v2 = dword_91E084;
      if ( dword_91E084 )
      {
        if ( *(_DWORD *)(dword_91E084 + 14820) != -1 && !byte_B6F118 )
        {
          if ( !*(_DWORD *)(dword_91E084 + 14820) && !sub_54EDF0() )
          {
            sub_53E3E0(v2);
            *(float *)&dword_757C20 = dbl_FB1D18 + 3.0;
          }
          sub_42C920(dbl_FB1D18);
        }
      }
    }
    v3 = dword_757C10;
    v4 = 0;
    if ( dword_757C10 > 0 )
    {
      v5 = v13;
      do
      {
        v6 = *(_DWORD *)(*(&dword_91E088 + v4) + 19316) - 1;
        v7 = v3 - 1;
        if ( v6 >= 0 )
        {
          if ( v6 > v7 )
            v6 = v7;
        }
        else
        {
          v6 = 0;
        }
        if ( *(_DWORD *)dword_B72314 == 7 )
        {
          sub_4013C0(&flt_91BCA0, 0, &v21, v31);
          sub_5DA7A0(&v15, &v16, v17);
          v6 = 0;
          v12 = 0.0;
          v24 = v15 - v21;
          v17[1] = v24;
          v25 = v16 - v22;
          v17[2] = v25;
          v26 = v17[0] - v23;
          v17[3] = v26;
          v14 = sqrt(v26 * v26 + v25 * v25 + v24 * v24) * 4.0;
          if ( v14 > 0.0 )
          {
            do
            {
              if ( v6 >= 101 )
                break;
              sub_4013C0(&flt_91BCA0, v6, &v21, v31);
              v6 += 2;
              sub_4013C0(&flt_91BCA0, v6, &v15, v31);
              v27 = v15 - v21;
              v17[4] = v27;
              v28 = v16 - v22;
              v17[5] = v28;
              v29 = v17[0] - v23;
              v17[6] = v29;
              v8 = sqrt(v29 * v29 + v28 * v28 + v27 * v27) + v12;
              v12 = v8;
            }
            while ( v8 < v14 );
          }
        }
        sub_4013C0(&flt_91BCA0, v6, &v18, v30);
        v9 = (_DWORD *)*(&dword_91E088 + v4);
        if ( !(unsigned __int8)sub_4275E0() && (!sub_53F260(v9) || byte_B6F118 != 1) && v9[3705] != 4 )
        {
          sub_57DCC0(&v18, v30);
          sub_57F840(v5);
          sub_4FC460(v9 + 3706);
          v9[4822] = 2;
          v9[4888] = 0;
          sub_52BE40(v10, v11);
          sub_429540();
        }
        v3 = dword_757C10;
        ++v4;
      }
      while ( v4 < dword_757C10 );
    }
    sub_52B230(&byte_9034D0, 1);
    sub_52B190(&byte_9034D0, 0);
  }
}
