int __thiscall sub_60DBC0(_DWORD *this, int a2, char a3)
{
  if ( !a3 && (!*((_BYTE *)this + 4815) || (*(_DWORD *)a2 & 0x8000) == 0) )
    return 1;
  if ( !(*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD, _DWORD, int, int, int, _DWORD))(*this + 368))(
          this,
          this + 173,
          this[172],
          *(_DWORD *)(a2 + 8),
          (*(_BYTE *)a2 & 8) != 0 ? 0x8000 : 4096,
          a2 + 44,
          a2 + 52,
          0)
    && !(*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD, _DWORD, int, int, _DWORD))(*this + 372))(
          this,
          this + 183,
          this[182],
          *(_DWORD *)(a2 + 36),
          a2 + 48,
          a2 + 56,
          0) )
  {
    (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD))(*this + 388))(this, a2, 0, 0);
    sub_60B7E0(*(char **)(a2 + 44), 0);
    sub_60B9D0(*(unsigned int **)(a2 + 48));
    return 1;
  }
  return 0;
}
