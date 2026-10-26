int __thiscall sub_592720(void *this, _DWORD *a2, char *a3)
{
  int result; // eax

  result = sub_5924D0(this, a2, a3);
  if ( !result )
  {
    if ( a2 )
      *(_DWORD *)(*a2 + 276) |= 8u;
  }
  return result;
}
