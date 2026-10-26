// f1c  0x00418970  size=60
void __thiscall sub_418970(_DWORD *this, float a2)
{
  int v2; // ecx

  v2 = this[701];
  if ( v2 && a2 >= 0.0 && a2 <= 1.0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 28))(v2, LODWORD(a2));
}
