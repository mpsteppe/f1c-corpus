int __thiscall sub_4E3BE0(_DWORD *this, int a2)
{
  int result; // eax
  int v4; // ebx
  int v5; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // edx
  int v9; // edx
  bool v10; // zf

  if ( dword_7685D0 == 5 )
  {
    result = *(_DWORD *)(25304 * this[157] + dword_76BB88 + 20884) - 1;
    v10 = *(_DWORD *)(25304 * this[157] + dword_76BB88 + 20884) == 1;
    this[158] = result;
    if ( v10 )
      ++this[154];
  }
  else
  {
    result = dword_7685D0 - 7;
    if ( dword_7685D0 == 7 )
    {
      v4 = 0;
      this[a2 + 8] = *(_DWORD *)(25304 * this[157] + dword_76BB88 + 20892) == 1;
      this[a2 + 56] = *(_DWORD *)(25304 * this[157] + dword_76BB88 + 20884);
      if ( sub_57AE50(aSeasonscoringi) )
      {
        v5 = sub_57A700(this[a2 + 56] - 1);
        if ( v5 )
        {
          v6 = (const char *)sub_57A6D0(v5);
          v4 = atol(v6);
        }
      }
      if ( sub_4DEBD0((_DWORD *)(25304 * this[157] + dword_76BB88 + 20836)) )
        v4 += 5;
      if ( sub_4DEB90((_DWORD *)(25304 * this[157] + dword_76BB88 + 20836)) )
        v4 += 5;
      v7 = sub_4DEBD0((_DWORD *)(25304 * this[157] + dword_76BB88 + 20836));
      v8 = 25304 * this[157];
      this[155] += v7;
      this[156] += *(_DWORD *)(v8 + dword_76BB88 + 20848);
      this[a2 + 104] = v4;
      v9 = this[157];
      result = v4 + this[152];
      this[152] = result;
      this[158] = v9;
    }
  }
  return result;
}
