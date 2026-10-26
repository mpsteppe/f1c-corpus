char __thiscall sub_462E20(void *this)
{
  int v2; // edi
  int v3; // esi
  char result; // al
  char v5; // [esp+Bh] [ebp-Dh]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]

  v5 = 0;
  v8 = sub_462300(this);
  v6 = 0;
  if ( *(char *)(*(_DWORD *)this + 16345) <= 0 )
    goto LABEL_17;
  v7 = 0;
  do
  {
    v2 = 0;
    v3 = 15896;
    while ( 1 )
    {
      if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 6774) )
        sub_4D7AA0(&unk_8AD25C, aComparingNodei);
      if ( *(_DWORD *)(v3 + *(_DWORD *)this) == *(_DWORD *)(v7 + *(_DWORD *)this + 16346) )
        break;
      v3 += 4;
      ++v2;
      if ( v3 >= 16312 )
        goto LABEL_15;
    }
    if ( v8 == *(_DWORD *)(*(_DWORD *)this + 4 * v2 + 15896) )
      v5 = 1;
    dword_5F0730[4656 * v2] = v6 + 1;
    if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 6783) )
      sub_4D7AA0(&unk_8AD25C, aSetSlotDToPlac);
LABEL_15:
    v7 += 4;
    ++v6;
  }
  while ( v6 < *(char *)(*(_DWORD *)this + 16345) );
  result = v5;
  if ( !v5 )
  {
LABEL_17:
    sub_4BC2F0(dword_5C329C);
    result = sub_4BC320(dword_7C54E8 + 16436);
    if ( dword_7C569C != 5 )
    {
      result = sub_4D7A50(1, aDDevF119992002_1, 6794);
      if ( result )
        return sub_4D7AA0(&unk_8AD25C, aCouldNotFindSe);
    }
  }
  return result;
}
