int __thiscall sub_4B5E70(int this, int a2)
{
  unsigned __int8 v3; // al
  char v4; // cl
  int v5; // eax
  const char *v6; // eax
  char *v7; // eax

  **(_BYTE **)(this + 844) = **(_BYTE **)(this + 844) == 0;
  if ( *(_DWORD *)(this + 840) == 309 )
  {
    v3 = **(_BYTE **)(this + 844);
    v4 = byte_B729EA;
    byte_B729E8 = **(_BYTE **)(this + 844);
    if ( (unsigned __int8)byte_B729E8 < (unsigned __int8)byte_B729EA
      || (v4 = byte_B729EB, v3 > (unsigned __int8)byte_B729EB) )
    {
      byte_B729E8 = v4;
    }
  }
  if ( *(_DWORD *)(this + 840) == 308 )
  {
    v5 = dword_B71D88;
    dword_B71D80 = 0;
    if ( dword_B71D88 > 0 || (v5 = dword_B71D8C, dword_B71D8C < 0) )
      dword_B71D80 = v5;
  }
  v6 = (const char *)sub_4CFC00(**(unsigned __int8 **)(this + 844));
  v7 = sub_41D840(&byte_91CC38, v6);
  return sub_4CE770(v7);
}
