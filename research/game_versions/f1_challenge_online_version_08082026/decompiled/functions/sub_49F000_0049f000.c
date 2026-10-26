int __thiscall sub_49F000(int this)
{
  int result; // eax
  _DWORD *v3; // esi
  int v4; // edi

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_16, 2635) )
    sub_4D7AA0(&unk_8AD25C, aEnteredOnscree_2);
  sub_45BDF0(&dword_7CD204);
  sub_49F150(0);
  *(_DWORD *)(this + 4) = 1;
  *(_BYTE *)(this + 8) = 0;
  result = sub_45BDF0(&dword_7CD204);
  v3 = &unk_8AD2A8;
  v4 = 25;
  do
  {
    if ( *v3 )
      result = sub_4D7E30();
    ++v3;
    --v4;
  }
  while ( v4 );
  return result;
}
