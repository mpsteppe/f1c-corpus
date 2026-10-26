unsigned int __thiscall sub_5A8E30(unsigned int *this, _DWORD *a2, int a3, int a4, int a5, char a6)
{
  unsigned int result; // eax
  int v8; // ebx
  _DWORD *v9; // esi
  unsigned int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  _DWORD v16[2]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v17[4]; // [esp+1Ch] [ebp-10h] BYREF
  int v18; // [esp+40h] [ebp+14h]

  result = *this;
  if ( a3 < *(_DWORD *)(*this + 8) )
  {
    v8 = 0;
    BinkGoto(result, a3, 0);
    BinkDoFrame(*this);
    this[1] = a3;
    v9 = a2;
    switch ( a2[12] )
    {
      case 5:
        a3 = 9;
        break;
      case 6:
        a3 = 10;
        break;
      case 7:
        a3 = 1;
        break;
      case 8:
        a3 = 5;
        break;
      default:
        break;
    }
    if ( (a6 & 0x20) != 0 )
      a3 |= 0x80000000;
    if ( (a6 & 0x10) != 0 )
      a3 |= 0x60000000u;
    if ( a6 < 0 )
    {
      result = sub_59FD80(a2, 0, 0);
      if ( result )
      {
        BinkCopyToBuffer(*this, result, a2[10], a2[8], a4, a5, a3);
        result = sub_59FDA0(a2, 0, 0);
        a2[14] &= ~0x400u;
      }
    }
    else
    {
      BinkGetRects(*this, 0);
      v10 = *this;
      v18 = 0;
      if ( *(int *)(*this + 180) > 0 )
      {
        while ( 1 )
        {
          v17[0] = *(_DWORD *)(v8 + v10 + 52);
          v17[1] = *(_DWORD *)(v8 + v10 + 56);
          v17[2] = *(_DWORD *)(v8 + v10 + 52) + *(_DWORD *)(v8 + v10 + 60);
          v11 = v9[14];
          v17[3] = *(_DWORD *)(v8 + v10 + 64) + *(_DWORD *)(v8 + v10 + 56);
          if ( (v11 & 1) != 0 )
            break;
          if ( (v11 & 2) != 0 )
          {
            v12 = v9[4];
            goto LABEL_17;
          }
          if ( (v11 & 4) != 0 )
          {
            v14 = v9[5];
            goto LABEL_22;
          }
          if ( (v11 & 8) != 0 )
          {
            v14 = v9[6];
LABEL_22:
            v13 = (*(int (__stdcall **)(int, _DWORD, _DWORD *, _DWORD *, _DWORD))(*(_DWORD *)v14 + 64))(
                    v14,
                    0,
                    v16,
                    v17,
                    0);
LABEL_23:
            a2 = (_DWORD *)v13;
          }
          if ( !a2 )
          {
            BinkCopyToBufferRect(
              *this,
              v16[1],
              v16[0],
              v9[8],
              a4,
              a5,
              *(_DWORD *)(v8 + v10 + 52),
              *(_DWORD *)(v8 + v10 + 56),
              *(_DWORD *)(v8 + v10 + 60),
              *(_DWORD *)(v8 + v10 + 64),
              a3);
            v15 = v9[14];
            if ( (v15 & 1) != 0 )
            {
              (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9[3] + 40))(v9[3]);
            }
            else if ( (v15 & 2) != 0 )
            {
              (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v9[4] + 40))(v9[4]);
            }
            else if ( (v15 & 4) != 0 )
            {
              (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)v9[5] + 68))(v9[5], 0);
            }
            else if ( (v15 & 8) != 0 )
            {
              (*(void (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)v9[6] + 68))(v9[6], 0);
            }
          }
          v10 = *this;
          v8 += 16;
          if ( ++v18 >= *(_DWORD *)(*this + 180) )
            goto LABEL_34;
        }
        v12 = v9[3];
LABEL_17:
        v13 = (*(int (__stdcall **)(int, _DWORD *, _DWORD *, _DWORD))(*(_DWORD *)v12 + 36))(v12, v16, v17, 0);
        goto LABEL_23;
      }
LABEL_34:
      result = v9[14] & 0xFFFFFBFF;
      v9[14] = result;
    }
  }
  return result;
}
