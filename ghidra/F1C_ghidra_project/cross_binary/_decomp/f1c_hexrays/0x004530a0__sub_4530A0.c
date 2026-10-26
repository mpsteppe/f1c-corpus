// f1c  0x004530a0  size=83
int __thiscall sub_4530A0(int *this, _DWORD *a2, int a3)
{
  int result; // eax

  if ( !*a2 )
    return sub_4527E0(this, a2[1], a3);
  result = *a2 - 1;
  if ( *a2 == 1 )
  {
    result = sub_452B10(this, a2[1], a3 == 2);
    if ( result )
      return sub_452810(this, a2[1]);
  }
  return result;
}
