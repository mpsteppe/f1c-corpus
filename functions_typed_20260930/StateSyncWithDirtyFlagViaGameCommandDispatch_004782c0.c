int __thiscall StateSyncWithDirtyFlagViaGameCommandDispatch(int *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // edx

  v2 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 16);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 372);
    if ( this[58] != v3 )
    {
      v4 = *this;
      this[58] = v3;
      (*(void (__thiscall **)(int *, int))(v4 + 44))(this, 1);
    }
  }
  return 0;
}

