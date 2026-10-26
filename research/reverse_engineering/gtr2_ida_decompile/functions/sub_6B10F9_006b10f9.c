int __thiscall sub_6B10F9(void *this, int a2, int *a3, _DWORD *a4)
{
  int v5; // eax

  if ( (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 84))(this, *(_DWORD *)(a2 + 108)) == 0xFFFF )
  {
    *a4 = 0;
    v5 = (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 88))(this, *(_DWORD *)(a2 + 108));
  }
  else
  {
    *a4 = 1;
    v5 = *(_DWORD *)(a2 + 12);
  }
  *a3 = v5;
  return 0;
}
