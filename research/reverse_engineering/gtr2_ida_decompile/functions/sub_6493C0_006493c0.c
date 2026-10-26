int __thiscall sub_6493C0(int this)
{
  sub_64645D(this);
  if ( *(_DWORD *)(this + 20) )
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(this + 20) + 8))(*(_DWORD *)(this + 20));
  if ( *(_DWORD *)(this + 24) )
    j__free(*(void **)(this + 24));
  return sub_659B9C(this);
}
