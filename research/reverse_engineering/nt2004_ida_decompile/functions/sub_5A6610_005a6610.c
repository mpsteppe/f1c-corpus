int __thiscall sub_5A6610(int this, int a2, int a3)
{
  int v3; // eax
  int v4; // ebp
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int *v12; // edx
  int v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // eax
  int *v17; // edx
  int v18; // ebp
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int *v24; // edx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // ebx
  int v32; // ecx
  int v33; // eax
  _DWORD *v34; // eax
  _DWORD *v35; // eax
  int v37; // ecx
  int v38; // [esp+38h] [ebp-11Ch]
  int v39; // [esp+38h] [ebp-11Ch]
  int v40; // [esp+38h] [ebp-11Ch]
  int v41; // [esp+4Ch] [ebp-108h] BYREF
  int v42; // [esp+50h] [ebp-104h]
  char Buffer[256]; // [esp+54h] [ebp-100h] BYREF

  v3 = *(_DWORD *)(a2 + 48);
  v4 = 0;
  v6 = *(_DWORD *)(this + 4460);
  if ( v3 == 7 )
    sub_5B43F0(&v41, 8, 0);
  else
    sub_5B43F0(&v41, v3, 0);
  v7 = *(_DWORD *)(a2 + 56);
  if ( (v7 & 0x10) != 0 )
  {
    if ( v41 == 21 )
    {
      v41 = 22;
    }
    else if ( v41 == 25 )
    {
      v41 = 24;
    }
  }
  if ( (v7 & 1) != 0 )
  {
    v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int))(**(_DWORD **)(this + 4448) + 108))(
           *(_DWORD *)(this + 4448),
           *(_DWORD *)(a2 + 28),
           *(_DWORD *)(a2 + 32),
           v41,
           a2 + 12);
    *(_DWORD *)this = v8;
    if ( v8 )
      goto LABEL_75;
  }
  v9 = *(_DWORD *)(a2 + 56);
  if ( (v9 & 2) != 0 )
  {
    if ( (v9 & 0x40000) != 0 )
    {
      v10 = *(_DWORD *)(a2 + 36);
      if ( v10 == 32 )
        v11 = *(_DWORD *)(this + 8280);
      else
        v11 = v10 == 16 ? *(_DWORD *)(this + 8276) : v6;
      v12 = *(int **)(this + 4444);
      v38 = v11;
      v41 = v11;
      v42 = *v12;
      v13 = sub_5A4740((_DWORD *)this);
      v8 = (*(int (__stdcall **)(int, int, int, int, int, int, int))(v42 + 40))(v14, v13, 1, v6, 1, 1, v38);
      *(_DWORD *)this = v8;
      if ( v8 )
        goto LABEL_75;
    }
    v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4448) + 100))(
           *(_DWORD *)(this + 4448),
           *(_DWORD *)(a2 + 28),
           *(_DWORD *)(a2 + 32),
           v41,
           0,
           0,
           a2 + 16);
    *(_DWORD *)this = v8;
    if ( v8 )
      goto LABEL_75;
  }
  if ( (*(_DWORD *)(a2 + 56) & 0x40008) != 0 )
  {
    v15 = *(_DWORD *)(a2 + 36);
    if ( v15 == 32 )
    {
      v16 = *(_DWORD *)(this + 8280);
    }
    else if ( v15 == 16 )
    {
      v16 = *(_DWORD *)(this + 8276);
    }
    else
    {
      v16 = v6;
    }
    v17 = *(int **)(this + 4444);
    v39 = v16;
    v41 = v16;
    v18 = *v17;
    v19 = sub_5A4740((_DWORD *)this);
    v21 = (*(int (__stdcall **)(int, int, int, int, int, int, int))(v18 + 40))(v20, v19, 1, v6, 1, 3, v39);
    *(_DWORD *)this = v21;
    if ( !v21 )
      goto LABEL_51;
    v22 = *(_DWORD *)(a2 + 36);
    v4 = 0;
    if ( v22 == 32 )
      v23 = *(_DWORD *)(this + 8276);
    else
      v23 = v22 == 16 ? *(_DWORD *)(this + 8280) : v6;
    v24 = *(int **)(this + 4444);
    v40 = v23;
    v41 = v23;
    v42 = *v24;
    v25 = sub_5A4740((_DWORD *)this);
    v27 = (*(int (__stdcall **)(int, int, int, int, int, int, int))(v42 + 40))(v26, v25, 1, v6, 1, 3, v40);
    *(_DWORD *)this = v27;
    if ( v27 )
    {
      if ( !v41 )
      {
        v28 = *(_DWORD *)(a2 + 36);
        if ( v28 == 16 )
        {
          v29 = *(_DWORD *)(this + 5128);
          if ( (v29 & 0x1000000) != 0 )
          {
            v41 = 23;
          }
          else if ( (v29 & 0x4000000) != 0 )
          {
            v41 = 24;
          }
          else if ( (v29 & 0x2000000) != 0 )
          {
            v41 = 25;
          }
        }
        else if ( v28 == 24 || v28 == 32 )
        {
          v30 = *(_DWORD *)(this + 5128);
          if ( (v30 & 0x8000000) != 0 )
          {
            v41 = 20;
          }
          else if ( (v30 & 0x20000000) != 0 )
          {
            v41 = 22;
          }
          else if ( (v30 & 0x10000000) != 0 )
          {
            v41 = 21;
          }
        }
      }
      v31 = a3;
      *(_DWORD *)(a2 + 56) = *(_DWORD *)(a2 + 56) & 0xFFFBFFF3 | 4;
    }
    else
    {
LABEL_51:
      v31 = 1;
      *(_DWORD *)(a2 + 56) |= 0x80400u;
      v4 = 1;
    }
    sub_5B41C0(v41, 0, a2 + 48);
  }
  else
  {
    v31 = a3;
  }
  if ( (*(_BYTE *)(a2 + 56) & 8) == 0 )
    goto LABEL_71;
  if ( !v31 )
    v31 = 1;
  v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, int, _DWORD, int))(**(_DWORD **)(this + 4448) + 80))(
         *(_DWORD *)(this + 4448),
         *(_DWORD *)(a2 + 28),
         *(_DWORD *)(a2 + 32),
         v31,
         v4,
         v41,
         0,
         a2 + 24);
  *(_DWORD *)this = v8;
  if ( !v8 )
  {
    v33 = *(_DWORD *)(a2 + 56);
    if ( (v33 & 0x40000) != 0 && (v33 & 0x200000) == 0 )
    {
      v34 = operator new(0x40u);
      if ( v34 )
        v35 = sub_59F160(v34);
      else
        v35 = 0;
      *(_DWORD *)(a2 + 8) = v35;
      if ( sub_5A62C0((int *)this, 0, (_DWORD *)a2, (int)v35, 0) )
      {
        if ( *(_DWORD *)(a2 + 8) )
        {
          j_nullsub_6(*(void **)(a2 + 8));
          sub_5BE8AE();
        }
        *(_DWORD *)(a2 + 8) = 0;
        return 0;
      }
      sub_5A7610(a2, 0, 0, *(_DWORD *)(a2 + 28), *(_DWORD *)(a2 + 32), 0);
    }
LABEL_71:
    if ( (*(_BYTE *)(a2 + 56) & 4) != 0 )
    {
      v37 = *(_DWORD *)(a2 + 44);
      if ( !v37 )
        v37 = 1;
      v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, int, int, int))(**(_DWORD **)(this + 4448) + 80))(
             *(_DWORD *)(this + 4448),
             *(_DWORD *)(a2 + 28),
             *(_DWORD *)(a2 + 32),
             v37,
             0,
             v41,
             2,
             a2 + 20);
      *(_DWORD *)this = v8;
      if ( v8 )
        goto LABEL_75;
    }
    return 0;
  }
  v32 = *(_DWORD *)(a2 + 56);
  if ( (v32 & 0x40000) != 0 )
  {
    *(_DWORD *)(a2 + 56) = v32 & 0xFFFBFFF3 | 4;
    goto LABEL_71;
  }
LABEL_75:
  sprintf(Buffer, "%s - 0x%x", aCouldNotAlloca, v8);
  sub_591C60(this, -1, Buffer);
  return -1;
}
