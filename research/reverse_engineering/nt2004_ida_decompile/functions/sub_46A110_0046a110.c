char __thiscall sub_46A110(CHAR ****this)
{
  CHAR ***v2; // eax
  CHAR **v3; // eax
  CHAR ***v4; // eax
  bool v5; // zf
  CHAR *v7; // eax
  CHAR ***v8; // eax
  CHAR ***v9; // eax
  char *v10; // esi

  sub_4BA060(&byte_766124);
  v2 = this[2];
  if ( !v2 || (v3 = *v2) == 0 )
  {
    v4 = *this;
    v5 = *this == 0;
    this[2] = *this;
    if ( v5 )
      return 0;
    v3 = *v4;
    if ( !v3 )
      return 0;
  }
  v7 = *v3;
  if ( !v7 )
    v7 = &byte_629120;
  sub_4E8C80(v7);
  sub_4E8A30(&byte_7D6A30);
  v8 = this[2];
  if ( v8 )
    this[2] = (CHAR ***)v8[1];
  v9 = this[2];
  if ( !v9 || !*v9 )
    this[2] = *this;
  sub_464290(dword_764D70);
  if ( dword_75CBA8 == 5 )
  {
    sub_4302B0(&dword_75CBA8);
  }
  else
  {
    *(_DWORD *)dword_7689CC = 5;
    if ( dword_7689D4 <= 5 )
    {
      if ( dword_7689D8 < 5 )
        *(_DWORD *)dword_7689CC = dword_7689D8;
    }
    else
    {
      *(_DWORD *)dword_7689CC = dword_7689D4;
    }
    v10 = (char *)&unk_62BFBC;
    do
    {
      sub_51BC20(-1, 0);
      v10 += 25304;
    }
    while ( (int)v10 < (int)byte_75483C );
    NumOfElements = 0;
    sub_42DC40();
    byte_75AB9C = 1;
  }
  sub_4694C0((int)this);
  sub_42FDA0(&dword_75CBA8);
  sub_42FE80(&dword_75CBA8);
  sub_42FFB0(&dword_75CBA8);
  this[106] = 0;
  sub_57B690(this + 107);
  return 1;
}
