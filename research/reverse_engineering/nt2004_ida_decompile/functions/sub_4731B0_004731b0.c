void sub_4731B0()
{
  float v0; // [esp+0h] [ebp-24h]
  int v1; // [esp+1Ch] [ebp-8h] BYREF
  int v2; // [esp+20h] [ebp-4h] BYREF

  if ( dword_600F48 != dword_766178 )
  {
    dword_600F48 = dword_766178;
    if ( byte_7655A8 )
    {
      byte_7655A8 = 0;
      sub_455890((float *)&ppvOut);
      sub_455960(&ppvOut);
      sub_455BD0(&ppvOut);
    }
    sub_4582C0((float *)&ppvOut);
    v0 = dbl_7DA9C0;
    sub_457380((int)&ppvOut, v0, &dword_7655AC, &flt_7655B0, &flt_7655B4, &v2, &flt_7655B8, &v1);
  }
}
