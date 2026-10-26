int __stdcall sub_48B750(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // esi
  double v6; // st7
  int v7; // edi
  double v8; // st7
  int i; // edi
  double v10; // st7
  double v12; // [esp+Ch] [ebp-74h] BYREF
  float v13; // [esp+14h] [ebp-6Ch] BYREF
  float v14; // [esp+18h] [ebp-68h] BYREF
  float v15[2]; // [esp+1Ch] [ebp-64h] BYREF
  int v16; // [esp+24h] [ebp-5Ch]
  float v17; // [esp+28h] [ebp-58h] BYREF
  float v18; // [esp+2Ch] [ebp-54h]
  double v19; // [esp+30h] [ebp-50h] BYREF
  double v20; // [esp+38h] [ebp-48h] BYREF
  double v21[8]; // [esp+40h] [ebp-40h]

  sub_49E3A0(a1, a2, a3, a4);
  if ( (unsigned __int8)sub_49D870(0, &v12, (char *)&v12 + 4) && (unsigned __int8)sub_49D870(1, &v13, &v14) )
  {
    if ( dword_7DA988 && dword_7E8CDC )
    {
      LODWORD(v15[0]) = LODWORD(v12) * *(_DWORD *)(dword_7E8CDC + 28);
      v15[0] = (double)SLODWORD(v15[0]) * 0.00125;
      v16 = (int)v15[0];
      LODWORD(v12) = v16;
      v16 = HIDWORD(v12) * *(_DWORD *)(dword_7E8CDC + 32);
      *(float *)&v16 = (double)v16 * 0.0016666667;
      LODWORD(v15[0]) = (int)*(float *)&v16;
      *((float *)&v12 + 1) = v15[0];
      v16 = LODWORD(v13) * *(_DWORD *)(dword_7E8CDC + 28);
      *(float *)&v16 = (double)v16 * 0.00125;
      LODWORD(v15[0]) = (int)*(float *)&v16;
      v13 = v15[0];
      v16 = LODWORD(v14) * *(_DWORD *)(dword_7E8CDC + 32);
      *(float *)&v16 = (double)v16 * 0.0016666667;
      LODWORD(v15[0]) = (int)*(float *)&v16;
      v14 = v15[0];
    }
    v20 = 0.0;
    v19 = 0.0;
    v17 = 0.0;
    v18 = 0.0;
    v4 = sub_434600(&byte_75CBC8);
    v16 = LODWORD(v14) - HIDWORD(v12);
    v5 = v4;
    LODWORD(v15[0]) = (__int64)(((double)dword_75E14C * dbl_75E140 + dbl_75E138)
                              * 9.549296585513721
                              * 0.0001
                              * (double)(LODWORD(v14) - HIDWORD(v12))
                              + (double)SHIDWORD(v12));
    if ( byte_768A14 )
      v6 = 3.6;
    else
      v6 = 2.236936292054402;
    *(float *)&v16 = v6;
    v7 = 0;
    v20 = v12;
    if ( v4 > 0 )
    {
      do
      {
        v8 = sub_434630((int)&byte_75CBC8, v7++);
        v21[v7 - 1] = v8 * *(float *)&v16;
      }
      while ( v7 < v5 );
    }
    v16 = LODWORD(v13) - LODWORD(v12);
    v19 = v20;
    LODWORD(v17) = (__int64)((double)(LODWORD(v13) - LODWORD(v12)) * (v21[0] * 0.01) + (double)SLODWORD(v12));
    v18 = v15[0];
    sub_48BA10(&v19, &v17);
    for ( i = 1; i < v5; ++i )
    {
      v10 = v21[i] * 0.01;
      v15[0] = v17;
      v16 = LODWORD(v13) - LODWORD(v12);
      v15[1] = v18;
      LODWORD(v17) = (__int64)(v10 * (double)(LODWORD(v13) - LODWORD(v12)) + (double)SLODWORD(v12));
      sub_48BA50(LODWORD(v15[0]), &v20, &v17, &v19);
      sub_48BA10(v15, &v19);
      sub_48BA10(&v19, &v17);
    }
  }
  return 0;
}
