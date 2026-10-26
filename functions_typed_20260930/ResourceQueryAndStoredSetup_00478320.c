int __thiscall ResourceQueryAndStoredSetup(_DWORD *this)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 18);
  if ( v2 )
  {
    this[56] = v2;
    ProfileIconPathSetter(this);
  }
  return 0;
}

