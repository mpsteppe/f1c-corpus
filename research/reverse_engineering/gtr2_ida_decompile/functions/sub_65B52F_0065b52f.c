int __thiscall sub_65B52F(_DWORD *this, char *a2)
{
  int v4; // ecx
  char v5; // [esp+0h] [ebp-10h]
  _DWORD *v6; // [esp+Ch] [ebp-4h] BYREF

  if ( !strcmp("__LINE__", a2) )
    return this[163];
  if ( sub_65B1A2(this, a2, &a2, &v6) )
  {
    if ( a2 )
    {
      sub_65DD1F(
        (int)(this + 6),
        (int)(this + 158),
        1517,
        "functional defines in preprocessor expressions not yet implemented",
        v5);
      return 1;
    }
    if ( v6 )
    {
      if ( !v6[3] )
      {
        v4 = v6[4];
        if ( v4 >= 2 && v4 <= 4 )
          return v6[6];
      }
    }
    sub_65DD1F((int)(this + 6), (int)(this + 158), 1518, "invalid or unsupported integer constant expression", v5);
  }
  return 0;
}
