int __thiscall sub_479AC0(char *this, int a2, int ArgList)
{
  char *v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // ebp
  int v7; // eax
  int v8; // edx
  _DWORD *v9; // ecx
  int i; // edi
  int v12; // [esp+Ch] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-18h]
  char v14; // [esp+14h] [ebp-14h]
  char v15; // [esp+24h] [ebp-4h]

  v4 = &this[56 * ArgList + 302768];
  *((_DWORD *)v4 + 2) = 0;
  *((_DWORD *)v4 + 3) = 0;
  *((_DWORD *)v4 + 4) = 0;
  *((_DWORD *)v4 + 5) = 0;
  *((_DWORD *)v4 + 6) = 0;
  *((_DWORD *)v4 + 7) = 0;
  *((_DWORD *)v4 + 8) = 0;
  *((_DWORD *)v4 + 9) = 0;
  *((_DWORD *)v4 + 10) = 0;
  *((_DWORD *)v4 + 11) = 0;
  *((_DWORD *)v4 + 12) = 0;
  *((_DWORD *)v4 + 13) = 0;
  v5 = (_DWORD *)((char *)&unk_9204A0 + 22616 * ArgList);
  *(_DWORD *)v4 = 1092616192;
  *((_DWORD *)v4 + 1) = 1087006310;
  sub_59A9C0(&this[1704 * ArgList + 113772]);
  sub_4797E0();
  v6 = *(_DWORD **)this;
  v7 = sub_59B580(*(_DWORD *)(**(_DWORD **)this + 113316));
  v8 = 0;
  v9 = (_DWORD *)(*v6 + 112888);
  while ( *v9 != v7 )
  {
    ++v8;
    ++v9;
    if ( v8 >= 104 )
    {
      v8 = -1;
      break;
    }
  }
  if ( ArgList == v8 )
  {
    if ( !v5[4845] || v5[3705] == -1 )
      sub_53E6A0(v5, 0);
    sub_42C8E0(ArgList);
    v15 = 1;
  }
  else
  {
    sub_53E6A0(v5, 2);
  }
  sub_52C360(ArgList + 1);
  sub_52C3C0(v5 + 4818);
  if ( dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4644) )
  {
    sub_561210((int)byte_FAE910, "*** LOADING Slot (index %d, \"%s\") @ et=%8.4f", ArgList);
  }
  ++dword_757C10;
  sub_42CC30(&unk_920488);
  sub_53F5D0(v5, 1, v15);
  sub_53E6F0(COERCE_FLOAT(1));
  sub_553020(&unk_FADD40, v12, v13);
  if ( !v5[3705] )
  {
    if ( dword_B640C0 != 5
      && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 4670) )
    {
      sub_561210((int)byte_FAE910, "*** Slot is tagged as player slot", v14);
    }
    for ( i = 0; i < dword_757C10; ++i )
      sub_56AE80(0, 1);
    sub_42C8A0(ArgList);
    sub_4EA410(&unk_B6E7A8);
    sub_413790(&dword_91BF20, v5);
  }
  return sub_438330(&dword_B66000, v5[5617]);
}
