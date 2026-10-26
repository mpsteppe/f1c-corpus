int __thiscall sub_4909D0(_DWORD *this)
{
  char v1; // dl
  const char *v3; // esi
  const char *v4; // eax

  v1 = byte_7683D8;
  if ( *((_BYTE *)this + 416) != byte_7683D8 )
    goto LABEL_7;
  v3 = (const char *)this[105];
  if ( !v3 )
    v3 = &byte_629120;
  v4 = dword_76662C;
  if ( !dword_76662C )
    v4 = &byte_629120;
  if ( strcmp(v4, v3) )
  {
LABEL_7:
    *((_BYTE *)this + 416) = byte_7683D8;
    if ( v1 )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*this + 40))(this, 1);
      sub_490320(this);
      return 0;
    }
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 40))(this, 0);
  }
  return 0;
}
