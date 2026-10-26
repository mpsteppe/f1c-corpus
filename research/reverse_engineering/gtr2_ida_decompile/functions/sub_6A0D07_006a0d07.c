int __thiscall sub_6A0D07(int this, _DWORD *a2, unsigned int a3, int *a4, int a5)
{
  unsigned int v5; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  unsigned int v11; // ecx
  bool v12; // zf
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // edi
  unsigned int v16; // eax
  int v18; // [esp+Ch] [ebp-4h]

  v5 = 0;
  v18 = 0;
  if ( a5 )
  {
    v18 = 983040;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *a2) + 61) & 2) != 0 )
      v18 = 0x100000;
    if ( a3 )
    {
      do
      {
        v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * a2[v5]) + 16);
        v8 = 0;
        if ( v7 )
        {
          v9 = v7 - 1;
          if ( v9 )
          {
            v10 = v9 - 1;
            if ( v10 )
            {
              if ( v10 == 1 )
                v8 = 0x80000;
            }
            else
            {
              v8 = 0x40000;
            }
          }
          else
          {
            v8 = 0x20000;
          }
        }
        else
        {
          v8 = 0x10000;
        }
        if ( (v8 & v18) != 0 )
          sub_686791(this, *(_DWORD *)(*(_DWORD *)(this + 256) + 60), 4821, "internal error: overlapping output writes");
        v18 |= v8;
        ++v5;
      }
      while ( v5 < a3 );
    }
  }
  if ( (*(_BYTE *)(this + 112) & 0x40) == 0 )
  {
    if ( (*(_BYTE *)(this + 204) & 0x20) != 0 )
      goto LABEL_27;
    v11 = 0;
    v12 = a3 == 0;
    if ( a3 )
    {
      do
      {
        v13 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * a2[v11]);
        if ( (*(_BYTE *)(v13 + 3) & 2) == 0
          && ((*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(this + 16) + 4 * *(_DWORD *)(v13 + 4)) + 4) & 1) == 0
           || *(_DWORD *)(v13 + 72) == -1
           || *(_DWORD *)(v13 + 84) != -1) )
        {
          break;
        }
        ++v11;
      }
      while ( v11 < a3 );
      v12 = v11 == a3;
    }
    if ( v12 )
LABEL_27:
      BYTE2(v18) |= 0x20u;
  }
  if ( (*(_BYTE *)(this + 204) & 1) != 0 )
  {
    v14 = 0;
    if ( *(_DWORD *)(this + 292) )
    {
      if ( a3 )
      {
        do
        {
          v15 = a2[v14];
          v16 = v14 + 6 * *(_DWORD *)(this + 296);
          ++v14;
          *(_DWORD *)(*(_DWORD *)(this + 292) + 4 * v16 - 16) = v15;
        }
        while ( v14 < a3 );
      }
    }
  }
  *a4 = v18;
  return 0;
}
