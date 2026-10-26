int __thiscall sub_59F600(_DWORD *this, const char *a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v7; // eax
  _DWORD *v8; // ebp
  int v9; // edx
  _DWORD *v10; // eax
  int *v11; // esi
  unsigned int v13; // ecx
  char v14; // dl
  unsigned int v15; // ecx
  char v16; // dl
  const char *v17; // ecx
  int v18; // eax
  int v19; // edi
  int v20; // edi
  int v21; // esi
  int v22; // eax
  int v23; // eax
  int v24; // esi
  char v25[16]; // [esp+18h] [ebp-610h] BYREF
  char String[768]; // [esp+28h] [ebp-600h] BYREF
  char Buffer[768]; // [esp+328h] [ebp-300h] BYREF

  if ( (a6 & 0xF) != 0 )
  {
    v7 = operator new(0x40u);
    if ( v7 )
      v8 = sub_59F160(v7);
    else
      v8 = 0;
    if ( (a6 & 0x800) != 0 )
    {
      v8[14] |= 0x800u;
      sub_5A0280(this[13]);
    }
    if ( ((unsigned int)&unk_800000 & a6) != 0 )
      v8[14] |= (unsigned int)&unk_800000;
    v9 = v8[14];
    if ( (a6 & 0x4000) != 0 )
    {
      v8[14] = v9 | 0x4000;
      strcpy(String, a2);
      _strupr(String);
      v10 = operator new(0x40u);
      if ( v10 )
        v11 = sub_59F160(v10);
      else
        v11 = 0;
      if ( (a6 & 0x800) != 0 )
      {
        v11[14] |= 0x800u;
        sub_5A0280(this[13]);
      }
      if ( ((unsigned int)&unk_800000 & a6) != 0 )
        v11[14] |= (unsigned int)&unk_800000;
      v11[14] |= 1u;
      if ( sub_59FB10((int)v11, (int)String) )
      {
LABEL_18:
        j_nullsub_6(v11);
        sub_5BE8AE();
        return -1;
      }
      if ( sub_59F5A0(v8, v11[7], v11[8], v11[12], this[11], v8[14] | 1) || sub_5A6B10(v11, v8, 0) )
        return -1;
      sub_59FA90((int)v11);
      v13 = strlen(String) + 1;
      v14 = v25[v13 + 14];
      v15 = v13 - 2;
      if ( v14 != 46 )
      {
        do
        {
          if ( !v15 )
            break;
          v16 = v25[v15-- + 15];
        }
        while ( v16 != 46 );
      }
      v17 = &String[v15];
      strcpy(v25, v17);
      v18 = this[11];
      v19 = 1;
      *v17 = 0;
      if ( v18 > 1 )
      {
        do
        {
          if ( (a6 & 0x800) != 0 )
          {
            v11[14] |= 0x800u;
            sub_5A0280(this[13]);
          }
          if ( ((unsigned int)&unk_800000 & a6) != 0 )
            v11[14] |= (unsigned int)&unk_800000;
          v11[14] |= 1u;
          sprintf(Buffer, "%s_MIP%.2d%s", String, v19, v25);
          if ( sub_59FB10((int)v11, (int)Buffer) )
            goto LABEL_18;
          if ( sub_5A6B10(v11, v8, v19) )
            return -1;
          sub_59FA90((int)v11);
        }
        while ( ++v19 < this[11] );
      }
      j_nullsub_6(v11);
      sub_5BE8AE();
      v20 = a4;
      v21 = a3;
    }
    else
    {
      v21 = a3;
      v20 = a4;
      v8[7] = a3;
      v8[8] = a4;
      v8[14] = v9 | 1;
      if ( (a6 & 0x1000000) == 0 && sub_59FB10((int)v8, (int)a2) )
        goto LABEL_61;
    }
    if ( (a6 & 0x800) != 0 )
      sub_5A0280(0);
    v22 = 8;
    if ( v8[12] == 8 )
      this[14] |= (unsigned int)&unk_800000;
    else
      v22 = a5;
    if ( sub_59F1B0(this, v22, a6) )
      goto LABEL_56;
    if ( v21 )
      this[7] = v21;
    else
      this[7] = v8[7];
    if ( v20 )
      this[8] = v20;
    else
      this[8] = v8[8];
    v23 = a6;
    this[14] = a6;
    v24 = v8[14] & 0xF;
    if ( (a6 & 1) != 0 )
    {
      if ( sub_5A6C20((int)&unk_7E6B48, (int)v8, v24, (int)this, 1, a6 & 0x1000000) )
        goto LABEL_56;
      v23 = a6;
    }
    if ( (this[14] & 2) != 0 )
    {
      if ( sub_5A6C20((int)&unk_7E6B48, (int)v8, v24, (int)this, 2, v23 & 0x1000000) )
      {
LABEL_56:
        sub_59FA90((int)v8);
        j_nullsub_6(v8);
        sub_5BE8AE();
        return -1;
      }
      v23 = a6;
    }
    if ( (this[14] & 4) != 0 )
    {
      if ( sub_5A6C20((int)&unk_7E6B48, (int)v8, v24, (int)this, 4, v23 & 0x1000000) )
        goto LABEL_56;
      v23 = a6;
    }
    if ( (this[14] & 8) != 0 && sub_5A6C20((int)&unk_7E6B48, (int)v8, v24, (int)this, 8, v23 & 0x1000000) )
    {
      sub_59FA90((int)v8);
LABEL_61:
      j_nullsub_6(v8);
      sub_5BE8AE();
      return -1;
    }
    sub_59FA90((int)v8);
    j_nullsub_6(v8);
    sub_5BE8AE();
  }
  return 0;
}
