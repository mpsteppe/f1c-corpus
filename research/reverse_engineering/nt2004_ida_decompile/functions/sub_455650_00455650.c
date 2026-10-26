int __thiscall sub_455650(_DWORD *this, _DWORD *a2, int a3)
{
  int result; // eax

  if ( !*a2 )
    return sub_454D90(this, a2[1], a3);
  result = *a2 - 1;
  if ( *a2 == 1 )
  {
    result = sub_4550C0(this, a2[1], a3 == 2);
    if ( result )
      return sub_454DC0(this, a2[1]);
  }
  return result;
}
