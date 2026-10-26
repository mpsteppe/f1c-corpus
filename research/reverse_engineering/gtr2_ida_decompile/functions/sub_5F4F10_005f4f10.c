int __thiscall sub_5F4F10(_DWORD *this, int *a2, int a3, int a4, int a5, char a6)
{
  int result; // eax
  int v9; // edi
  int v10; // ebp
  int v11; // eax
  int v12; // ecx
  _DWORD *v13; // edi
  int v14; // eax
  bool v15; // zf
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  _DWORD v22[2]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v23[4]; // [esp+1Ch] [ebp-10h] BYREF
  int v24; // [esp+30h] [ebp+4h]
  int i; // [esp+40h] [ebp+14h]

  result = this[1];
  if ( a3 < *(_DWORD *)(result + 8) )
  {
    result = BinkGoto(result, a3, 0);
    if ( a2 )
    {
      BinkDoFrame(this[1]);
      this[2] = a3;
      switch ( a2[6] )
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
        case 14:
          a3 = 3;
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
        result = sub_5E6E70(a2, 0, 0, 2);
        if ( !result )
          return result;
        BinkCopyToBuffer(this[1], result, a2[4], a2[2], a4, a5, a3);
        result = sub_5E6EA0(a2, 0, 0, 2);
      }
      else
      {
        BinkGetRects(this[1], 0);
        result = *(_DWORD *)(this[1] + 180);
        v24 = 0;
        if ( result > 0 )
        {
          v9 = 0;
          v10 = a5;
          for ( i = 0; ; i += 16 )
          {
            v11 = this[1];
            v12 = *(_DWORD *)(v9 + v11 + 52);
            v13 = (_DWORD *)(v9 + v11 + 52);
            v23[0] = v12;
            v23[1] = v13[1];
            v23[2] = *v13 + v13[2];
            v14 = *a2;
            v15 = (*a2 & 1) == 0;
            v23[3] = v13[1] + v13[3];
            if ( v15 )
            {
              if ( (v14 & 2) != 0 )
              {
                v16 = sub_5E7150(a2, 2);
              }
              else if ( (v14 & 4) != 0 )
              {
                v16 = sub_5E7150(a2, 4);
              }
              else
              {
                if ( (v14 & 8) == 0 )
                  goto LABEL_25;
                v16 = sub_5E7150(a2, 8);
              }
            }
            else
            {
              v16 = sub_5E7150(a2, 1);
            }
            v10 = (*(int (__stdcall **)(int, _DWORD, _DWORD *, _DWORD *, _DWORD))(*(_DWORD *)v16 + 76))(
                    v16,
                    0,
                    v22,
                    v23,
                    0);
LABEL_25:
            if ( !v10 )
            {
              BinkCopyToBufferRect(this[1], v22[1], v22[0], a2[2], a4, a5, *v13, v13[1], v13[2], v13[3], a3);
              v17 = *a2;
              if ( (*a2 & 1) != 0 )
              {
                v18 = sub_5E7150(a2, 1);
                (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v18 + 80))(v18, 0);
              }
              else
              {
                if ( (v17 & 2) != 0 )
                {
                  v19 = sub_5E7150(a2, 2);
LABEL_34:
                  (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v19 + 80))(v19, 0);
                  goto LABEL_35;
                }
                if ( (v17 & 4) != 0 )
                {
                  v20 = sub_5E7150(a2, 4);
                  (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v20 + 80))(v20, 0);
                }
                else if ( (v17 & 8) != 0 )
                {
                  v19 = sub_5E7150(a2, 8);
                  goto LABEL_34;
                }
              }
            }
LABEL_35:
            v9 = i + 16;
            if ( ++v24 >= *(_DWORD *)(this[1] + 180) )
            {
              result = *a2 & 0xFFFFFEFF;
              *a2 = result;
              return result;
            }
          }
        }
      }
      *a2 &= ~0x100u;
    }
  }
  return result;
}
