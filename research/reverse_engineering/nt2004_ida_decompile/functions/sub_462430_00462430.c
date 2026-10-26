char __thiscall sub_462430(_DWORD *this, char a2)
{
  _DWORD *v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // esi
  int v8; // ebp
  _DWORD *v9; // edi
  int v10; // edx
  _DWORD *v11; // ecx

  this[1628] = 0;
  v3 = this + 1580;
  v4 = 48;
  do
  {
    v3[49] = -1;
    *v3++ = -1;
    --v4;
  }
  while ( v4 );
  sub_56A530(this[1677]);
  LOBYTE(v5) = a2;
  if ( a2 )
  {
    v5 = this[1628];
    if ( v5 < 48 )
    {
      v6 = (int)&this[29 * v5 + 188];
      v7 = 48 - v5;
      do
      {
        LOBYTE(v5) = sub_462BD0(v6);
        v6 += 116;
        --v7;
      }
      while ( v7 );
    }
  }
  if ( this[1680] != 3 )
  {
    v8 = 0;
    v9 = this + 111;
    do
    {
      if ( *v9 != -1 )
      {
        v10 = this[1628];
        v5 = 0;
        if ( v10 <= 0 )
        {
LABEL_14:
          if ( dword_75CBA8 != 5 )
          {
            LOBYTE(v5) = sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 5383);
            if ( (_BYTE)v5 )
              LOBYTE(v5) = sub_500FE0((int)&unk_7D7920, aMarkingSlotDAs, v8);
          }
          *v9 = -1;
        }
        else
        {
          v11 = this + 1580;
          while ( *v11 != *v9 )
          {
            ++v5;
            ++v11;
            if ( v5 >= v10 )
              goto LABEL_14;
          }
        }
      }
      ++v8;
      ++v9;
    }
    while ( v8 < 48 );
  }
  return v5;
}
