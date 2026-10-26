int __thiscall ConditionalRenderingCall(int this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  char *v6; // eax

  if ( !*(_DWORD *)(this + 236) )
    return 0;
  v6 = UIStringAccessor_62c0((_DWORD *)this);
  if ( v6 )
    sub_498560(*(char **)(this + 64), v6);
  return UILargeRenderDispatcher(this, a2, a3, a4, a5);
}
