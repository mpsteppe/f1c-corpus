void __thiscall sub_419190(_DWORD *this, float a2)
{
  int v2; // ecx

  v2 = this[3];
  if ( v2 && a2 >= 0.0 && a2 <= 1.0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 32))(v2, LODWORD(a2));
}
