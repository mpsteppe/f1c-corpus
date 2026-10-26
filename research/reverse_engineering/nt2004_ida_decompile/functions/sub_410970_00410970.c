char __stdcall sub_410970(char *String1, char *Destination, unsigned __int16 a3)
{
  int v3; // eax
  size_t v4; // esi
  const char *v5; // eax

  (**(void (__thiscall ***)(int))dword_76BB24)(dword_76BB24);
  if ( !sub_57AE50(aCareermessages) )
    return 0;
  v3 = sub_57A720(String1);
  if ( !v3 )
    return 0;
  v4 = a3 - 1;
  v5 = (const char *)sub_57A6D0(v3);
  strncpy(Destination, v5, v4);
  Destination[v4] = 0;
  return 1;
}
