int __thiscall sub_5A2870(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int *v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax

  result = 0;
  if ( a3 < this[43] )
  {
    v4 = (int *)(this[44] + 148 * a3);
    if ( v4[18] <= 1 )
    {
      if ( v4[36] && dword_7E5D5C )
        sub_5A8C40(*(_DWORD *)(v4[35] + 16), 0, 0, 128);
      return v4[35];
    }
    else if ( a2 == -1 )
    {
      return v4[35];
    }
    else
    {
      v5 = v4[20];
      if ( a2 < v5 )
      {
        v7 = v4[35];
        v8 = 96 * *(_DWORD *)(v4[19] + 4 * abs32(a2));
      }
      else
      {
        v6 = *(_DWORD *)(v4[19] + 4 * (abs32(a2) - v5));
        v7 = v4[35];
        v8 = 96 * v6;
      }
      return v7 + v8;
    }
  }
  return result;
}
