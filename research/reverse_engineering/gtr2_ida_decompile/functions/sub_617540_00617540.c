BOOL __thiscall sub_617540(int this, const char *a2)
{
  int v3; // esi
  int v5; // eax

  v3 = strlen(a2);
  if ( !*(_BYTE *)(this + 92) )
    return v3 == sub_613C90((_DWORD *)this, (int)a2, v3);
  v5 = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)(this + 96) + 20))(this + 96, a2, v3);
  return v3 == sub_613C90((_DWORD *)this, v5, v3);
}
