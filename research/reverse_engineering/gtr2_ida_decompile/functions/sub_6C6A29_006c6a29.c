void __thiscall sub_6C6A29(int this)
{
  int v2; // eax
  void *v3; // [esp-4h] [ebp-Ch]

  v3 = *(void **)(this + 268);
  *(_DWORD *)this = &off_7477F0;
  j__free(v3);
  j__free(*(void **)(this + 292));
  v2 = *(_DWORD *)(this + 432);
  if ( v2 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 8))(*(_DWORD *)(this + 432));
    *(_DWORD *)(this + 432) = 0;
  }
  sub_660713((_DWORD *)(this + 468));
  sub_660713((_DWORD *)(this + 436));
  sub_682431((_DWORD *)this);
}
