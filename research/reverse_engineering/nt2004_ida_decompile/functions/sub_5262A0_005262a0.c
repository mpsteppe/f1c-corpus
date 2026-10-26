float *__thiscall sub_5262A0(_BYTE *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st7
  double v5; // st6
  int v6; // eax
  int v7; // eax
  int v9; // [esp+4h] [ebp-8h]
  float v10; // [esp+8h] [ebp-4h]

  v2 = sub_51E730((float *)(*(_DWORD *)this + 84));
  v3 = flt_7D4054[(unsigned __int8)dword_7D3C50++] * 0.050000001;
  v10 = v3 + v2 * 0.85000002 + 0.15000001;
  v4 = sub_51E730((float *)(*(_DWORD *)this + 84));
  v5 = flt_7D4054[(unsigned __int8)dword_7D3C50++];
  v6 = rand();
  if ( v6 >= 10922 )
    v7 = (v6 < 21844) + 15;
  else
    v7 = 17;
  *(float *)&v9 = v5 * 0.050000001 + (v4 - 0.25) * 0.5 + 1.0;
  return sub_526050(this, v7, 1, v10, v9);
}
