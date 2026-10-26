int __thiscall sub_659D0D(int this)
{
  _DWORD *v2; // ecx
  void *v3; // edi

  v2 = *(_DWORD **)(this + 56);
  if ( v2 )
    sub_659CB7(v2, 1);
  v3 = *(void **)(this + 108);
  if ( v3 )
  {
    sub_659D0D(*(_DWORD *)(this + 108));
    j__free(v3);
  }
  if ( *(_DWORD *)(this + 88) && *(_DWORD *)(this + 100) )
    (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 88) + 4))(
      *(_DWORD *)(this + 88),
      *(_DWORD *)(this + 100));
  Concurrency::details::UMSFreeVirtualProcessorRoot::InitialThreadParam::~InitialThreadParam((HGDIOBJ *)(this + 76));
  sub_659B9C(this + 60);
  return nullsub_9(this);
}
