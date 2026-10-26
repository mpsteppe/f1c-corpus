int __thiscall sub_58EC30(void *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st7
  double v5; // st7
  double v6; // st6
  int v7; // eax
  int v8; // ebx
  int v9; // edi
  int v11; // [esp+10h] [ebp-20h]
  float v12; // [esp+28h] [ebp-8h]
  float v13; // [esp+2Ch] [ebp-4h]

  v2 = *(float *)(*(_DWORD *)this + 17228) / *(float *)(*(_DWORD *)this + 17232);
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
  v4 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
  v12 = v3 * 0.69999999 + 0.30000001 + v4 * 0.050000001;
  v5 = sub_578630((float *)(*(_DWORD *)this + 16));
  v6 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
  v7 = rand();
  if ( v7 >= 10922 )
    v8 = (v7 < 21844) + 24;
  else
    v8 = 26;
  sub_58C630(this, v8);
  v9 = off_9034A4;
  if ( dword_82F4A0 < 1023 )
  {
    ++dword_82F4A0;
    off_9034A4 += 848;
  }
  *(float *)&v11 = dbl_FB1D18;
  sub_51B2A0((_DWORD *)v9, 3, 0, 3, *(_DWORD *)(*(_DWORD *)this + 22468), v11, 1);
  v13 = v6 * 0.050000001 + (v5 - 0.25) * 0.5 + 1.0;
  return sub_51AA40((_BYTE *)(v9 + 8), v8, 1, v12, v13);
}
