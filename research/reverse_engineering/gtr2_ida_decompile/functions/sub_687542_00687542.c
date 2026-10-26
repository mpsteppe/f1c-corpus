unsigned int __thiscall sub_687542(_DWORD *this, int a2, unsigned int a3)
{
  unsigned int result; // eax
  _DWORD *v6; // esi

  for ( result = a3; result; result = v6[21] )
  {
    if ( a2 != -1 && *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a2) + 56) != -1 )
      a2 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * a2) + 56);
    v6 = *(_DWORD **)(this[5] + 4 * a2);
    if ( v6[21] < result )
      v6[21] = result;
    result = v6[2];
    if ( result != -1 )
      result = sub_687542(result, v6[21]);
    a2 = v6[5];
    if ( a2 == -1 )
      break;
  }
  return result;
}
