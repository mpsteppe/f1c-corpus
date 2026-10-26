int __thiscall sub_64B306(_DWORD *this)
{
  return off_914340(
           *(_DWORD *)(this[1] + 32),
           *(_DWORD *)(*this + 32),
           *(_DWORD *)(*this + 104),
           *(_DWORD *)(*this + 108),
           *(_DWORD *)(*this + 96),
           *(_DWORD *)(this[1] + 96));
}
