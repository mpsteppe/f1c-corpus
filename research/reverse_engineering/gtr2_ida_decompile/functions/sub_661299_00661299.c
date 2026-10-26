void __thiscall sub_661299(int this)
{
  int v2; // eax
  _DWORD *v3; // ecx

  v2 = *(_DWORD *)(this + 8);
  if ( v2 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
    *(_DWORD *)(this + 8) = 0;
  }
  j__free(*(void **)(this + 88));
  v3 = *(_DWORD **)(this + 120);
  if ( v3 )
    sub_660C49(v3, 1);
}
