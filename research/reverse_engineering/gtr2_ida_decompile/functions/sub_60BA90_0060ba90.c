int __thiscall sub_60BA90(char *this)
{
  int v2; // eax
  int v3; // ecx
  unsigned int v4; // eax
  int v5; // eax
  int v6; // eax

  if ( *((_DWORD *)this + 7) && (*(_DWORD *)this & 0x20000) == 0 )
  {
    while ( *((int *)this + 4) > 0 )
    {
      v2 = *((_DWORD *)this + 7);
      if ( v2 && *this < 0 && !(*(int (__stdcall **)(_DWORD))(*(_DWORD *)v2 + 48))(*((_DWORD *)this + 7)) )
      {
        v3 = *((_DWORD *)this + 4) - 1;
        v4 = *(_DWORD *)this & 0xFFFFFF7F;
        *((_DWORD *)this + 8) = 0;
        *((_DWORD *)this + 4) = v3;
        *(_DWORD *)this = v4;
      }
    }
    v5 = *((_DWORD *)this + 7);
    *((_DWORD *)this + 4) = 0;
    (*(void (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
    v6 = *(_DWORD *)this | 0x20000;
    *((_DWORD *)this + 7) = 0;
    *(_DWORD *)this = v6;
  }
  return 0;
}
