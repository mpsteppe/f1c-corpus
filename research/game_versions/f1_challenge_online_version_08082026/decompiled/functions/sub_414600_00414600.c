int __thiscall sub_414600(const char **this, char a2)
{
  const char *v3; // eax
  char v4; // bl
  const char *v5; // ecx
  const char *v6; // ecx
  const char *v7; // eax
  _BYTE v9[128]; // [esp+Ch] [ebp-100h] BYREF
  char v10[128]; // [esp+8Ch] [ebp-80h] BYREF

  v3 = *this;
  v4 = 0;
  if ( !*this )
    v3 = &byte_5EA438;
  v5 = (const char *)dword_5EC470;
  if ( !dword_5EC470 )
    v5 = &byte_5EA438;
  sub_58815F(v10, "%spws%s_", v5, v3);
  sub_58815F(v9, "%s%s", v10, aFb);
  if ( sub_414900(v9, this + 4) )
    sub_415D90(this + 4, this[2], 0, 1, 1);
  else
    v4 = 1;
  sub_58815F(v9, "%s%s", v10, aFe);
  if ( sub_414900(v9, this + 9) )
    sub_415D90(this + 9, this[2], 0, 1, 0);
  else
    v4 = 1;
  sub_58815F(v9, "%s%s", v10, aSb);
  if ( sub_414900(v9, this + 14) )
    sub_415D90(this + 14, this[2], 0, 0, 1);
  else
    v4 = 1;
  sub_58815F(v9, "%s%s", v10, aSe);
  if ( sub_414900(v9, this + 19) )
    sub_415D90(this + 19, this[2], 0, 0, 0);
  else
    v4 = 1;
  v6 = *this;
  if ( !*this )
    v6 = &byte_5EA438;
  v7 = (const char *)dword_5EC470;
  if ( !dword_5EC470 )
    v7 = &byte_5EA438;
  sub_58815F(v10, "%stv%s_", v7, v6);
  sub_58815F(v9, "%s%s", v10, aFb);
  if ( sub_414900(v9, this + 24) )
    sub_415D90(this + 24, this[2], 1, 1, 1);
  else
    v4 = 1;
  sub_58815F(v9, "%s%s", v10, aFe);
  if ( sub_414900(v9, this + 29) )
    sub_415D90(this + 29, this[2], 1, 1, 0);
  else
    v4 = 1;
  sub_58815F(v9, "%s%s", v10, aSb);
  if ( sub_414900(v9, this + 34) )
    sub_415D90(this + 34, this[2], 1, 0, 1);
  else
    v4 = 1;
  sub_58815F(v9, "%s%s", v10, aSe);
  if ( sub_414900(v9, this + 39) )
    sub_415D90(this + 39, this[2], 1, 0, 0);
  else
    v4 = 1;
  if ( !a2 || v4 )
    return 0;
  sub_4149A0(this);
  return 1;
}
