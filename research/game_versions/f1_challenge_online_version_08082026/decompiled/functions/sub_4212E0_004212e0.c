int __thiscall sub_4212E0(void *this)
{
  int v2; // edi
  int v4; // esi
  int v5; // eax
  int v6; // eax
  _BYTE v7[80]; // [esp+8h] [ebp-50h] BYREF

  v2 = 0;
  if ( !this )
    return 0;
  v4 = 0;
  v5 = sub_4C2850(&unk_7D2DB0);
  if ( sub_4C1370(v5) > 0 )
  {
    do
    {
      sub_4C2850(&unk_7D2DB0);
      sub_4C13A0(v4);
      sub_4C0A20(v7, 80);
      if ( sub_566810(v7, this) )
      {
        sub_4C2850(&unk_7D2DB0);
        v2 += *(_DWORD *)(sub_4C13A0(v4) + 416);
      }
      ++v4;
      v6 = sub_4C2850(&unk_7D2DB0);
    }
    while ( v4 < sub_4C1370(v6) );
  }
  return v2;
}
