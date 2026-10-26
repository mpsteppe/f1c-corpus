int __thiscall sub_480370(void *this)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( v2 && *(_DWORD *)(v2 + 28) && dword_600F58 >= 0 )
  {
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
    return 0;
  }
}
