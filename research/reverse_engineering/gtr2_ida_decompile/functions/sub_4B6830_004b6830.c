int __thiscall sub_4B6830(int this)
{
  const char *v1; // eax
  signed int v2; // eax
  int v3; // edx

  v1 = **(const char ***)(this + 268);
  if ( !v1 )
    v1 = WindowName;
  v2 = strlen(v1);
  v3 = *(_DWORD *)(this + 272);
  if ( v3 >= 0 )
  {
    if ( v3 > v2 )
      *(_DWORD *)(this + 272) = v2;
    *(_DWORD *)(this + 276) = *(_DWORD *)(this + 272);
  }
  else
  {
    *(_DWORD *)(this + 272) = 0;
    *(_DWORD *)(this + 276) = *(_DWORD *)(this + 272);
  }
  return sub_4B3150();
}
