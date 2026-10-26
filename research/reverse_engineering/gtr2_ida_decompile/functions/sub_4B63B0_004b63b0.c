int __thiscall sub_4B63B0(_DWORD *this)
{
  const char *v2; // eax
  const char *v3; // ecx
  const char *v4; // eax
  const CHAR *v5; // eax
  char v6; // al

  v2 = (const char *)this[92];
  if ( !v2 )
    v2 = WindowName;
  if ( !strlen(v2) )
    goto LABEL_9;
  v3 = dword_B6F68C;
  if ( !dword_B6F68C )
    v3 = WindowName;
  v4 = (const char *)this[92];
  if ( !v4 )
    v4 = WindowName;
  if ( _stricmp(v4, v3) )
  {
LABEL_9:
    v5 = dword_B6F68C;
    if ( !dword_B6F68C )
      v5 = WindowName;
    (*(void (__thiscall **)(_DWORD *, const CHAR *))(*this + 168))(this, v5);
  }
  if ( dword_B640C0 == 5 && *(_DWORD *)dword_B72314 == 5 )
  {
    if ( this[89] )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*this + 40))(this, 1);
      v6 = byte_B71D0A;
      byte_B71D08 = 1;
      if ( (unsigned __int8)byte_B71D0A > 1u || (v6 = byte_B71D0B) == 0 )
        byte_B71D08 = v6;
    }
  }
  sub_4A12E0();
  return 0;
}
