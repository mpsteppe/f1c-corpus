int __thiscall sub_494E20(_DWORD **this)
{
  const char *v2; // ecx
  const char *v3; // eax
  int result; // eax
  char *v5; // eax
  int v6; // [esp+0h] [ebp-8h]

  v2 = dword_B6F68C;
  if ( !dword_B6F68C )
    v2 = WindowName;
  v3 = &v2[strlen(v2)];
  if ( v3 > v2 )
  {
    while ( *v3 != 92 )
    {
      if ( --v3 <= v2 )
        goto LABEL_8;
    }
    ++v3;
  }
LABEL_8:
  CGarageOnline::GetFileList((CGarageOnline *)dword_B6CBB8, v3);
  result = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 54);
  if ( result )
  {
    sub_4D0AC0(v6);
    v5 = sub_41D840(&byte_91CC38, "Reading Folder...");
    return sub_4D93B0(v5, 0, 0, 0, 0, 0, -1, -1, -1, -1);
  }
  return result;
}
