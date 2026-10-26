int __thiscall sub_50AF50(_DWORD *this, int *a2)
{
  int result; // eax

  result = *a2;
  if ( *a2 )
  {
    if ( *((_BYTE *)a2 + 64) )
    {
      sub_59E730(*a2);
      *((_BYTE *)a2 + 64) = 0;
      sub_59ECC0(1, 1, 1, 0);
      sub_59E090(0.0, -3.4028235e38, 0.0);
      return sub_50B4E0(this[717], 1);
    }
  }
  return result;
}
