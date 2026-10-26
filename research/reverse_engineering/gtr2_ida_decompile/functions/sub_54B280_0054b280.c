int __thiscall sub_54B280(_DWORD *this, int a2)
{
  int v3; // ecx
  int result; // eax

  v3 = this[1];
  if ( v3 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 12))(v3, a2);
  result = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)a2 + 4))(a2, this[1]);
  this[1] = a2;
  return result;
}
