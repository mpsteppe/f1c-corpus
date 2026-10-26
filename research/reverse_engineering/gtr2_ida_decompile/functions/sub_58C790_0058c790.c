int __thiscall sub_58C790(void *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st7
  double v5; // st6
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  int v10; // [esp+10h] [ebp-20h]
  float v11; // [esp+28h] [ebp-8h]
  float v12; // [esp+2Ch] [ebp-4h]

  v2 = sub_578630((float *)(*(_DWORD *)this + 16));
  v3 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++] * 0.050000001;
  v11 = v3 + v2 * 0.69999999 + 0.30000001;
  v4 = sub_578630((float *)(*(_DWORD *)this + 16));
  v5 = flt_BE0CA4[(unsigned __int8)dword_BE08A0++];
  v6 = rand();
  if ( v6 >= 10922 )
    v7 = (v6 < 21844) + 27;
  else
    v7 = 29;
  sub_58C630(this, v7);
  v8 = off_9034A4;
  if ( dword_82F4A0 < 1023 )
  {
    ++dword_82F4A0;
    off_9034A4 += 848;
  }
  *(float *)&v10 = dbl_FB1D18;
  sub_51B2A0((_DWORD *)v8, 3, 0, 3, *(_DWORD *)(*(_DWORD *)this + 22468), v10, 1);
  v12 = v5 * 0.050000001 + (v4 - 0.25) * 0.5 + 1.0;
  return sub_51AA40((_BYTE *)(v8 + 8), v7, 1, v11, v12);
}
