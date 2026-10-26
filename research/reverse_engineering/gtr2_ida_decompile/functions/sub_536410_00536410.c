char __thiscall sub_536410(_DWORD *this)
{
  char result; // al
  int v3; // edi
  float v4; // [esp+0h] [ebp-Ch]

  result = dword_757C1C;
  if ( (_BYTE)dword_757C1C && dword_BE1204 != 2 && *(_DWORD *)dword_B640C8 == 6 )
  {
    v3 = *(_DWORD *)(dword_91E084 + 19316);
    ++this[10];
    ++this[dword_B72338 + 47];
    sub_535080((int)this, v3);
    if ( dword_B72B68 > 0 )
    {
      v4 = (float)dword_B71FD8;
      sub_535250((int)this, v4);
    }
    sub_5351B0((int)this, flt_B728A4);
    result = dword_B72314[0];
    if ( (*(_DWORD *)dword_B72314 == 4 || *(_DWORD *)dword_B72314 == 3) && v3 == 1 )
    {
      ++this[15];
      result = dword_B72338;
      ++this[dword_B72338 + 62];
    }
  }
  return result;
}
