void __stdcall sub_4B7C20(float a1)
{
  int v1; // edi
  double v2; // st7
  __int64 v3; // rax
  float v4; // [esp+8h] [ebp+4h]

  if ( dword_7660C8 )
  {
    v4 = a1 * a1;
    v1 = (__int64)((double)dword_6152EC * 0.3333333333333333 * v4);
    sub_5069D0(0, 0, 1, 0);
    sub_506980(v1, v1);
    v2 = v4;
    if ( v4 >= 0.0 )
    {
      if ( v4 > 1.0 )
        v2 = 1.0;
    }
    else
    {
      v2 = 0.0;
    }
    v3 = (__int64)((1.0 - v2) * 0.0 + v2 * 255.0);
    sub_506B20((unsigned __int8)v3 | (((unsigned __int8)v3 | (((unsigned __int8)v3 | ((unsigned __int8)v3 << 8)) << 8)) << 8));
    sub_506960(0);
  }
}
