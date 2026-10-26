int __thiscall sub_54C230(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // edx

  result = this[129];
  v3 = 0;
  if ( !result )
    return 0;
  while ( v3 != a2 )
  {
    result = *(_DWORD *)(result + 16);
    ++v3;
    if ( !result )
      return 0;
  }
  return result;
}

