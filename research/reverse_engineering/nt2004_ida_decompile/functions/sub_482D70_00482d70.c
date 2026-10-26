int __thiscall sub_482D70(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // ecx
  bool v5; // cc
  int result; // eax

  sub_46FBE0(this);
  v2 = this[217];
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 != 1 )
        goto LABEL_15;
      v4 = dword_767A30;
      dword_767A24 = 2;
      if ( dword_767A2C > 2 )
      {
        dword_767A24 = dword_767A2C;
        goto LABEL_15;
      }
      v5 = dword_767A30 < 2;
    }
    else
    {
      v4 = dword_767A30;
      dword_767A24 = 1;
      if ( dword_767A2C > 1 )
      {
        dword_767A24 = dword_767A2C;
        goto LABEL_15;
      }
      v5 = dword_767A30 < 1;
    }
  }
  else
  {
    v4 = dword_767A30;
    dword_767A24 = 0;
    if ( dword_767A2C > 0 )
    {
      dword_767A24 = dword_767A2C;
      goto LABEL_15;
    }
    v5 = dword_767A30 < 0;
  }
  if ( v5 )
    dword_767A24 = v4;
LABEL_15:
  result = dword_76847C;
  dword_768474 = 0;
  if ( dword_76847C <= 0 )
  {
    if ( dword_768480 < 0 )
      dword_768474 = dword_768480;
  }
  else
  {
    dword_768474 = dword_76847C;
  }
  return result;
}
