int __thiscall sub_4E5EE0(_DWORD *this)
{
  int result; // eax
  int v2; // esi
  int v3; // eax
  float v4; // ecx
  float v5; // [esp+4h] [ebp-4h]

  result = *(_DWORD *)(dword_75AACC + 20848);
  if ( result > 0 )
  {
    v5 = *(float *)(dword_75AACC + 20960);
    v2 = *(_DWORD *)(dword_75AACC + 20848);
    if ( v5 < 0.0 )
    {
      v5 = 0.0;
      v2 = result - 1;
    }
    v3 = dword_7D6B58 + 400 * dword_7D6B54;
    if ( v3 )
      v4 = COERCE_FLOAT(sub_4E5E20(this, (char *)(v3 + 4)));
    else
      v4 = v5;
    if ( v4 != 0.0 )
    {
      *(_DWORD *)(LODWORD(v4) + 16) += v2;
      if ( v5 > 0.0 && (*(float *)(LODWORD(v4) + 20) > (double)v5 || *(float *)(LODWORD(v4) + 20) <= 0.0) )
        *(float *)(LODWORD(v4) + 20) = v5;
    }
    return sub_4E6190(v2);
  }
  return result;
}
