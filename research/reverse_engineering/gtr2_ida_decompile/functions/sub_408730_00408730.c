char __thiscall sub_408730(_DWORD *this, double a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  float v8; // [esp+18h] [ebp-4h]

  v3 = (_DWORD *)this[2];
  v4 = (_DWORD *)*v3;
  if ( (_DWORD *)*v3 != v3 )
  {
    do
    {
      v8 = a2;
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v4[2] + 4))(v4[2], LODWORD(v8));
      v4 = (_DWORD *)*v4;
    }
    while ( v4 != (_DWORD *)this[2] );
  }
  v5 = (_DWORD *)this[5];
  v6 = (_DWORD *)*v5;
  if ( (_DWORD *)*v5 != v5 )
  {
    do
    {
      LOBYTE(v5) = sub_405990((_BYTE *)v6[2], a2);
      v6 = (_DWORD *)*v6;
    }
    while ( v6 != (_DWORD *)this[5] );
  }
  return (char)v5;
}
