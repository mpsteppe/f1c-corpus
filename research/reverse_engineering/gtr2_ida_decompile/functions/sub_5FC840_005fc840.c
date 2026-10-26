int __userpurge sub_5FC840@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4)
{
  int v6; // eax
  int v7; // eax
  char *v8; // ebp
  _WORD *v9; // edx
  const void *v10; // esi
  int v11; // esi
  int v12; // ecx
  __int16 v13; // cx
  int i; // eax
  char *retaddr; // [esp+40h] [ebp+0h]
  int v16; // [esp+44h] [ebp+4h]

  if ( (*a1 & 0x200000) == 0 )
  {
    if ( (*(int (__thiscall **)(int, int, _DWORD, int, int))(*(_DWORD *)dword_FB27A4 + 404))(
           dword_FB27A4,
           a1[16] + 44,
           *(_DWORD *)(a1[16] + 8),
           4096,
           14) )
    {
      return -1;
    }
    ++*(_DWORD *)(*(_DWORD *)(a1[16] + 44) + 12);
    if ( (*(int (__thiscall **)(int, int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 444))(
           dword_FB27A4,
           a1[16] + 48,
           *(_DWORD *)(a1[16] + 36),
           14) )
    {
      return -1;
    }
    ++*(_DWORD *)(*(_DWORD *)(a1[16] + 48) + 12);
    v6 = a1[16];
    *a1 |= 0x200000u;
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int, int, int))(*(_DWORD *)dword_FB27A4 + 412))(
      dword_FB27A4,
      *(_DWORD *)(v6 + 44),
      0,
      0,
      4096,
      a3,
      a2);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_FB27A4 + 452))(
      dword_FB27A4,
      *(_DWORD *)(a1[16] + 48),
      0,
      0);
    v7 = a1[16];
    v8 = *(char **)(*(_DWORD *)(v7 + 44) + 76);
    v9 = *(_WORD **)(*(_DWORD *)(v7 + 48) + 32);
    if ( v8 )
    {
      if ( v9 )
      {
        v16 = 0;
        if ( (int)a1[11] > 0 )
        {
          retaddr = 0;
          do
          {
            if ( (*a1 & 0x400) != 0 )
              v10 = *(const void **)&retaddr[a1[13] + 128];
            else
              v10 = (const void *)a1[20];
            qmemcpy(v8, v10, 4 * (a1[19] << 6 >> 2));
            v11 = v16;
            v12 = a1[19];
            v8 += 64 * v12;
            v13 = v16 * v12;
            for ( i = 0; i < a1[21]; ++i )
              *v9++ = v13 + *(_WORD *)(a1[22] + 2 * i);
            ++v16;
            retaddr += 132;
          }
          while ( v11 + 1 < a1[11] );
        }
      }
    }
    (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)dword_FB27A4 + 416))(
      dword_FB27A4,
      *(_DWORD *)(a1[16] + 44),
      4096);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)dword_FB27A4 + 456))(dword_FB27A4, *(_DWORD *)(a1[16] + 48));
  }
  return 0;
}
