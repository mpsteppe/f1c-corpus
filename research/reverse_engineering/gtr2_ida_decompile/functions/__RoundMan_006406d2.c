int __cdecl _RoundMan(int a1, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ebx
  int v6; // [esp+Ch] [ebp-4h]

  v6 = 0;
  v2 = a2 / 32;
  v3 = a1;
  if ( ((1 << (31 - a2 % 32)) & *(_DWORD *)(a1 + 4 * (a2 / 32))) != 0 )
  {
    if ( !_ZeroTail(a1, a2) )
      v6 = _IncMan(a1, a2 - 1);
    v3 = a1;
  }
  *(_DWORD *)(v3 + 4 * v2) &= -1 << (31 - a2 % 32);
  v4 = v2 + 1;
  if ( v4 < 3 )
    memset((void *)(v3 + 4 * v4), 0, 4 * (3 - v4));
  return v6;
}
