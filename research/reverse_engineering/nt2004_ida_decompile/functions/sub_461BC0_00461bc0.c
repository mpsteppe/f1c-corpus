void __thiscall sub_461BC0(_DWORD *this, int ArgList)
{
  int v3; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // eax
  char v8; // [esp+0h] [ebp-80h]
  _BYTE v9[100]; // [esp+Ch] [ebp-74h] BYREF
  char v10; // [esp+70h] [ebp-10h]
  char v11; // [esp+71h] [ebp-Fh]

  sub_462BC0(v9);
  sub_463C50(v9);
  sub_462C30(2, 1);
  sub_462C30(4, 0);
  if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 4986) )
    sub_500FE0((int)&unk_7D7920, aNetcommSetself, v8);
  v3 = this[1680];
  v11 = dword_769824;
  if ( v3 == 2 || v3 == 1 )
  {
    if ( v10 == -1 )
    {
      v4 = sub_45FDD0(this);
      v5 = this[1677];
      v6 = v4;
      v10 = v4;
      v7 = sub_56A540(v5);
      sub_45FDF0(this, v6, v7);
      if ( dword_75CBA8 != 5 )
      {
        if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 5000) )
          sub_500FE0((int)&unk_7D7920, aNetcommSetself_0, v6);
      }
    }
    sub_462C30(1, 1);
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 5004) )
      sub_500FE0((int)&unk_7D7920, aNetcommSetself_2, v8);
  }
  else if ( ArgList == -1 )
  {
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 5022) )
      sub_500FE0((int)&unk_7D7920, aNetcommSetself_1, v8);
  }
  else
  {
    v10 = ArgList;
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 5015) )
      sub_500FE0((int)&unk_7D7920, aNetcommSetself_0, ArgList);
  }
  sub_463C20(v9);
  nullsub_6(v9);
}
