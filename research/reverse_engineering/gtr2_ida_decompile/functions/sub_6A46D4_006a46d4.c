int __thiscall sub_6A46D4(_DWORD *this)
{
  _DWORD *v1; // esi
  bool v2; // zf
  int v3; // ebx
  unsigned int v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // edx
  int v11; // esi
  int v13; // [esp-4h] [ebp-1Ch]
  int v14; // [esp-4h] [ebp-1Ch]
  _DWORD **i; // [esp+Ch] [ebp-Ch]
  _DWORD **v16; // [esp+10h] [ebp-8h]
  unsigned int v17; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+14h] [ebp-4h]
  int v19; // [esp+14h] [ebp-4h]

  v18 = 0;
  if ( this[3] )
  {
    v16 = (_DWORD **)this[6];
    do
    {
      this[63] = v18;
      v1 = *v16;
      v2 = *v16 == 0;
      this[64] = *v16;
      if ( !v2 && *v1 )
      {
        v3 = *v1 & 0xFFFFF;
        v4 = *v1 & 0xFFF00000;
        if ( v4 > 0x60C00000 )
        {
          switch ( v4 )
          {
            case 0x60D00000u:
              v14 = 2;
LABEL_42:
              v5 = v14;
LABEL_43:
              v6 = 0;
LABEL_44:
              sub_686791(
                (int)this,
                v1[15],
                4532,
                "%s%s is not supported on ps_1_%i",
                *(const char **)&off_91A4B0[4 * v5],
                off_91A4C0[v6],
                (unsigned __int8)this[50]);
              return -2147467259;
            case 0x61100000u:
              v13 = 3;
LABEL_39:
              v5 = v13;
LABEL_40:
              v6 = 1;
              goto LABEL_44;
            case 0x61200000u:
              v14 = 3;
              goto LABEL_42;
          }
        }
        else
        {
          switch ( v4 )
          {
            case 0x60C00000u:
              v13 = 2;
              goto LABEL_39;
            case 0x60200000u:
              v5 = 0;
              goto LABEL_40;
            case 0x60300000u:
              v5 = 0;
              goto LABEL_43;
            case 0x60700000u:
              if ( (unsigned __int16)this[50] != 260 )
              {
                v6 = 1;
                v5 = 1;
                goto LABEL_44;
              }
              break;
            case 0x60800000u:
              v5 = 1;
              goto LABEL_43;
          }
        }
        if ( sub_6A2293(*v1 & 0xFFF00000) || v7 == 285212672 )
        {
          v8 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v1[2] + 4 * (v7 != 285212672 ? v3 : 0)));
          if ( *(_DWORD *)(v8 + 60) )
          {
            if ( (unsigned __int16)this[50] != 260
              && (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v8 + 4)) + 4) & 0x10) != 0 )
            {
              sub_686791(
                (int)this,
                v1[15],
                4532,
                "dependent texture read not supported on ps_1_%i",
                (unsigned __int8)this[50]);
              return -2147467259;
            }
          }
        }
      }
      ++v18;
      ++v16;
    }
    while ( v18 < this[3] );
  }
  v19 = 0;
  if ( !this[3] )
    return 0;
  for ( i = (_DWORD **)this[6]; ; ++i )
  {
    this[63] = v19;
    v9 = *i;
    v2 = *i == 0;
    this[64] = *i;
    if ( !v2 )
    {
      if ( *v9 )
      {
        v17 = 0;
        if ( v9[1] )
          break;
      }
    }
LABEL_32:
    if ( (unsigned int)++v19 >= this[3] )
      return 0;
  }
  v10 = (_DWORD *)v9[2];
  while ( 1 )
  {
    v11 = *(_DWORD *)(this[5] + 4 * *v10);
    if ( *(_DWORD *)(v11 + 4) == this[32] && *(_BYTE *)(v11 + 108) == 5 )
      break;
    ++v17;
    ++v10;
    if ( v17 >= *(_DWORD *)(this[64] + 4) )
      goto LABEL_32;
  }
  sub_686791((int)this, v9[15], 4512, "cannot access w component from texcoord in general expression");
  return -2147467259;
}
