// f1c  0x0044f150  size=732
void __thiscall sub_44F150(_DWORD *this, float a2)
{
  int v3; // ecx
  int v4; // eax
  float *v5; // ecx
  int v6; // esi
  int i; // eax
  int v8; // ecx
  _BYTE *v9; // eax
  int v10; // esi
  char v11; // dl
  int v12; // esi
  __int16 *v13; // ecx
  __int16 v14; // ax
  __int16 v15; // ax
  __int16 v16; // [esp+20h] [ebp-60Ch]
  float *v17; // [esp+24h] [ebp-608h]
  int v18; // [esp+28h] [ebp-604h] BYREF
  _BYTE v19[256]; // [esp+2Ch] [ebp-600h] BYREF
  _BYTE v20[1280]; // [esp+12Ch] [ebp-500h] BYREF

  v3 = this[1];
  if ( !v3 )
    return;
  this[801] = 0;
  if ( !byte_5CD08D )
    return;
  if ( *this != 2 )
  {
    for ( i = 0; i < 256; ++i )
      v19[i] = *((_BYTE *)this + i + 892) << 7;
    v18 = -1;
    if ( (*(int (__stdcall **)(int, int, _DWORD, int *, int))(*(_DWORD *)v3 + 40))(v3, 20, 0, &v18, 1)
      || (*(int (__stdcall **)(_DWORD, int, _BYTE *, int *, _DWORD))(*(_DWORD *)this[1] + 40))(
           this[1],
           20,
           v20,
           &v18,
           0) )
    {
      return;
    }
    v8 = v18;
    if ( v18 > 0 )
    {
      v9 = v20;
      do
      {
        v10 = *(_DWORD *)v9;
        v11 = v9[4] & 0x80;
        v9 += 20;
        --v8;
        v19[v10] = v11;
      }
      while ( v8 );
    }
    goto LABEL_9;
  }
  v4 = (*(int (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)v3 + 36))(v3, 256, v19);
  if ( v4 == -2147024884 || v4 == -2147024866 )
  {
    if ( (*(int (__stdcall **)(_DWORD))(*(_DWORD *)this[1] + 28))(this[1]) )
      return;
    v4 = (*(int (__stdcall **)(_DWORD, int, _BYTE *))(*(_DWORD *)this[1] + 36))(this[1], 256, v19);
  }
  if ( !v4 )
  {
LABEL_9:
    v16 = 0;
    if ( (v19[29] & 0x80) != 0 || (v19[157] & 0x80) != 0 )
      v16 = 4096;
    if ( (v19[56] & 0x80) != 0 )
      v16 |= 0x2000u;
    if ( (v19[42] & 0x80) != 0 )
      v16 |= 0x8000u;
    if ( (v19[54] & 0x80) != 0 )
      v16 |= 0x8000u;
    if ( (v19[69] & 0x80) != 0 )
      v16 |= 0x4000u;
    v5 = (float *)(this + 288);
    v6 = 1;
    v17 = (float *)(this + 288);
    do
    {
      if ( dbl_8AFEA8 >= v5[256] )
      {
        if ( (v19[v6] & 0x80) != 0 )
        {
          if ( (*((_BYTE *)this + v6 + 892) & 1) != 0 )
          {
            if ( *((_BYTE *)this + v6 + 636) )
            {
              if ( *((_BYTE *)this + v6 + 636) == 1 )
              {
                *v5 = a2 + *v5;
                *((_BYTE *)this + v6 + 892) = 1;
                if ( *v5 >= 0.0 )
                {
                  *((_BYTE *)this + v6 + 892) = 3;
                  *v5 = *((float *)this + 800);
                }
              }
            }
            else
            {
              *((_BYTE *)this + v6 + 892) = 1;
            }
          }
          else
          {
            *((_BYTE *)this + v6 + 892) = 3;
            *v5 = *((float *)this + 799);
          }
          if ( (*((_BYTE *)this + v6 + 892) & 2) != 0 )
          {
            if ( !sub_404F10(&dword_5EA43C) || dword_7C569C != 5 || v6 == 1 )
              *((_WORD *)this + this[801]++ + 1604) = v6 | v16;
            v5 = v17;
          }
        }
        else
        {
          *((_BYTE *)this + v6 + 892) = 0;
        }
      }
      ++v6;
      v17 = ++v5;
    }
    while ( v6 < 256 );
    if ( (v19[58] & 0x80) != 0 )
    {
      v12 = 0;
      if ( (int)this[801] > 0 )
      {
        v13 = (__int16 *)(this + 802);
        do
        {
          v14 = *v13;
          switch ( (unsigned __int8)*v13 )
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
              if ( v14 >= 0 )
                v15 = v14 | 0x8000;
              else
                v15 = v14 & 0x7FFF;
              *v13 = v15;
              break;
            default:
              break;
          }
          ++v12;
          ++v13;
        }
        while ( v12 < this[801] );
      }
    }
  }
}
