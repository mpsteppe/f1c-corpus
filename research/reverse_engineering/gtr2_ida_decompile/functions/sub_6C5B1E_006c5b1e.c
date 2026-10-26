int __thiscall sub_6C5B1E(int this, _DWORD *a2, unsigned int a3, int *a4, int a5)
{
  _DWORD *v5; // edx
  int v7; // eax
  unsigned int v8; // ecx
  unsigned int i; // edi
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  unsigned int v15; // eax
  int v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]

  v5 = a2;
  v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * *a2) + 60);
  v8 = 0;
  v17 = 0;
  v18 = 0;
  if ( (v7 & 0x400) != 0 )
  {
    v18 = (int)&dword_1000000;
  }
  else if ( (v7 & 0x800) != 0 )
  {
    v18 = (int)&dword_2000000;
  }
  else if ( (v7 & 0x1000) != 0 )
  {
    v18 = 50331648;
  }
  else if ( (v7 & 0x2000) != 0 )
  {
    v18 = 251658240;
  }
  else if ( (v7 & 0x4000) != 0 )
  {
    v18 = 234881024;
  }
  else if ( (v7 & 0x8000) != 0 )
  {
    v18 = 218103808;
  }
  if ( (v7 & 0x200) != 0 )
    BYTE2(v18) |= 0x10u;
  if ( a5 )
  {
    v17 = 983040;
  }
  else
  {
    for ( i = 0; i < a3; ++i )
    {
      v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v5[i]) + 16);
      v8 = 0;
      v11 = 0;
      if ( v10 )
      {
        v12 = v10 - 1;
        if ( v12 )
        {
          v13 = v12 - 1;
          if ( v13 )
          {
            if ( v13 == 1 )
              v11 = 0x80000;
          }
          else
          {
            v11 = 0x40000;
          }
        }
        else
        {
          v11 = 0x20000;
        }
      }
      else
      {
        v11 = 0x10000;
      }
      if ( (v11 & v17) != 0 )
      {
        sub_686791(this, *(_DWORD *)(*(_DWORD *)(this + 256) + 60), 4821, "internal error: overlapping output writes");
        v5 = a2;
        v8 = 0;
      }
      v17 |= v11;
    }
  }
  if ( *(char *)(this + 110) < 0 )
  {
    if ( (v17 & 0x80000) != 0 )
    {
      if ( (v17 & 0x70000) != 0 )
        v17 = 983040;
    }
    else
    {
      v17 = 458752;
    }
  }
  if ( (*(_BYTE *)(this + 204) & 1) != 0 && *(_DWORD *)(this + 292) && a3 )
  {
    do
    {
      v14 = v5[v8];
      v15 = v8 + 6 * *(_DWORD *)(this + 296);
      ++v8;
      *(_DWORD *)(*(_DWORD *)(this + 292) + 4 * v15 - 16) = v14;
    }
    while ( v8 < a3 );
  }
  *a4 = v17 | v18;
  return 0;
}
