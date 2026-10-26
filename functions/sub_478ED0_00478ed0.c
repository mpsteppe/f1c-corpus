int __thiscall sub_478ED0(_DWORD *this)
{
  const char *v2; // eax
  char *v3; // ecx
  char *v4; // eax
  char *v5; // eax

  v2 = (const char *)this[87];
  if ( !v2 )
    v2 = byte_5EA438;
  if ( !strlen(v2) )
    goto LABEL_9;
  v3 = (char *)dword_7CE5D0;
  if ( !dword_7CE5D0 )
    v3 = byte_5EA438;
  v4 = (char *)this[87];
  if ( !v4 )
    v4 = byte_5EA438;
  if ( sub_588410(v4, v3) )
  {
LABEL_9:
    v5 = (char *)dword_7CE5D0;
    if ( !dword_7CE5D0 )
      v5 = byte_5EA438;
    (*(void (__thiscall **)(_DWORD *, char *))(*this + 176))(this, v5);
  }
  if ( dword_7C569C == 5 && dword_7D0410 == 5 && this[84] )
  {
    (*(void (__thiscall **)(_DWORD *, int))(*this + 60))(this, 1);
    byte_7CFF48 = 1;
  }
  HitTest(this);
  return 0;
}
