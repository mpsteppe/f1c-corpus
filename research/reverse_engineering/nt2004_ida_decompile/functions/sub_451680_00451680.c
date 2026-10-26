char __thiscall sub_451680(_DWORD *this, float a2)
{
  _DWORD *v2; // ebx
  int v3; // eax
  int v4; // esi
  int v5; // ecx
  int v6; // edx
  _BYTE *v7; // esi
  float *v8; // edi
  __int16 v9; // bp
  int v10; // esi
  __int16 *v11; // ecx
  __int16 v12; // ax
  __int16 v13; // ax
  __int16 v15; // [esp+10h] [ebp-214h]
  char v16; // [esp+17h] [ebp-20Dh]
  int v17; // [esp+18h] [ebp-20Ch]
  _BYTE *i; // [esp+20h] [ebp-204h]
  _BYTE v20[256]; // [esp+24h] [ebp-200h] BYREF
  char v21; // [esp+124h] [ebp-100h] BYREF
  char v22; // [esp+125h] [ebp-FFh]
  char v23; // [esp+15Dh] [ebp-C7h]

  v2 = this;
  v3 = this[1];
  if ( !v3 )
    return v3;
  this[802] = 0;
  LOBYTE(v3) = sub_4DA570(&dword_7D5DA4);
  v16 = v3;
  if ( !byte_6098E5 )
  {
    if ( !(_BYTE)v3 )
      return v3;
    goto LABEL_6;
  }
  if ( (_BYTE)v3 )
  {
LABEL_6:
    if ( (unsigned __int8)sub_4DA590(v20) )
    {
      v4 = 0;
    }
    else
    {
      memset(v20, 0, sizeof(v20));
      v4 = 1;
    }
    LOBYTE(v3) = byte_6098E5;
    if ( byte_6098E5 )
    {
      v3 = sub_451580((_DWORD **)v2, (int)&v21);
      if ( !v3 )
      {
        LOBYTE(v3) = sub_405BE0(&dword_629124);
        if ( (_BYTE)v3 )
        {
          LOBYTE(v3) = v22;
          if ( v22 || (LOBYTE(v3) = v23) != 0 )
            v20[1] = 0x80;
        }
        else
        {
          v20[1] = v22;
        }
      }
    }
    goto LABEL_17;
  }
  v3 = sub_451580((_DWORD **)v2, (int)v20);
  v4 = v3;
LABEL_17:
  if ( v4 )
    return v3;
  v15 = 0;
  if ( v20[29] < 0 || v20[157] < 0 )
    v15 = 4096;
  if ( v20[56] < 0 )
    v15 |= 0x2000u;
  if ( v20[42] < 0 )
    v15 |= 0x8000u;
  if ( v20[54] < 0 )
    v15 |= 0x8000u;
  if ( v20[69] < 0 )
    v15 |= 0x4000u;
  v5 = 1;
  v6 = v20 - (_BYTE *)(v2 + 224);
  v17 = 1;
  v7 = (char *)v2 + 897;
  v8 = (float *)(v2 + 289);
  for ( i = (_BYTE *)v6; ; v6 = (int)i )
  {
    if ( (char)v7[v6] >= 0 || dbl_7DA9D8 < v8[256] )
    {
      *v7 = 0;
    }
    else
    {
      if ( (*v7 & 1) != 0 )
      {
        if ( *((_BYTE *)v2 + v5 + 640) )
        {
          if ( *((_BYTE *)v2 + v5 + 640) == 1 )
          {
            *v8 = a2 + *v8;
            *v7 = 1;
            if ( *v8 >= 0.0 )
            {
              *v7 = 3;
              *v8 = *((float *)v2 + 801);
            }
          }
        }
        else
        {
          *v7 = 1;
        }
      }
      else
      {
        *v7 = 3;
        *v8 = *((float *)v2 + 800);
      }
      if ( (*v7 & 2) != 0 )
      {
        v9 = v5 | v15;
        if ( sub_405BF0(&dword_629124) && dword_75CBA8 == 5 )
        {
          v5 = v17;
          if ( !v16 && v17 != 1 )
          {
            v2 = this;
            goto LABEL_46;
          }
        }
        else
        {
          v5 = v17;
        }
        v2 = this;
        *((_WORD *)this + this[802]++ + 1606) = v9;
      }
    }
LABEL_46:
    ++v5;
    ++v8;
    ++v7;
    v17 = v5;
    if ( v5 >= 256 )
      break;
  }
  LOBYTE(v3) = v20[58];
  if ( v20[58] < 0 )
  {
    v3 = v2[802];
    v10 = 0;
    if ( v3 > 0 )
    {
      v11 = (__int16 *)(v2 + 803);
      do
      {
        v12 = *v11;
        switch ( (unsigned __int8)*v11 )
        {
          case 0x10u:
          case 0x11u:
          case 0x12u:
          case 0x13u:
          case 0x14u:
          case 0x15u:
          case 0x16u:
          case 0x17u:
          case 0x18u:
          case 0x19u:
          case 0x1Eu:
          case 0x1Fu:
          case 0x20u:
          case 0x21u:
          case 0x22u:
          case 0x23u:
          case 0x24u:
          case 0x25u:
          case 0x26u:
          case 0x2Cu:
          case 0x2Du:
          case 0x2Eu:
          case 0x2Fu:
          case 0x30u:
          case 0x31u:
          case 0x32u:
            if ( v12 >= 0 )
              v13 = v12 | 0x8000;
            else
              v13 = v12 & 0x7FFF;
            *v11 = v13;
            break;
          default:
            break;
        }
        v3 = v2[802];
        ++v10;
        ++v11;
      }
      while ( v10 < v3 );
    }
  }
  return v3;
}
