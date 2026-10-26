char __thiscall sub_48E050(int this)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  if ( *(_DWORD *)(this + 296) )
    return 0;
  if ( !*(_DWORD *)(this + 268) )
    return 0;
  if ( *(float *)(this + 288) > 0.0 )
    return 0;
  if ( sub_4CF920() <= 0 )
    return 0;
  v1 = sub_4CF930(0);
  if ( !v1 )
    return 0;
  v2 = sub_4E3120(v1);
  if ( !v2 )
    return 0;
  v3 = sub_4E3DF0(v2);
  if ( !v3 )
    return 0;
  sub_5F4F10(v3, 1, 0, 0, 32);
  return 1;
}
