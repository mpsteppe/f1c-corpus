int __thiscall sub_45BEA0(int this)
{
  if ( *(_DWORD *)(this + 60) )
  {
    AVIStreamRelease(*(PAVISTREAM *)(this + 60));
    *(_DWORD *)(this + 60) = 0;
  }
  if ( *(_DWORD *)(this + 64) )
  {
    AVIStreamRelease(*(PAVISTREAM *)(this + 64));
    *(_DWORD *)(this + 64) = 0;
  }
  if ( *(_DWORD *)(this + 56) )
  {
    AVIFileRelease(*(PAVIFILE *)(this + 56));
    *(_DWORD *)(this + 56) = 0;
  }
  return AVIPlayerCleanup();
}
