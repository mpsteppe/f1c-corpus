int __thiscall sub_5A8910(_DWORD *this, int a2, int a3, int a4, char a5)
{
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // eax
  int v12; // eax
  int v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+18h] [ebp-18h] BYREF
  int v15; // [esp+1Ch] [ebp-14h]
  int v16; // [esp+20h] [ebp-10h] BYREF
  int v17; // [esp+24h] [ebp-Ch]
  int v18; // [esp+28h] [ebp-8h]
  int v19; // [esp+2Ch] [ebp-4h]
  int v20; // [esp+34h] [ebp+4h]
  int v21; // [esp+40h] [ebp+10h]
  int v22; // [esp+40h] [ebp+10h]

  v13 = 3;
  if ( BinkWait(*this) )
  {
    if ( (a5 & 0x40) != 0 )
      return this[1] == 0;
  }
  else
  {
    BinkDoFrame(*this);
    BinkNextFrame(*this);
    this[1] = (unsigned int)(this[1] + 1) % *(_DWORD *)(*this + 8);
  }
  switch ( *(_DWORD *)(a2 + 48) )
  {
    case 5:
      v13 = 9;
      break;
    case 6:
      v13 = 10;
      break;
    case 7:
      v13 = 1;
      break;
    case 8:
      v13 = 5;
      break;
    default:
      break;
  }
  if ( (a5 & 0x20) != 0 )
    v13 |= 0x80000000;
  if ( a5 < 0 )
  {
    v12 = sub_59FD80((void *)a2, 0, 0);
    if ( v12 )
    {
      BinkCopyToBuffer(*this, v12, *(_DWORD *)(a2 + 40), *(_DWORD *)(a2 + 32), a3, a4, v13);
      sub_59FDA0((void *)a2, 0, 0);
LABEL_33:
      *(_DWORD *)(a2 + 56) &= ~0x400u;
    }
  }
  else
  {
    v7 = 0;
    BinkGetRects(*this, 0);
    v8 = *this;
    if ( *(int *)(*this + 180) > 0 )
    {
      v9 = *(_DWORD *)(a2 + 56);
      v21 = 0;
      if ( (v9 & 3) != 0 )
      {
        if ( (v9 & 1) != 0 )
        {
          v21 = *(_DWORD *)(a2 + 12);
        }
        else if ( (v9 & 2) != 0 )
        {
          v21 = *(_DWORD *)(a2 + 16);
        }
        v20 = 0;
        if ( *(int *)(v8 + 180) > 0 )
        {
          while ( 1 )
          {
            v16 = *(_DWORD *)(v7 + v8 + 52);
            v17 = *(_DWORD *)(v7 + v8 + 56);
            v18 = *(_DWORD *)(v7 + v8 + 52) + *(_DWORD *)(v7 + v8 + 60);
            v19 = *(_DWORD *)(v7 + v8 + 64) + *(_DWORD *)(v7 + v8 + 56);
            if ( (*(int (__stdcall **)(int, int *, int *, _DWORD))(*(_DWORD *)v21 + 36))(v21, &v14, &v16, 0) )
              return -1;
            BinkCopyToBufferRect(
              *this,
              v15,
              v14,
              *(_DWORD *)(a2 + 32),
              a3,
              a4,
              *(_DWORD *)(v7 + v8 + 52),
              *(_DWORD *)(v7 + v8 + 56),
              *(_DWORD *)(v7 + v8 + 60),
              *(_DWORD *)(v7 + v8 + 64),
              0x80000000);
            (*(void (__stdcall **)(int))(*(_DWORD *)v21 + 40))(v21);
            v8 = *this;
            v7 += 16;
            if ( ++v20 >= *(_DWORD *)(*this + 180) )
              goto LABEL_33;
          }
        }
        goto LABEL_33;
      }
      if ( (v9 & 4) != 0 )
      {
        if ( (v9 & 8) != 0 )
        {
          v22 = 0;
          if ( *(int *)(v8 + 180) > 0 )
          {
            while ( 1 )
            {
              v16 = *(_DWORD *)(v7 + v8 + 52);
              v17 = *(_DWORD *)(v7 + v8 + 56);
              v18 = *(_DWORD *)(v7 + v8 + 60) + *(_DWORD *)(v7 + v8 + 52);
              v19 = *(_DWORD *)(v7 + v8 + 56) + *(_DWORD *)(v7 + v8 + 64);
              if ( (*(int (__stdcall **)(_DWORD, _DWORD, int *, int *, _DWORD))(**(_DWORD **)(a2 + 20) + 64))(
                     *(_DWORD *)(a2 + 20),
                     0,
                     &v14,
                     &v16,
                     0) )
              {
                return -1;
              }
              BinkCopyToBufferRect(
                *this,
                v15,
                v14,
                *(_DWORD *)(a2 + 32),
                a3,
                a4,
                *(_DWORD *)(v7 + v8 + 52),
                *(_DWORD *)(v7 + v8 + 56),
                *(_DWORD *)(v7 + v8 + 60),
                *(_DWORD *)(v7 + v8 + 64),
                v13);
              (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 20) + 68))(*(_DWORD *)(a2 + 20), 0);
              v8 = *this;
              v7 += 16;
              if ( ++v22 >= *(_DWORD *)(*this + 180) )
                goto LABEL_33;
            }
          }
        }
        else
        {
          v10 = sub_59FD80((void *)a2, 0, 0);
          if ( v10 )
          {
            BinkCopyToBuffer(*this, v10, *(_DWORD *)(a2 + 40), *(_DWORD *)(a2 + 32), a3, a4, v13 | 0x80000000);
            sub_59FDA0((void *)a2, 0, 0);
          }
        }
        goto LABEL_33;
      }
    }
  }
  return this[1] == 0;
}
