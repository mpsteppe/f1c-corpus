int __thiscall sub_6C6619(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int v4; // edi
  bool v6; // zf
  int v8; // eax
  char *v9; // ebx
  int v10; // edi
  unsigned int v11; // edi
  int v12; // esi
  char ***v13; // ebx
  char Buffer[32]; // [esp+8h] [ebp-38h] BYREF
  _WORD v15[6]; // [esp+28h] [ebp-18h] BYREF
  int v16; // [esp+34h] [ebp-Ch]
  void *Block; // [esp+38h] [ebp-8h]
  int v18; // [esp+3Ch] [ebp-4h]
  unsigned int v19; // [esp+50h] [ebp+10h]

  v4 = 0;
  v6 = this[86] == 0;
  v18 = 0;
  Block = 0;
  if ( v6 )
    return 0;
  v8 = this[125] + this[124] + this[116];
  if ( v8 )
  {
    v9 = (char *)operator new(4 * v8);
    Block = v9;
    if ( v9 )
    {
      if ( this[11] )
      {
        while ( 1 )
        {
          sprintf(Buffer, "r_$Int%d", v4);
          v18 = sub_66078B(this + 109, Buffer, v4, 1);
          if ( v18 < 0 )
            break;
          if ( (unsigned int)++v4 >= this[11] )
          {
            v9 = (char *)Block;
            goto LABEL_10;
          }
        }
      }
      else
      {
LABEL_10:
        sub_65EC22(this + 109, (int)v9);
        v10 = this[125] + this[116];
        sub_65EC22(this + 117, (int)&v9[4 * v10]);
        v11 = this[124] + v10;
        sub_632C60((int)v9, v11);
        v15[0] = 1;
        v15[1] = 3;
        v15[2] = 1;
        v15[3] = 4;
        v15[4] = 1;
        v15[5] = 0;
        v16 = 0;
        v12 = a3 + 20 * a4;
        v19 = 0;
        if ( v11 )
        {
          while ( 1 )
          {
            v13 = (char ***)&v9[4 * v19];
            v18 = sub_68024C(a2, **v13, 0xFFFFFFFF, 7, (_DWORD *)v12);
            if ( v18 < 0 )
              break;
            v18 = sub_68024C(a2, (char *)v15, 0x10u, 6, (_DWORD *)(v12 + 12));
            if ( v18 < 0 )
              break;
            if ( (*v13)[3] )
            {
              *(_BYTE *)(v12 + 10) |= 1u;
              v18 = sub_68024C(a2, (char *)*v13 + 16, 0x10u, 7, (_DWORD *)(v12 + 16));
              if ( v18 < 0 )
                break;
            }
            ++v19;
            *(_WORD *)(v12 + 4) = 2;
            *(_WORD *)(v12 + 6) = *((_WORD *)*v13 + 2);
            *(_WORD *)(v12 + 8) = 1;
            v12 += 20;
            if ( v19 >= v11 )
              goto LABEL_18;
            v9 = (char *)Block;
          }
        }
        else
        {
LABEL_18:
          v18 = 0;
        }
      }
    }
    else
    {
      v18 = -2147024882;
    }
  }
  j__free(Block);
  return v18;
}
