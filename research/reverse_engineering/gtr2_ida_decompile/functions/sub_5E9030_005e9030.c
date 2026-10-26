int __thiscall sub_5E9030(_DWORD *this, int a2)
{
  int *v2; // edx
  int result; // eax
  int v4; // edx
  int v5; // edx
  int *v6; // edx

  v2 = (int *)this[9];
  result = 0;
  this[11] = v2;
  if ( !v2 )
    return -1;
  v4 = *v2;
  if ( !v4 )
    return -1;
  while ( v4 != a2 )
  {
    v5 = this[11];
    ++result;
    if ( v5 )
      this[11] = *(_DWORD *)(v5 + 4);
    v6 = (int *)this[11];
    if ( v6 )
    {
      v4 = *v6;
      if ( v4 )
        continue;
    }
    return -1;
  }
  return result;
}
