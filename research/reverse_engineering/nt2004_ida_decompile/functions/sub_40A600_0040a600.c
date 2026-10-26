int __thiscall sub_40A600(int this)
{
  int v2; // ecx
  const char *v3; // eax
  const char *v4; // eax

  v2 = *(_DWORD *)(this + 16);
  if ( v2 )
  {
    v3 = (const char *)sub_459B80(v2);
    if ( !_strcmpi(v3, aNosecam) || *(_BYTE *)(this + 52) )
      return 3;
    v4 = (const char *)sub_459B80(*(_DWORD *)(this + 16));
    if ( !_strcmpi(v4, aCockpit) )
      return 1;
  }
  return 0;
}
