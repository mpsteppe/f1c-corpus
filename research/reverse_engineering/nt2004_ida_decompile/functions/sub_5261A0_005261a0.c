float *__thiscall sub_5261A0(_BYTE *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st7
  double v5; // st7
  double v6; // st6
  int v7; // eax
  int v8; // eax
  int v10; // [esp+4h] [ebp-8h]
  float v11; // [esp+8h] [ebp-4h]

  v2 = *(float *)(*(_DWORD *)this + 18820) / *(float *)(*(_DWORD *)this + 18824);
  if ( v2 >= 0.0 )
  {
    if ( v2 > 1.0 )
      v2 = 1.0;
  }
  else
  {
    v2 = 0.0;
  }
  v3 = v2;
  v4 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  v11 = v3 * 0.85000002 + 0.15000001 + v4 * 0.050000001;
  v5 = sub_51E730((float *)(*(_DWORD *)this + 84));
  v6 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  v7 = rand();
  if ( v7 >= 10922 )
    v8 = (v7 < 21844) + 12;
  else
    v8 = 14;
  *(float *)&v10 = v6 * 0.050000001 + (v5 - 0.25) * 0.5 + 1.0;
  return sub_526050(this, v8, 1, v11, v10);
}
