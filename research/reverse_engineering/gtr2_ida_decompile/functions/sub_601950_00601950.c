int __thiscall sub_601950(_DWORD *this)
{
  int v1; // edx
  int result; // eax
  int v3; // ecx

  v1 = this[162];
  result = -1;
  if ( v1 )
  {
    v3 = this[160];
    for ( result = 0; v3; ++result )
    {
      if ( v3 == v1 )
        break;
      v3 = *(_DWORD *)(v3 + 4);
    }
  }
  return result;
}
