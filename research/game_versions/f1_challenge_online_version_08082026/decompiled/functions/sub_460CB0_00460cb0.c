char __thiscall sub_460CB0(_DWORD *this, char a2)
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

  this[3973] = 0;
  v3 = this + 3869;
  v4 = 104;
  do
  {
    v3[105] = -1;
    *v3++ = -1;
    --v4;
  }
  while ( v4 );
  sub_57A800(this[4078]);
  LOBYTE(v5) = a2;
  if ( a2 )
  {
    v5 = this[3973];
    if ( v5 < 104 )
    {
      v6 = (int)&this[35 * v5 + 229];
      v7 = 104 - v5;
      do
      {
        LOBYTE(v5) = sub_461480(v6);
        v6 += 140;
        --v7;
      }
      while ( v7 );
    }
  }
  if ( this[4081] != 3 )
  {
    v8 = 0;
    v9 = this + 117;
    do
    {
      if ( *v9 != -1 )
      {
        v10 = this[3973];
        v5 = 0;
        if ( v10 <= 0 )
        {
LABEL_14:
          if ( dword_7C569C != 5 )
          {
            LOBYTE(v5) = sub_4D7A50(1, aDDevF119992002_1, 4745);
            if ( (_BYTE)v5 )
              LOBYTE(v5) = sub_4D7AA0(&unk_8AD25C, aMarkingSlotDAs);
          }
          *v9 = -1;
        }
        else
        {
          v11 = this + 3869;
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
    while ( v8 < 104 );
  }
  return v5;
}
