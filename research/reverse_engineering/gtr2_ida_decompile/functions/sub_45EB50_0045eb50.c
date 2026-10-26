void __thiscall sub_45EB50(_DWORD *this, float a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // edi
  _BYTE *v6; // ecx
  float *v7; // edx
  int v8; // eax
  int i; // eax
  int v10; // ecx
  _BYTE *v11; // eax
  int v12; // edi
  char v13; // dl
  int v14; // edi
  __int16 *v15; // ecx
  __int16 v16; // ax
  __int16 v17; // ax
  int v18; // [esp+24h] [ebp-608h]
  int v19; // [esp+28h] [ebp-604h] BYREF
  _BYTE v20[256]; // [esp+2Ch] [ebp-600h] BYREF
  _BYTE v21[1280]; // [esp+12Ch] [ebp-500h] BYREF

  v3 = this[1];
  if ( !v3 )
    return;
  this[802] = 0;
  if ( !byte_75B2B9 )
    return;
  if ( *this != 2 )
  {
    for ( i = 0; i < 256; ++i )
      v20[i] = *((_BYTE *)this + i + 896) << 7;
    v19 = -1;
    if ( (*(int (__stdcall **)(int, int, _DWORD, int *, int))(*(_DWORD *)v3 + 40))(v3, 20, 0, &v19, 1)
      || (*(int (__stdcall **)(_DWORD, int, _BYTE *, int *, _DWORD))(*(_DWORD *)this[1] + 40))(
           this[1],
           20,
           v21,
           &v19,
           0) )
    {
      return;
    }
    v10 = v19;
    if ( v19 > 0 )
    {
      v11 = v21;
      do
      {
        v12 = *(_DWORD *)v11;
        v13 = v11[4] & 0x80;
        v11 += 20;
        --v10;
        v20[v12] = v13;
      }
      while ( v10 );
    }
    goto LABEL_9;
  }
  v4 = (*(int (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)v3 + 36))(v3, 256, v20);
  if ( v4 == -2147024884 || v4 == -2147024866 )
  {
    if ( (*(int (__stdcall **)(_DWORD))(*(_DWORD *)this[1] + 28))(this[1]) )
      return;
    v4 = (*(int (__stdcall **)(_DWORD, int, _BYTE *))(*(_DWORD *)this[1] + 36))(this[1], 256, v20);
  }
  if ( !v4 )
  {
LABEL_9:
    v18 = 0;
    if ( (v20[29] & 0x80) != 0 || (v20[157] & 0x80) != 0 )
      v18 = 4096;
    if ( (v20[56] & 0x80) != 0 )
      v18 |= 0x2000u;
    if ( (v20[42] & 0x80) != 0 )
      v18 |= 0x8000u;
    if ( (v20[54] & 0x80) != 0 )
      v18 |= 0x8000u;
    if ( (v20[69] & 0x80) != 0 )
      v18 |= 0x4000u;
    v5 = 1;
    v6 = (char *)this + 897;
    v7 = (float *)(this + 289);
    while ( (v6[v20 - (_BYTE *)(this + 224)] & 0x80) == 0 || dbl_FB1D20 < v7[256] )
    {
      *v6 = 0;
LABEL_42:
      ++v5;
      ++v7;
      ++v6;
      if ( v5 >= 256 )
      {
        if ( (v20[58] & 0x80) != 0 )
        {
          v14 = 0;
          if ( (int)this[802] > 0 )
          {
            v15 = (__int16 *)(this + 803);
            do
            {
              v16 = *v15;
              switch ( (unsigned __int8)*v15 )
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
                  if ( v16 >= 0 )
                    v17 = v16 | 0x8000;
                  else
                    v17 = v16 & 0x7FFF;
                  *v15 = v17;
                  break;
                default:
                  break;
              }
              ++v14;
              ++v15;
            }
            while ( v14 < this[802] );
          }
        }
        return;
      }
    }
    if ( (*v6 & 1) != 0 )
    {
      if ( !*((_BYTE *)this + v5 + 640) )
      {
        *v6 = 1;
        goto LABEL_39;
      }
      if ( *((_BYTE *)this + v5 + 640) != 1 || (*v7 = a2 + *v7, *v6 = 1, *v7 < 0.0) )
      {
LABEL_39:
        if ( (*v6 & 2) != 0 )
          *((_WORD *)this + this[802]++ + 1606) = v18 | v5;
        goto LABEL_42;
      }
      *v6 = 3;
      v8 = this[801];
    }
    else
    {
      *v6 = 3;
      v8 = this[800];
    }
    *(_DWORD *)v7 = v8;
    goto LABEL_39;
  }
}
