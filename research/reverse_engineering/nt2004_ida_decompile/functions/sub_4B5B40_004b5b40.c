int __stdcall sub_4B5B40(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  float v6; // [esp+0h] [ebp-18h]
  int v7; // [esp+1Ch] [ebp+4h]

  if ( *(_BYTE *)(304 * a1 + dword_75AAC4 + 2296) )
  {
    if ( *(_DWORD *)(dword_75AAD0[dword_75AAC0] + 25248) == *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248) )
    {
      v7 = 157 * a1;
      v6 = dbl_75EF84[v7] - 273.16;
      sub_4B5B70(v6);
      return sub_4B5CCD(a2, v7, a2, a3, a4, a5);
    }
    else
    {
      return sub_59FFB0(a2, a3, a4, a5, -16711936);
    }
  }
  else
  {
    result = (int)(__int64)dbl_7DA9D0 % 2;
    if ( !result )
      return sub_59FFB0(a2, a3, a4, a5, -65536);
  }
  return result;
}
