int __thiscall sub_495BFE(_DWORD *this, char a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // edi
  int result; // eax

  v3 = this[5];
  v4 = this + 5;
  v5 = this[6];
  v6 = v3 + 1;
  *v4 = v6;
  if ( v5 < v6 )
  {
    v7 = v6 + 1;
    sub_4F14D0();
    v4[2] = sub_5A8CF0((void *)v4[2], 8 * v7, 2, 16, 2);
    v4[1] = v7;
  }
  result = sub_5C6B40(*v4 - 1, &a2);
  if ( a3 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)a3 + 4))(a3);
  return result;
}
