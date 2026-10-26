void __thiscall sub_5EE130(void *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  unsigned int v6; // eax

  v2 = *((_DWORD *)this + 1);
  if ( v2 == 2 || v2 == 1 )
  {
    if ( *((_DWORD *)this + 11) )
      j__free(*((void **)this + 11));
    *((_DWORD *)this + 11) = 0;
  }
  v3 = *((_DWORD *)this + 8);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 12);
    if ( v4 <= 0 || (v5 = v4 - 1, (*(_DWORD *)(v3 + 12) = v5) == 0) )
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 408))(
        dword_FB27A4,
        *((_DWORD *)this + 8),
        0);
  }
  v6 = *(_DWORD *)this & 0xFFFFFFCF | 0x20;
  *((_DWORD *)this + 8) = 0;
  *(_DWORD *)this = v6;
  nullsub_7(this);
}
