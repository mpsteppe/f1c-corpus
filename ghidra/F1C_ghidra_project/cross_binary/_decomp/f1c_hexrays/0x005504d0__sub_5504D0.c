// f1c  0x005504d0  size=205
int __thiscall sub_5504D0(_DWORD *this, int a2, int a3)
{
  int result; // eax
  int *v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax

  result = 0;
  if ( a3 < this[41] )
  {
    v4 = (int *)(this[42] + 148 * a3);
    if ( v4[18] <= 1 )
    {
      if ( v4[36] && dword_8B6AC4 )
      {
        sub_551DD0(*(_DWORD *)(v4[35] + 84), 0, 0, 32);
        *(_DWORD *)(*(_DWORD *)(v4[35] + 84) + 24) &= ~0x400u;
      }
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
