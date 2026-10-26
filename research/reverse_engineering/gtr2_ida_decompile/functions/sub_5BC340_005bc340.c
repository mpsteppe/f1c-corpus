void __thiscall sub_5BC340(_DWORD *this, double a2)
{
  int v3; // ebp
  int i; // esi
  int v5; // edi
  float v6; // [esp+0h] [ebp-14h]

  v3 = this[117];
  for ( i = 0; i < v3; ++i )
  {
    v5 = *(_DWORD *)(this[119] + 4 * i);
    if ( (unsigned __int8)sub_5BFC80(v5) )
    {
      v6 = a2;
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 4))(v5, LODWORD(v6));
    }
  }
}
