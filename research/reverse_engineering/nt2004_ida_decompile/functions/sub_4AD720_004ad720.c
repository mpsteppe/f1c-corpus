int __thiscall sub_4AD720(_DWORD *this, char *String2, char a3)
{
  int v4; // eax

  if ( String2 && (v4 = sub_4AD490(this, String2)) != 0 )
    return sub_4AD5B0(this, v4, 1, a3);
  else
    return 0;
}
