void __thiscall sub_5B8C10(void *this)
{
  int v2; // ebp
  int v3; // eax
  int v4; // edx
  int v5; // ebx
  int v6; // eax
  int i; // edi
  _DWORD *v8; // [esp-10h] [ebp-20h]

  v2 = **((_DWORD **)this + 4);
  if ( (*((_BYTE *)this + 40) & 4) == 0 )
  {
    v3 = *((_DWORD *)this + 7);
    v4 = *(_DWORD *)(v3 + 312);
    if ( (*(_BYTE *)(v4 + 60) & 2) == 0 )
    {
      if ( (*(_DWORD *)(v3 + 20) & 0x20000000) == 0 )
      {
        (*(void (__cdecl **)(int, int, int, int))(*(_DWORD *)dword_7E8E58 + 4))(
          dword_7E8E58,
          v3 + 220,
          v3 + 232,
          v4 + 276);
        *(_DWORD *)(*((_DWORD *)this + 7) + 20) |= 0x20000000u;
      }
      if ( *(float *)this <= sub_5AC8D0((unsigned int *)*((_DWORD *)this + 8)) )
      {
        sub_5AC740(*((int **)this + 8), 1);
        v5 = 0;
        **((_DWORD **)this + 9) = 0;
        v8 = (_DWORD *)*((_DWORD *)this + 3);
        *((_DWORD *)this + 1) = 0;
        v6 = sub_5A8020(dword_7E6B48, v8, 96, 0, 0);
        *((_DWORD *)this + 2) = v6;
        if ( v6 )
        {
          for ( i = 0; i < *(_DWORD *)(v2 + 328); v5 += 24 )
          {
            sub_5B8D00(*(_DWORD *)(*(_DWORD *)(v2 + 332) + v5 + 16));
            ++i;
          }
          sub_5A80B0(dword_7E6B48, *((_DWORD *)this + 3));
        }
      }
    }
  }
}
