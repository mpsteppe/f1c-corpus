int __thiscall sub_4DAC90(_DWORD *this)
{
  _DWORD *v2; // edi
  int v3; // eax

  v2 = this + 23;
  if ( !(*(int (__thiscall **)(_DWORD *, char *, int))(this[23] + 36))(this + 23, byte_75AF70, 512) )
    return 0;
  while ( 1 )
  {
    ++this[188];
    v3 = sub_612EB0(&unk_75AD58);
    if ( v3 != 1 && (v3 <= 2 || v3 > 4) )
      break;
    ++this[189];
    if ( !(*(int (__thiscall **)(_DWORD *, char *, int))(*v2 + 36))(v2, byte_75AF70, 512) )
      return 0;
  }
  return 1;
}
