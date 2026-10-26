char __thiscall sub_40C420(int *this, char a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // ecx
  const char *v5; // eax
  int v6; // ecx

  v6 = *this;
  LOBYTE(v2) = a2;
  v3 = v6;
  if ( a2 )
  {
    *(_DWORD *)(v6 + 24) = 2;
  }
  else
  {
    v4 = *(_DWORD *)(v6 + 16);
    *(_DWORD *)(v3 + 24) = v4 && (v5 = (const char *)sub_459BA0(v4), (v2 = _strcmpi(v5, aTrackside)) == 0);
  }
  return v2;
}
