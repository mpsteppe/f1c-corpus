int __thiscall sub_5F4990(_DWORD *this, int *a2, int a3, int a4, int a5)
{
  char v6; // bl
  unsigned int v8; // esi
  int v9; // ecx
  int v10; // eax
  int v11; // ebx
  int v12; // eax
  int v13; // edx
  _DWORD *v14; // esi
  bool v15; // cc
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  _DWORD *v19; // esi
  int v20; // eax
  int v21; // eax
  int v23; // eax
  int v24; // [esp+14h] [ebp-18h] BYREF
  int v25; // [esp+18h] [ebp-14h]
  int v26; // [esp+1Ch] [ebp-10h] BYREF
  int v27; // [esp+20h] [ebp-Ch]
  int v28; // [esp+24h] [ebp-8h]
  int v29; // [esp+28h] [ebp-4h]
  int v30; // [esp+30h] [ebp+4h]
  int v31; // [esp+30h] [ebp+4h]
  int v32; // [esp+3Ch] [ebp+10h]

  v6 = a5;
  if ( BinkWait(this[1]) )
  {
    if ( (a5 & 0x40) != 0 )
      return this[2] == 0;
  }
  else
  {
    BinkDoFrame(this[1]);
    BinkNextFrame(this[1]);
    this[2] = (unsigned int)(this[2] + 1) % *(_DWORD *)(this[1] + 8);
  }
  switch ( a2[6] )
  {
    case 5:
      a5 = 9;
      break;
    case 6:
      a5 = 10;
      break;
    case 7:
      a5 = 1;
      break;
    case 8:
      a5 = 5;
      break;
    case 14:
      a5 = 3;
      break;
    default:
      break;
  }
  v8 = a5;
  if ( (v6 & 0x20) != 0 )
  {
    v8 = a5 | 0x80000000;
    a5 |= 0x80000000;
  }
  if ( v6 < 0 )
  {
    v23 = sub_5E6E70(a2, 0, 0, 2);
    if ( v23 )
    {
      BinkCopyToBuffer(this[1], v23, a2[4], a2[2], a3, a4, v8);
      goto LABEL_37;
    }
  }
  else
  {
    BinkGetRects(this[1], 0);
    v9 = this[1];
    if ( *(int *)(v9 + 180) > 0 )
    {
      v10 = *a2;
      v11 = 0;
      if ( (*a2 & 3) != 0 )
      {
        if ( (v10 & 1) != 0 )
        {
          v12 = sub_5E7120(a2, 1);
        }
        else
        {
          if ( (v10 & 2) == 0 )
            goto LABEL_20;
          v12 = sub_5E7120(a2, 2);
        }
        v11 = v12;
LABEL_20:
        v30 = 0;
        if ( *(int *)(this[1] + 180) > 0 )
        {
          v32 = 0;
          while ( 1 )
          {
            v13 = this[1];
            v14 = (_DWORD *)(v32 + v13 + 52);
            v26 = *v14;
            v27 = *(_DWORD *)(v32 + v13 + 56);
            v28 = *(_DWORD *)(v32 + v13 + 60) + *v14;
            v29 = *(_DWORD *)(v32 + v13 + 64) + *(_DWORD *)(v32 + v13 + 56);
            if ( (*(int (__stdcall **)(int, int *, int *, _DWORD))(*(_DWORD *)v11 + 52))(v11, &v24, &v26, 0) )
              return -1;
            BinkCopyToBufferRect(this[1], v25, v24, a2[2], a3, a4, *v14, v14[1], v14[2], v14[3], 0x80000000);
            (*(void (__stdcall **)(int))(*(_DWORD *)v11 + 56))(v11);
            v15 = ++v30 < *(_DWORD *)(this[1] + 180);
            v32 += 16;
            if ( !v15 )
              goto LABEL_38;
          }
        }
        goto LABEL_38;
      }
      if ( (v10 & 4) != 0 )
      {
        if ( (v10 & 8) != 0 )
        {
          v17 = 0;
          if ( *(int *)(v9 + 180) > 0 )
          {
            v31 = 0;
            while ( 1 )
            {
              v18 = this[1];
              v19 = (_DWORD *)(v31 + v18 + 52);
              v26 = *v19;
              v27 = *(_DWORD *)(v31 + v18 + 56);
              v28 = *(_DWORD *)(v31 + v18 + 60) + *v19;
              v29 = *(_DWORD *)(v31 + v18 + 64) + *(_DWORD *)(v31 + v18 + 56);
              v20 = sub_5E7150(a2, 4);
              if ( (*(int (__stdcall **)(int, _DWORD, int *, int *, _DWORD))(*(_DWORD *)v20 + 76))(
                     v20,
                     0,
                     &v24,
                     &v26,
                     0) )
              {
                return -1;
              }
              BinkCopyToBufferRect(this[1], v25, v24, a2[2], a3, a4, *v19, v19[1], v19[2], v19[3], a5);
              v21 = sub_5E7150(a2, 4);
              (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v21 + 80))(v21, 0);
              ++v17;
              v31 += 16;
              if ( v17 >= *(_DWORD *)(this[1] + 180) )
                goto LABEL_38;
            }
          }
          goto LABEL_38;
        }
        v16 = sub_5E6E70(a2, 0, 0, 2);
        if ( !v16 )
        {
LABEL_38:
          *a2 &= ~0x100u;
          return this[2] == 0;
        }
        BinkCopyToBuffer(this[1], v16, a2[4], a2[2], a3, a4, v8 | 0x80000000);
LABEL_37:
        sub_5E6EA0(a2, 0, 0, 2);
        goto LABEL_38;
      }
    }
  }
  return this[2] == 0;
}
