char __thiscall sub_474920(void *this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // esi
  bool v5; // zf
  char result; // al
  char v7; // [esp+0h] [ebp-18h]
  char v8; // [esp+Fh] [ebp-9h]
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v8 = 0;
  v10 = sub_59B580(*(_DWORD *)(*(_DWORD *)this + 113316));
  v2 = 0;
  if ( *(char *)(*(_DWORD *)this + 113349) <= 0 )
    goto LABEL_25;
  v9 = 0;
  do
  {
    v3 = 0;
    v4 = 112888;
    while ( 1 )
    {
      if ( dword_B640C0 != 5
        && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 7615) )
      {
        sub_561210((int)byte_FAE910, "       comparing NODEIDs (nodemap[%d]=%d,pos[%d]=%d)", v3);
      }
      if ( *(_DWORD *)(v4 + *(_DWORD *)this) == *(_DWORD *)(v9 + *(_DWORD *)this + 113350) )
        break;
      v4 += 4;
      ++v3;
      if ( v4 >= 113304 )
        goto LABEL_15;
    }
    if ( v10 == *(_DWORD *)(*(_DWORD *)this + 4 * v3 + 112888) )
      v8 = 1;
    v5 = dword_B640C0 == 5;
    dword_925014[5654 * v3] = v2 + 1;
    if ( !v5
      && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 7624) )
    {
      sub_561210((int)byte_FAE910, "--Set slot %d to place %d %s", v3);
    }
LABEL_15:
    v9 += 4;
    ++v2;
  }
  while ( v2 < *(char *)(*(_DWORD *)this + 113349) );
  result = v8;
  if ( !v8 )
  {
LABEL_25:
    if ( dword_B640C0 != 5
      && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 7632) )
    {
      sub_561210((int)byte_FAE910, "Qualification not set by the server in latest SYNC. ", v7);
    }
    sub_52C360(-1);
    result = sub_52C3C0(dword_91E084 + 19272);
    if ( dword_B640C0 != 5 )
    {
      result = sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\netcomm.cpp", 7636);
      if ( result )
        return sub_561210(
                 (int)byte_FAE910,
                 "!!!!!  Could not find self in server's qualification view, setting at back + slotID (%d)",
                 -1);
    }
  }
  return result;
}
