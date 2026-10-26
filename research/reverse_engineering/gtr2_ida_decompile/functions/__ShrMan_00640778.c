int __cdecl _ShrMan(int a1, int a2)
{
  int v2; // edx
  int v3; // eax
  int result; // eax
  _DWORD *v5; // ecx
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]
  int v9; // [esp+24h] [ebp+Ch]

  v2 = a2 % 32;
  v7 = a2 / 32;
  v3 = 0;
  v9 = 32 - a2 % 32;
  v8 = 0;
  do
  {
    v6 = ~(-1 << v2) & *(_DWORD *)(a1 + 4 * v3);
    *(_DWORD *)(a1 + 4 * v3) = v8 | (*(_DWORD *)(a1 + 4 * v3) >> v2);
    ++v3;
    v8 = v6 << v9;
  }
  while ( v3 < 3 );
  result = 2;
  v5 = (_DWORD *)(a1 + 4 * (2 - v7));
  do
  {
    if ( result < v7 )
      *(_DWORD *)(a1 + 4 * result) = 0;
    else
      *(_DWORD *)(a1 + 4 * result) = *v5;
    --result;
    --v5;
  }
  while ( result >= 0 );
  return result;
}
