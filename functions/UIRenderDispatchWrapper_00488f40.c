int __thiscall UIRenderDispatchWrapper(int this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // eax
  const char *v7; // eax

  v6 = *(_DWORD *)(this + 200);
  if ( v6 )
  {
    v7 = *(const char **)(v6 + 64);
    if ( !v7 )
      v7 = byte_5EA438;
    sub_498560(*(char **)(this + 64), v7);
  }
  return UILargeRenderDispatcher(this, a2, a3, a4, a5);
}
