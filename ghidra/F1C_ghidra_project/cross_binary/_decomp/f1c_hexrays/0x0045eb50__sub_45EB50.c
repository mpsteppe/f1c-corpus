// f1c  0x0045eb50  size=118
char *__thiscall sub_45EB50(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  _DWORD *v4; // esi

  v2 = this[3973];
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_5:
    if ( dword_7C569C != 5 )
    {
      if ( (unsigned __int8)sub_4D7A50(1, aDDevF119992002_1, 3094) )
        sub_4D7AA0(&unk_8AD25C, aCouldNotFindNa);
    }
    return asc_5C5DBC;
  }
  else
  {
    v4 = this + 3869;
    while ( *v4 != a2 )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    return (char *)&this[35 * v3 + 230];
  }
}
