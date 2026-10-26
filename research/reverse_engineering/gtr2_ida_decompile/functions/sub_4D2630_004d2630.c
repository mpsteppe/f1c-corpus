int __thiscall sub_4D2630(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int v6; // [esp-4h] [ebp-Ch]

  v2 = this[213] - 1;
  v3 = 2 * (a2 == 1) - 1 + this[217];
  this[217] = v3;
  *((_BYTE *)this + 872) = a2 == 1;
  if ( v3 < 0 )
    v3 = v2;
  this[217] = v3;
  v4 = *this;
  v6 = v3 > v2 ? 0 : v3;
  this[217] = v6;
  return (*(int (__stdcall **)(int, int))(v4 + 184))(a2, v6);
}
