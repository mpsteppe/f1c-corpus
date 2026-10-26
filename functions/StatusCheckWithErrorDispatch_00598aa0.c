char *__thiscall sub_598AA0(char *this)
{
  int v2; // edi
  char *v3; // eax
  char *v4; // ecx
  int v5; // eax

  v2 = 0;
  v3 = &this[*(_DWORD *)(*(_DWORD *)this + 4)];
  if ( (v3[4] & 6) == 0 && (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v3 + 10) + 44))(*((_DWORD *)v3 + 10)) == -1 )
    v2 = 4;
  v4 = &this[*(_DWORD *)(*(_DWORD *)this + 4)];
  if ( v2 )
  {
    v5 = v2 | *((_DWORD *)v4 + 1);
    if ( !*((_DWORD *)v4 + 10) )
      LOBYTE(v5) = v5 | 4;
    sub_59A5FE(v5, 0);
  }
  return this;
}
