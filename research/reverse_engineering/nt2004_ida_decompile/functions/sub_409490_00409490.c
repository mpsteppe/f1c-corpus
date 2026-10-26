char __thiscall sub_409490(_DWORD *this, int a2)
{
  _DWORD *v2; // esi
  signed int v3; // ecx
  int v5; // eax
  signed int v6; // ebp
  int v7; // edi
  int v8; // ebx
  int v9; // esi
  int v11; // eax
  int v13; // [esp+14h] [ebp-4h]
  int v14; // [esp+1Ch] [ebp+4h]

  v2 = this;
  if ( dword_75AAC4 )
    v13 = *(_DWORD *)(dword_75AAC4 + 25248);
  else
    v13 = -1;
  v3 = NumOfElements;
  if ( (int)NumOfElements <= 0 )
    return 0;
  if ( !dword_75AAC4 )
  {
    sub_42DB40(0);
LABEL_22:
    if ( sub_409430(v2[4]) )
      sub_40A1B0(aSwingman);
    if ( v2[4] && sub_459B90() == 2 )
      sub_459B30(v2[4]);
    if ( v13 >= 0 )
      sub_50B4E0(0, 1);
    if ( dword_75AAC4 )
      sub_50B4E0(0, 1);
    return 1;
  }
  if ( a2 == 2 )
  {
    sub_42DB40(dword_75AAC8);
    goto LABEL_22;
  }
  v5 = *(_DWORD *)(dword_75AAC4 + 20884);
  v6 = NumOfElements;
  v14 = v5;
  v7 = 2 * (a2 != 0) - 1;
  v8 = 0;
  v9 = v7 + v5;
  if ( (int)NumOfElements > 0 )
  {
    while ( 1 )
    {
      if ( v9 > 0 )
      {
        if ( v9 > v3 )
          v9 = 1;
      }
      else
      {
        v9 = v3;
      }
      if ( v9 == v5 )
        break;
      v11 = sub_409610(v9);
      if ( v11 && (*(_DWORD *)(v11 + 25296) & 2) != 0 )
      {
        sub_42DB60(*(_DWORD *)(v11 + 25248));
        v2 = this;
        goto LABEL_22;
      }
      v9 += v7;
      if ( ++v8 >= v6 )
        return 0;
      v3 = NumOfElements;
      v5 = v14;
    }
  }
  return 0;
}
