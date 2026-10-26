int __thiscall sub_5969C0(_DWORD *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // ebp
  int *v5; // eax
  _DWORD *v6; // ebx
  _DWORD *v7; // edi
  _DWORD *v8; // eax
  int v9; // edi
  int v10; // ebx
  int v11; // ebx
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  char *v15; // edi
  int v16; // eax
  int v17; // ebx
  int v18; // ebx
  int v19; // edi
  int *v20; // edi
  int v21; // ebx
  int v22; // edi
  int v23; // edi
  int i; // esi
  int v26; // [esp+10h] [ebp-24h]
  char Buffer[32]; // [esp+14h] [ebp-20h] BYREF

  if ( sub_5B4BE0(&unk_7E6B48) && (this[60] & 0x100000) != 0 )
  {
    if ( (int)this[91] > 0 )
    {
      v2 = 0;
      v3 = 0;
      do
      {
        sub_5A2660(v3 + this[92]);
        ++v2;
        v3 += 96;
      }
      while ( v2 < this[91] );
      sub_599CB0(this[92]);
      this[91] = 0;
      this[92] = 0;
    }
    this[60] &= ~0x100000u;
  }
  sub_5A78A0(this);
  if ( (this[60] & 0x100000) == 0 )
  {
    if ( sub_5B4BE0(&unk_7E6B48) )
    {
      v4 = this[89];
      v26 = v4;
      if ( v4 <= 0 )
        goto LABEL_52;
    }
    else
    {
      if ( (int)this[89] <= 0 )
        goto LABEL_52;
      v26 = 1;
      v4 = 1;
    }
    if ( dword_7E8CD0 )
    {
      sub_59FA90(dword_7E8CD0);
      if ( dword_7E8CD0 )
      {
        j_nullsub_6((void *)dword_7E8CD0);
        sub_5BE8AE();
      }
      dword_7E8CD0 = 0;
    }
    else if ( dword_7E8CD4 )
    {
      sub_59FA90(dword_7E8CD4);
      if ( dword_7E8CD4 )
      {
        j_nullsub_6((void *)dword_7E8CD4);
        sub_5BE8AE();
      }
      dword_7E8CD4 = 0;
    }
    v5 = (int *)operator new(96 * v4 + 4);
    if ( v5 )
    {
      v6 = v5 + 1;
      *v5 = v4;
      v7 = v5 + 1;
      if ( v4 - 1 >= 0 )
      {
        do
        {
          sub_5A1D10(v7);
          v7 += 24;
          --v4;
        }
        while ( v4 );
        v4 = v26;
      }
      v8 = v6;
    }
    else
    {
      v8 = 0;
    }
    v9 = 0;
    this[92] = v8;
    v8[22] = v4;
    if ( v4 > 0 )
    {
      v10 = 0;
      while ( 1 )
      {
        sprintf(Buffer, "SHADOWTEX%.3d", v9);
        if ( sub_5A1D50(Buffer) )
          break;
        if ( sub_59F580(dword_7E8D08, dword_7E8D08, dword_7E8D0C, 262152) )
        {
          if ( v9 >= 0 )
          {
            v18 = 0;
            v19 = v9 + 1;
            do
            {
              sub_5A2660(v18 + this[92]);
              v18 += 96;
              --v19;
            }
            while ( v19 );
          }
          sub_599CB0(this[92]);
          goto LABEL_45;
        }
        sub_5A0280(16711935);
        ++v9;
        v10 += 96;
        if ( v9 >= v4 )
          goto LABEL_46;
      }
      if ( v9 >= 0 )
      {
        v11 = 0;
        v12 = v9 + 1;
        do
        {
          sub_5A2660(v11 + this[92]);
          v11 += 96;
          --v12;
        }
        while ( v12 );
      }
      v13 = this[92];
      if ( v13 )
      {
        v14 = *(_DWORD *)(v13 - 4);
        v15 = (char *)(v13 + 96 * v14);
        v16 = v14 - 1;
        if ( v16 >= 0 )
        {
          v17 = v16 + 1;
          do
          {
            v15 -= 96;
            j_nullsub_6(v15);
            --v17;
          }
          while ( v17 );
        }
        sub_5BE8AE();
      }
LABEL_45:
      this[92] = 0;
    }
LABEL_46:
    if ( this[92] )
    {
      sub_599C60(this[92]);
      v20 = (int *)this[90];
      this[91] = v4;
      if ( v20 )
      {
        while ( !*v20 || !sub_5B86D0(*v20) )
        {
          v20 = (int *)v20[1];
          if ( !v20 )
            goto LABEL_51;
        }
        sub_591C60((int)this, -1, aErrorDuringSha);
        return -1;
      }
LABEL_51:
      this[60] |= 0x100000u;
    }
  }
LABEL_52:
  v21 = this[65];
  if ( v21 )
  {
    while ( 1 )
    {
      v22 = *(_DWORD *)(v21 + 236);
      if ( v22 )
        break;
LABEL_56:
      v21 = *(_DWORD *)(v21 + 260);
      if ( !v21 )
        goto LABEL_57;
    }
    while ( !sub_597020(v22, 0) )
    {
      v22 = *(_DWORD *)(v22 + 76);
      if ( !v22 )
        goto LABEL_56;
    }
    return -1;
  }
LABEL_57:
  v23 = this[67];
  if ( v23 )
  {
    while ( !sub_597020(v23, 0) )
    {
      v23 = *(_DWORD *)(v23 + 76);
      if ( !v23 )
        goto LABEL_60;
    }
    return -1;
  }
LABEL_60:
  for ( i = this[85]; i; i = *(_DWORD *)(i + 104) )
    sub_5AF4A0(i);
  return 0;
}
