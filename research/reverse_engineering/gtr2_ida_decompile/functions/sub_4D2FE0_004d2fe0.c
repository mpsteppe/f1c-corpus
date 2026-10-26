int __thiscall sub_4D2FE0(_DWORD *this, int a2, int a3)
{
  int result; // eax

  result = this[13];
  if ( result )
  {
    if ( *(_DWORD *)(result + 244) )
      sub_4E29F0(*(_DWORD *)(result + 132));
    return sub_4E2AF0(a2, a3);
  }
  return result;
}
