int __thiscall sub_5BCD20(_DWORD *this, int a2, int a3)
{
  int result; // eax
  _DWORD *v4; // esi
  int (__thiscall ***v5)(_DWORD); // edi
  int v6; // ecx

  result = this[2];
  v4 = (_DWORD *)(result + 8 * a2);
  if ( v4 )
  {
    *v4 = &off_7296C4;
    v4[1] = 0;
    v5 = *(int (__thiscall ****)(_DWORD))(a3 + 4);
    if ( v5 )
      result = (**v5)(*(_DWORD *)(a3 + 4));
    v6 = v4[1];
    v4[1] = v5;
    if ( v6 )
      return (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(v6);
  }
  return result;
}
