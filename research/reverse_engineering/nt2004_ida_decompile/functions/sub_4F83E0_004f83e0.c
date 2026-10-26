int __thiscall sub_4F83E0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx

  result = sub_4F7CF0(this + 98, a2);
  if ( result < 0 )
  {
    result = sub_4F7CF0((_DWORD *)(v3 + 4), a2);
    if ( result < 0 )
      return 0;
  }
  return result;
}
