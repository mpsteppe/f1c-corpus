int __thiscall sub_52CA90(float *this, char *Source)
{
  int v3; // eax
  int v5; // esi
  _BYTE v6[56]; // [esp+4h] [ebp-38h] BYREF

  sub_57A770(v6);
  sub_57AC50(Source, 0);
  v3 = sub_57AE50(aWeather);
  if ( v3 )
  {
    v5 = sub_52C610(this, v3);
    sub_57A7A0(v6);
    return v5;
  }
  else
  {
    sub_57A7A0(v6);
    return -1;
  }
}
