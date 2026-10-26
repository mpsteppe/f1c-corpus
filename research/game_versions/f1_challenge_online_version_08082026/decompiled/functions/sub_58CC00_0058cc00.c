unsigned int __cdecl sub_58CC00(unsigned int a1, _BYTE *a2, unsigned int a3)
{
  _BYTE *v3; // esi
  _BYTE *v4; // edi
  unsigned int v5; // ecx
  unsigned int result; // eax
  int v7; // esi
  int v8; // edi
  unsigned int v9; // ecx

  v3 = a2;
  v4 = (_BYTE *)a1;
  if ( a1 > (unsigned int)a2 && a1 < (unsigned int)&a2[a3] )
  {
    v7 = (int)&a2[a3 - 4];
    v8 = a3 + a1 - 4;
    if ( (v8 & 3) == 0 )
    {
      v9 = a3 >> 2;
      if ( a3 >> 2 >= 8 )
      {
        while ( v9 )
        {
          *(_DWORD *)v8 = *(_DWORD *)v7;
          v7 -= 4;
          v8 -= 4;
          --v9;
        }
        switch ( a3 & 3 )
        {
          case 0u:
            goto LABEL_32;
          case 1u:
            goto LABEL_33;
          case 2u:
            goto LABEL_34;
          case 3u:
            goto LABEL_35;
        }
      }
      switch ( a3 & 3 )
      {
        case 0u:
          goto LABEL_32;
        case 1u:
          goto LABEL_33;
        case 2u:
          goto LABEL_34;
        case 3u:
          goto LABEL_35;
      }
    }
    switch ( a3 )
    {
      case 0u:
LABEL_32:
        result = a1;
        break;
      case 1u:
LABEL_33:
        *(_BYTE *)(v8 + 3) = *(_BYTE *)(v7 + 3);
        result = a1;
        break;
      case 2u:
LABEL_34:
        *(_BYTE *)(v8 + 3) = *(_BYTE *)(v7 + 3);
        *(_BYTE *)(v8 + 2) = *(_BYTE *)(v7 + 2);
        result = a1;
        break;
      case 3u:
LABEL_35:
        *(_BYTE *)(v8 + 3) = *(_BYTE *)(v7 + 3);
        *(_BYTE *)(v8 + 2) = *(_BYTE *)(v7 + 2);
        *(_BYTE *)(v8 + 1) = *(_BYTE *)(v7 + 1);
        result = a1;
        break;
      default:
        __asm { jmp     dword ptr ds:loc_58CDE4+4[eax*4] }
        return result;
    }
  }
  else
  {
    if ( (a1 & 3) != 0 )
    {
      if ( a3 >= 4 )
        __asm { jmp     dword ptr ds:loc_58CC5C+4[eax*4] }
      __asm { jmp     dword ptr ds:loc_58CD58[ecx*4]; jumptable 0058CC35 case 0 }
    }
    v5 = a3 >> 2;
    switch ( v5 )
    {
      case 0u:
        goto LABEL_17;
      case 1u:
        goto LABEL_16;
      case 2u:
        goto LABEL_15;
      case 3u:
        goto LABEL_14;
      case 4u:
        goto LABEL_13;
      case 5u:
        goto LABEL_12;
      case 6u:
        goto LABEL_11;
      case 7u:
        *(_DWORD *)(a1 + 4 * v5 - 28) = *(_DWORD *)&a2[4 * v5 - 28];
LABEL_11:
        *(_DWORD *)(a1 + 4 * v5 - 24) = *(_DWORD *)&a2[4 * v5 - 24];
LABEL_12:
        *(_DWORD *)(a1 + 4 * v5 - 20) = *(_DWORD *)&a2[4 * v5 - 20];
LABEL_13:
        *(_DWORD *)(a1 + 4 * v5 - 16) = *(_DWORD *)&a2[4 * v5 - 16];
LABEL_14:
        *(_DWORD *)(a1 + 4 * v5 - 12) = *(_DWORD *)&a2[4 * v5 - 12];
LABEL_15:
        *(_DWORD *)(a1 + 4 * v5 - 8) = *(_DWORD *)&a2[4 * v5 - 8];
LABEL_16:
        *(_DWORD *)(a1 + 4 * v5 - 4) = *(_DWORD *)&a2[4 * v5 - 4];
        v3 = &a2[4 * v5];
        v4 = (_BYTE *)(4 * v5 + a1);
LABEL_17:
        switch ( a3 & 3 )
        {
          case 0u:
            goto LABEL_18;
          case 1u:
            goto LABEL_19;
          case 2u:
            goto LABEL_20;
          case 3u:
            goto LABEL_21;
        }
      default:
        qmemcpy((void *)a1, a2, 4 * v5);
        v3 = &a2[4 * v5];
        v4 = (_BYTE *)(a1 + 4 * v5);
        switch ( a3 & 3 )
        {
          case 0u:
LABEL_18:
            result = a1;
            break;
          case 1u:
LABEL_19:
            *v4 = *v3;
            result = a1;
            break;
          case 2u:
LABEL_20:
            *v4 = *v3;
            v4[1] = v3[1];
            result = a1;
            break;
          case 3u:
LABEL_21:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            result = a1;
            break;
        }
        break;
    }
  }
  return result;
}
