int __cdecl sub_498B00(float a1, int a2, float a3, float a4, float a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // ecx
  int v11; // esi
  double v12; // st7
  char v13; // al
  int v14; // eax
  long double v15; // st7
  double v16; // st7
  double v17; // st6
  float v19; // [esp+4h] [ebp-28h] BYREF
  float v20; // [esp+8h] [ebp-24h]
  float v21; // [esp+Ch] [ebp-20h]
  int v22; // [esp+10h] [ebp-1Ch] BYREF
  int v23; // [esp+14h] [ebp-18h] BYREF
  int v24; // [esp+18h] [ebp-14h] BYREF
  int v25; // [esp+1Ch] [ebp-10h] BYREF
  int v26; // [esp+20h] [ebp-Ch] BYREF
  int v27; // [esp+24h] [ebp-8h] BYREF
  _BYTE v28[4]; // [esp+28h] [ebp-4h] BYREF

  v11 = v10;
  if ( !dword_B6E070 )
    JUMPOUT(0x498D71);
  v26 = 0;
  v25 = 0;
  v24 = 0;
  v23 = 0;
  v19 = 0.0;
  v22 = 0;
  sub_4DE540(&v27, v28);
  v20 = sub_4DE460(*(_DWORD *)(v11 + 48));
  v12 = flt_B6E074 + v20;
  flt_B6E074 = v12;
  if ( v12 > 3.0 )
    flt_B6E074 = 3.0;
  sub_5DA610(&v26, &v25, &v24, &v23, &v19, &v22);
  v13 = *(_BYTE *)(v11 + 272);
  v19 = *(float *)&dword_B6E078;
  if ( v13 )
  {
    sub_4DF3F0(3);
    flt_B6E074 = 0.0;
    if ( v20 != 0.0 )
    {
      LODWORD(v21) = v27 - *(_DWORD *)(v11 + 288);
      flt_759F28 = (double)SLODWORD(v21) / v20 * 0.5;
    }
    v14 = v27 - *(_DWORD *)(v11 + 288);
    v15 = sqrt(flt_759F28 * flt_759F28) * 0.00030000001;
    if ( v14 <= 0 )
    {
      if ( v14 < 0 )
      {
        v19 = v15 + v19;
        JUMPOUT(0x498D2A);
      }
    }
    else
    {
      v19 = v19 - v15;
    }
    JUMPOUT(0x498D28);
  }
  v21 = sqrt(flt_759F28 * flt_759F28) * 0.00019999999 * (1.0 - flt_B6E074 * 0.33333334);
  v16 = v20 * 0.5;
  if ( flt_759F28 > 20.0 && flt_B6E074 < 3.0 )
  {
    v17 = v19 - (v21 + v16);
LABEL_16:
    v19 = v17;
    goto LABEL_17;
  }
  if ( flt_759F28 > 0.0 )
  {
    v17 = v19 - v16;
    goto LABEL_16;
  }
LABEL_17:
  if ( flt_759F28 >= -20.0 || flt_B6E074 >= 3.0 )
    JUMPOUT(0x498D11);
  return sub_498D03(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
