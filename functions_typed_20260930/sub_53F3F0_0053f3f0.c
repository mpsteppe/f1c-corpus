int __thiscall sub_53F3F0(int *this, int a2, _DWORD *a3, int a4, unsigned int a5)
{
  int *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edi
  int v12; // edi
  int v13; // ebx
  int v14; // edi
  int v15; // ebp
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v20; // [esp+20h] [ebp-20h]
  int v21; // [esp+34h] [ebp-Ch]
  int v22; // [esp+38h] [ebp-8h] BYREF
  int v23; // [esp+3Ch] [ebp-4h]

  if ( (a5 & 0x20) != 0 )
  {
    v21 = 2;
  }
  else if ( (a5 & 0x100) != 0 )
  {
    v21 = 3;
  }
  else if ( (a5 & 0x40) != 0 )
  {
    v21 = 4;
  }
  else if ( (a5 & 0x400) != 0 )
  {
    v21 = 6;
  }
  else
  {
    v21 = HIWORD(a5) & 0x10;
  }
  v6 = (int *)a2;
  if ( a2 )
  {
    v20 = *(_DWORD *)(a2 + 280);
    v23 = *(_DWORD *)(a2 + 260);
    v7 = sub_55BDE0(v20);
    sub_55C650(&a5, *(_DWORD *)(v7 + 20), 0);
    sub_55C450(a5, &v22, 0);
    if ( v22 == 16 )
    {
      v8 = *v6;
      if ( (*v6 & 0x1000000) != 0 )
      {
        a5 = 23;
      }
      else if ( (v8 & 0x4000000) != 0 )
      {
        a5 = 24;
      }
      else if ( (v8 & 0x2000000) != 0 )
      {
        a5 = 25;
      }
    }
    else if ( v22 == 24 || v22 == 32 )
    {
      v9 = *v6;
      if ( (*v6 & 0x8000000) != 0 )
      {
        a5 = 20;
      }
      else if ( (v9 & 0x20000000) != 0 )
      {
        a5 = 22;
      }
      else if ( (v9 & 0x10000000) != 0 )
      {
        a5 = 21;
      }
    }
  }
  else
  {
    sub_55C650(&a5, a3[12], 0);
    if ( a5 == 21 )
    {
      a5 = 22;
    }
    else if ( a5 == 25 )
    {
      a5 = 24;
    }
    v21 = 0;
    v23 = 0;
  }
  sub_55C650(&a2, a3[12], 0);
  v10 = a2;
  if ( a2 == 21 )
  {
    v10 = 22;
LABEL_35:
    a2 = v10;
    goto LABEL_36;
  }
  if ( a2 == 25 )
  {
    v10 = 24;
    goto LABEL_35;
  }
LABEL_36:
  if ( v6 )
  {
    sub_55C450(v10, &v22, 0);
    if ( v22 == 16 )
    {
      v11 = *v6;
      if ( (v11 & 0x1000000) != 0 )
      {
        a2 = 23;
      }
      else if ( (v11 & 0x4000000) != 0 )
      {
        a2 = 24;
      }
      else if ( (v11 & 0x2000000) != 0 )
      {
        a2 = 25;
      }
    }
    else if ( v22 == 24 || v22 == 32 )
    {
      v12 = *v6;
      if ( (v12 & 0x8000000) != 0 )
      {
        a2 = 20;
      }
      else if ( (v12 & 0x20000000) != 0 )
      {
        a2 = 22;
      }
      else if ( (v12 & 0x10000000) != 0 )
      {
        a2 = 21;
      }
    }
  }
  v13 = a4;
  v14 = (int)a3;
  v15 = 0;
  while ( 1 )
  {
    if ( v15 )
    {
      if ( v15 == 1 )
      {
        v14 = 77;
      }
      else if ( v15 == 2 )
      {
        v14 = 80;
      }
    }
    else
    {
      v14 = 71;
    }
    v16 = (*(int (__stdcall **)(int, int, int, unsigned int, int, int, int))(*(_DWORD *)this[1087] + 40))(
            this[1087],
            v23,
            1,
            a5,
            2,
            1,
            v14);
    *this = v16;
    if ( !v16 )
    {
      v17 = (*(int (__stdcall **)(int, int, int, unsigned int, int, int))(*(_DWORD *)this[1087] + 48))(
              this[1087],
              v23,
              1,
              a5,
              a2,
              v14);
      *this = v17;
      if ( !v17 )
      {
        v18 = (*(int (__stdcall **)(int, _DWORD, _DWORD, int, int, int))(*(_DWORD *)this[1088] + 104))(
                this[1088],
                a3[7],
                a3[8],
                v14,
                v21,
                v13 + 12);
        *this = v18;
        if ( !v18 )
          break;
      }
    }
    if ( ++v15 >= 3 )
    {
      sub_53C590(-1, aInvalidParamet);
      return -1;
    }
  }
  *(_DWORD *)(v13 + 24) |= 2u;
  return 0;
}

