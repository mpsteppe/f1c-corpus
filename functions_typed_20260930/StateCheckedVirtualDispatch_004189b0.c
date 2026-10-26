char __thiscall sub_4189B0(_DWORD *this, int a2)
{
  int v3; // ecx

  if ( this[699] != a2 )
    return 0;
  v3 = this[701];
  if ( !v3 || !(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(v3) )
    return 0;
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)this[701] + 12))(this[701]);
  return 1;
}

