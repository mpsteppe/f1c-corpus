int __thiscall sub_464F50(int *this, int a2)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int result; // eax
  int v7; // ecx

  v2 = sub_464EE0(this);
  v4 = *(_DWORD *)(v3 + 58380);
  v5 = 1;
  if ( v4 > 1 )
    v5 = v4 - 1;
  result = v2 / v5;
  v7 = *(_DWORD *)(560 * a2 + v3 + 684);
  if ( v7 <= result )
    return v7;
  return result;
}
