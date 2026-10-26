int __thiscall sub_4E29B0(_DWORD *this, int a2)
{
  int v2; // ecx
  int v3; // eax
  int result; // eax

  v2 = this[2];
  v3 = 0;
  if ( a2 <= 0 )
  {
LABEL_4:
    if ( v2 )
      v2 = *(_DWORD *)(v2 + 36);
  }
  else
  {
    while ( v2 )
    {
      v2 = *(_DWORD *)(v2 + 32);
      if ( ++v3 >= a2 )
        goto LABEL_4;
    }
  }
  for ( result = 0; v2; ++result )
    v2 = *(_DWORD *)(v2 + 36);
  return result;
}
