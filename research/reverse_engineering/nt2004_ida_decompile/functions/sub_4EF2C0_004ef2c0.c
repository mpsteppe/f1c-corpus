BOOL __thiscall sub_4EF2C0(_BYTE *this)
{
  sub_4EF370(this);
  if ( *this )
  {
    dword_7D6BB0 = (int)sub_4EEE20((void *)1);
    return dword_7D6BB0 == 0;
  }
  else
  {
    dword_7D6BB0 = 0;
    return 1;
  }
}
