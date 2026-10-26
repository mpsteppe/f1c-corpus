char __thiscall sub_408A50(_DWORD *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi

  v2 = (_DWORD *)this[2];
  v3 = (_DWORD *)*v2;
  if ( (_DWORD *)*v2 != v2 )
  {
    do
    {
      (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v3[2] + 12))(v3[2]);
      v3 = (_DWORD *)*v3;
    }
    while ( v3 != (_DWORD *)this[2] );
  }
  return sub_408730(this, 0.0);
}
