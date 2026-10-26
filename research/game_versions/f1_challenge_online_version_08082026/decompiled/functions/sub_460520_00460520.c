int __thiscall sub_460520(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // eax
  _BYTE v9[124]; // [esp+Ch] [ebp-8Ch] BYREF
  char v10; // [esp+88h] [ebp-10h]
  char v11; // [esp+89h] [ebp-Fh]

  sub_461470(v9);
  sub_4623E0(v9);
  if ( this[4081] != 1 )
    sub_4614F0(2, 1);
  sub_4614F0(4, 0);
  if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 4394) )
    sub_4D7AA0(&unk_8AD25C, aNetcommSetself);
  v3 = this[4081];
  v11 = dword_7D0E50;
  if ( v3 == 2 || v3 == 1 )
  {
    if ( v10 == -1 )
    {
      v4 = sub_45E5B0(this);
      v5 = this[4078];
      v6 = v4;
      v10 = v4;
      v7 = sub_57A810(v5);
      sub_45E5D0(this, v6, v7);
      if ( dword_7C569C != 5 )
      {
        if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 4408) )
          sub_4D7AA0(&unk_8AD25C, aNetcommSetself_0);
      }
    }
    sub_4614F0(1, 1);
    if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 4412) )
      sub_4D7AA0(&unk_8AD25C, aNetcommSetself_2);
  }
  else if ( a2 == -1 )
  {
    if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 4430) )
      sub_4D7AA0(&unk_8AD25C, aNetcommSetself_1);
  }
  else
  {
    v10 = a2;
    if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 4423) )
      sub_4D7AA0(&unk_8AD25C, aNetcommSetself_0);
  }
  sub_4623B0(v9);
  return nullsub_3(v9);
}
