int __thiscall sub_6CC56A(int this)
{
  unsigned int v2; // esi
  int result; // eax
  int i; // [esp+Ch] [ebp-8h]
  int v5; // [esp+10h] [ebp-4h]

  v2 = **(_DWORD **)(this + 256) & 0xFFFFF;
  v5 = 0;
  if ( !v2 )
    return 0;
  for ( i = 4 * v2; ; i += 4 )
  {
    result = sub_6CB29C(
               (_DWORD *)this,
               32,
               (_DWORD *)(4 * v5 + *(_DWORD *)(*(_DWORD *)(this + 256) + 16)),
               1,
               (_DWORD *)(4 * v5 + *(_DWORD *)(*(_DWORD *)(this + 256) + 8)),
               (_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 256) + 8) + i),
               0,
               v2,
               0,
               0,
               0,
               0);
    if ( result < 0 )
      break;
    if ( ++v5 >= v2 )
      return 0;
  }
  return result;
}
