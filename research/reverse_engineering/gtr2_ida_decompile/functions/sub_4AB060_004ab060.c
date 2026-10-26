int __thiscall sub_4AB060(int this)
{
  const CHAR *v2; // eax
  const char *v3; // eax
  FILE *v4; // eax
  const CHAR *v6; // eax
  char *FileName; // [esp+8h] [ebp-94h]
  _BYTE v8[128]; // [esp+10h] [ebp-8Ch] BYREF
  int v9; // [esp+98h] [ebp-4h]

  if ( *(_DWORD *)(this + 276) != 849 )
  {
    byte_B6E08E = 0;
    return 0;
  }
  sub_6178E0(&byte_B6DEF0);
  sub_617930(128);
  FileName = (char *)operator new(0x80u);
  *FileName = 0;
  v2 = *(const CHAR **)dword_BE121C;
  v9 = 0;
  if ( !*(_DWORD *)dword_BE121C )
    v2 = WindowName;
  sub_615A50(v2);
  sub_615A50(v8);
  sub_615A50(&stru_6F59D0.ExceptionRecord);
  v3 = FileName;
  if ( !FileName )
    v3 = WindowName;
  v4 = fopen(v3, "rb");
  if ( !v4 || byte_B6E08E )
  {
    v6 = FileName;
    if ( !FileName )
      v6 = WindowName;
    sub_52A200(&unk_BE1210, v6);
    if ( (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 53) )
      sub_497320();
    byte_B6E08E = 0;
    if ( FileName )
    {
      j_j__free(FileName);
      return 0;
    }
    return 0;
  }
  fclose(v4);
  byte_B6E08E = 1;
  sub_4E1810("TIMETRIAL OVERWRITE CONFIRM", 0);
  if ( FileName )
    j_j__free(FileName);
  return -1;
}
