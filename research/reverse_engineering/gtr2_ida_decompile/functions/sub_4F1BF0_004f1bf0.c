char __thiscall sub_4F1BF0(void *this, char a2)
{
  int v4; // eax
  int v5; // ebp
  int v6; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // ebp
  int v13; // esi
  int v14; // eax
  int v15; // esi
  char v16; // al

  if ( (*((_BYTE *)this + 12) & 0x10) != 0 )
    return 0;
  v4 = *((_DWORD *)this + 72);
  if ( !a2 )
  {
    v11 = 0;
    if ( v4 > 0 )
    {
      v12 = 0;
      do
      {
        v13 = *((_DWORD *)this + 73);
        v14 = *(_DWORD *)(v13 + v12 + 80);
        v15 = v12 + v13;
        if ( v14 != -1 && *(_DWORD *)(v15 + 136) )
        {
          v16 = *(_BYTE *)(v15 + 10);
          if ( *(_BYTE *)(v15 + 13) )
          {
            if ( v16 )
            {
              sub_5DB5A0();
              if ( *(_DWORD *)(*(_DWORD *)this + 14820) )
                *(_DWORD *)(252 * *(_DWORD *)(v15 + 80) + *(_DWORD *)this + 16200) = 0;
              else
                *((double *)&unk_B663B8 + 160 * *(_DWORD *)(v15 + 80)) = 0.0;
            }
          }
          else if ( !v16 )
          {
            sub_5DB5A0();
          }
        }
        ++v11;
        v12 += 768;
      }
      while ( v11 < *((_DWORD *)this + 72) );
    }
    return 1;
  }
  v5 = 0;
  if ( v4 <= 0 )
    return 1;
  v6 = 0;
  do
  {
    v7 = *((_DWORD *)this + 73);
    v8 = *(_DWORD *)(v7 + v6 + 80);
    v9 = v6 + v7;
    if ( v8 != -1 )
    {
      v10 = *(_DWORD *)(v9 + 136);
      if ( v10 )
        sub_5DB590(v10);
    }
    ++v5;
    v6 += 768;
  }
  while ( v5 < *((_DWORD *)this + 72) );
  return 1;
}
