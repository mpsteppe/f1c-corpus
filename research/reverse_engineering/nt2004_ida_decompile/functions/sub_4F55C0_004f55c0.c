int __thiscall sub_4F55C0(_DWORD *this)
{
  double v2; // st7
  int result; // eax
  int i; // esi
  int v5; // ecx
  float v6; // [esp+8h] [ebp-4h]

  if ( dword_7D5DA4 == 2 )
  {
    v2 = sub_4D9E20(&dword_7D5DAC);
    result = this[27];
    for ( i = 0; i < result; ++i )
    {
      v5 = *(_DWORD *)(this[28] + 4 * i);
      v6 = v2;
      if ( v6 < (double)*(float *)(v5 + 8) )
      {
        sub_4F2B40(this, (_DWORD *)v5);
        --i;
      }
      result = this[27];
    }
  }
  return result;
}
