int __thiscall sub_48E6B0(_DWORD *this)
{
  const char *v2; // esi
  const char *v3; // eax
  char *v4; // eax

  sub_496750(this, 0);
  v2 = (const char *)this[56];
  if ( !v2 )
    v2 = byte_5EA438;
  v3 = (const char *)this[46];
  if ( !v3 )
    v3 = byte_5EA438;
  if ( strcmp(v3, v2) )
  {
    v4 = (char *)this[46];
    if ( !v4 )
      v4 = byte_5EA438;
    sub_566650(v4);
    (*(void (__thiscall **)(_DWORD *))(*this + 172))(this);
  }
  (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
  return 0;
}
