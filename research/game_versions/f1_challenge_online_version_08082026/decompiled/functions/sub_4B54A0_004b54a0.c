char __thiscall sub_4B54A0(_DWORD *this)
{
  int *v2; // eax
  int v3; // ecx
  int v4; // eax
  int *v5; // eax

  v2 = (int *)this[8];
  this[10] = v2;
  if ( !v2 )
    return 1;
  v3 = *v2;
  if ( !*v2 )
    return 1;
  while ( (unsigned __int8)sub_5001F0(v3) )
  {
    v4 = this[10];
    if ( v4 )
      this[10] = *(_DWORD *)(v4 + 4);
    v5 = (int *)this[10];
    if ( v5 )
    {
      v3 = *v5;
      if ( *v5 )
        continue;
    }
    return 1;
  }
  return 0;
}
