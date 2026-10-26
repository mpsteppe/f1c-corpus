int __thiscall sub_4FE7C0(float *this, int a2)
{
  _DWORD *v3; // eax
  int v5; // esi
  _BYTE v6[56]; // [esp+4h] [ebp-38h] BYREF

  sub_567A00(v6);
  sub_567F40(a2, 0);
  v3 = (_DWORD *)sub_568210(aWeather_1);
  if ( v3 )
  {
    v5 = sub_4FE350(this, v3);
    sub_567A30(v6);
    return v5;
  }
  else
  {
    sub_567A30(v6);
    return -1;
  }
}
