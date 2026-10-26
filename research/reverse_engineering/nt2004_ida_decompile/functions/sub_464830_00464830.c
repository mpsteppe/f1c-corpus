char __thiscall sub_464830(void *this)
{
  int v2; // edi
  int v3; // esi
  char result; // al
  char v5; // si
  char v6; // [esp+Bh] [ebp-Dh]
  int v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v6 = 0;
  v9 = sub_463B50(this);
  v7 = 0;
  if ( *(char *)(*(_DWORD *)this + 6741) <= 0 )
    goto LABEL_17;
  v8 = 0;
  do
  {
    v2 = 0;
    v3 = 6516;
    while ( 1 )
    {
      if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7541) )
        sub_500FE0((int)&unk_7D7920, aComparingNodei, v2);
      if ( *(_DWORD *)(v3 + *(_DWORD *)this) == *(_DWORD *)(v8 + *(_DWORD *)this + 6742) )
        break;
      v3 += 4;
      ++v2;
      if ( v3 >= 6708 )
        goto LABEL_15;
    }
    if ( v9 == *(_DWORD *)(*(_DWORD *)this + 4 * v2 + 6516) )
      v6 = 1;
    dword_6310F4[6326 * v2] = v7 + 1;
    if ( dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7550) )
      sub_500FE0((int)&unk_7D7920, aSetSlotDToPlac, v2);
LABEL_15:
    v8 += 4;
    ++v7;
  }
  while ( v7 < *(char *)(*(_DWORD *)this + 6741) );
  result = v6;
  if ( !v6 )
  {
LABEL_17:
    v5 = NumOfElements;
    sub_4DEB20(NumOfElements);
    result = sub_4DD140(dword_75AACC + 20836);
    if ( dword_75CBA8 != 5 )
    {
      result = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 7561);
      if ( result )
        return sub_500FE0((int)&unk_7D7920, aCouldNotFindSe, v5);
    }
  }
  return result;
}
