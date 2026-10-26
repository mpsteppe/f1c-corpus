int __thiscall sub_6ABD51(void *this, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  int v5; // ebx
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  int v9; // edx
  int v10; // ebx
  int v11; // edi
  unsigned int v12; // esi
  char *v13; // ebx
  char *v14; // esi
  int v16; // edx
  unsigned int v17; // ecx
  _DWORD *v18; // eax
  int v19; // esi
  _DWORD v20[4]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v21[4]; // [esp+1Ch] [ebp-14h] BYREF
  int v22; // [esp+2Ch] [ebp-4h]

  v5 = (int)this;
  v6 = 0;
  v22 = (int)this;
  if ( (a4 & 0x10000) != 0 )
  {
    v21[0] = 0;
    v6 = 1;
  }
  if ( (a4 & 0x20000) != 0 )
    v21[v6++] = 1;
  if ( (a4 & 0x40000) != 0 )
    v21[v6++] = 2;
  if ( (a4 & 0x80000) != 0 )
    v21[v6++] = 3;
  v7 = a3;
  if ( a3 > v6 )
    v7 = v6;
  memset(v20, 255, sizeof(v20));
  v8 = 0;
  if ( v7 )
  {
    v9 = *(_DWORD *)(v5 + 20);
    do
    {
      v10 = v21[v8];
      v11 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * *(_DWORD *)((char *)&v21[v8++] + a2 - (_DWORD)v21)) + 16);
      v20[v10] = v11;
    }
    while ( v8 < v7 );
    v5 = v22;
  }
  if ( (unsigned __int16)*(_DWORD *)(v5 + 200) == 260 )
  {
    v12 = 0;
    v13 = (char *)&unk_91A410;
    while ( !sub_6A323B(v20, (int)v13) )
    {
      ++v12;
      v13 += 16;
      if ( v12 >= 5 )
        goto LABEL_21;
    }
    v14 = (char *)&unk_91A410 + 16 * v12;
    if ( v14 )
      goto LABEL_27;
LABEL_21:
    sub_686791(v22, *(_DWORD *)(*(_DWORD *)(v22 + 256) + 60), 4533, "cannot map swizzle to ps_1_4");
    return -2147467259;
  }
  else
  {
    v14 = (char *)&unk_91A440;
    if ( !sub_6A323B(v20, (int)&unk_91A440) )
    {
      v14 = (char *)&unk_91A450;
      if ( !sub_6A323B(v20, (int)&unk_91A450) && sub_6A323B(v20, (int)&unk_91A430) && (a4 & 0xF0000) == 0x80000 )
        v14 = (char *)&unk_91A430;
    }
LABEL_27:
    v16 = 0;
    v17 = 16;
    v18 = v14;
    do
    {
      v19 = *v18++ << v17;
      v16 |= v19;
      v17 += 2;
    }
    while ( v17 < 0x18 );
    *a5 = v16;
    return 0;
  }
}
