int __thiscall sub_597590(_DWORD *this, int a2)
{
  int v2; // esi
  int v3; // edx
  int result; // eax

  v2 = this[65];
  v3 = 0;
  if ( v2 )
  {
    while ( 1 )
    {
      result = *(_DWORD *)(v2 + 236);
      if ( result )
        break;
LABEL_5:
      v2 = *(_DWORD *)(v2 + 260);
      if ( !v2 )
        goto LABEL_6;
    }
    while ( a2 != v3 )
    {
      result = *(_DWORD *)(result + 76);
      ++v3;
      if ( !result )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_6:
    for ( result = this[67]; result; ++v3 )
    {
      if ( a2 == v3 )
        break;
      result = *(_DWORD *)(result + 76);
    }
  }
  return result;
}
