bool __thiscall sub_41F070(_DWORD *this)
{
  int v2; // edi
  int v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v2 = -1;
  if ( !this )
    return 0;
  v4 = 0;
  v5 = sub_4C2850(&unk_7D2DB0);
  if ( sub_4C1370(v5) > 0 )
  {
    do
    {
      sub_4C2850(&unk_7D2DB0);
      if ( this != (_DWORD *)sub_4C13A0(v4) )
      {
        sub_4C2850(&unk_7D2DB0);
        v6 = *(_DWORD *)(sub_4C13A0(v4) + 408);
        if ( v6 > v2 )
          v2 = v6;
      }
      ++v4;
      v7 = sub_4C2850(&unk_7D2DB0);
    }
    while ( v4 < sub_4C1370(v7) );
  }
  return this[102] - v2 >= 10;
}
