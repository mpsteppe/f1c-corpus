// f1c  0x0054e080  size=81
int __thiscall sub_54E080(_DWORD *this)
{
  int v2; // edi
  int result; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax

  v2 = 0;
  sub_545F40((_DWORD *)dword_8B8F28);
  result = this[72];
  if ( result > 0 )
  {
    v4 = 0;
    do
    {
      v5 = *(_DWORD *)(*(_DWORD *)(v4 + this[73] + 8) + 4);
      v6 = *(_DWORD *)(v5 + 156);
      if ( (v6 & 2) != 0 )
        *(_DWORD *)(v5 + 156) = v6 | 1;
      result = this[72];
      ++v2;
      v4 += 36;
    }
    while ( v2 < result );
  }
  return result;
}
