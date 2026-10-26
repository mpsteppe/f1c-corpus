int __thiscall sub_6BC4F5(int this)
{
  int v2; // eax
  _DWORD *v4; // eax
  char *v5; // edi
  char *v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  int v12; // [esp+14h] [ebp-8h]
  int v13; // [esp+18h] [ebp-4h]

  v2 = **(_DWORD **)(this + 256);
  if ( (v2 & 0xFFF00000) != 0x11400000 || (v2 & 0xFFFFF) != 1 )
    return 1;
  if ( (*(_BYTE *)(this + 112) & 4) == 0 )
  {
    sub_686791(this, *(_DWORD *)(*(_DWORD *)(this + 256) + 60), 4552, "cannot map general loop to this instruction set");
    return -2147467259;
  }
  v4 = (_DWORD *)sub_681186(116);
  if ( v4 )
    v5 = (char *)sub_680CEC(v4);
  else
    v5 = 0;
  if ( !v5 )
    return -2147024882;
  v13 = sub_6811D1(v5, 1951399937, 2, 1, 0);
  v6 = v5;
  if ( v13 < 0 )
    goto LABEL_14;
  v13 = sub_680D22(v5, *(_DWORD *)(this + 256));
  if ( v13 < 0 || (v7 = sub_681AAA((void *)this, 0, 0, 0, 0.0), v12 = v7, v7 == -1) )
  {
    v6 = v5;
LABEL_14:
    sub_66238F(v6, 1);
    return v13;
  }
  v8 = *(_DWORD *)(this + 20);
  v9 = *(_DWORD *)(v8 + 4 * v7);
  sub_6815D6((double *)v9, *(_DWORD *)(v8 + 4 * **(_DWORD **)(*(_DWORD *)(this + 256) + 8)));
  **((_DWORD **)v5 + 4) = **(_DWORD **)(*(_DWORD *)(this + 256) + 16);
  **((_DWORD **)v5 + 2) = **(_DWORD **)(*(_DWORD *)(this + 256) + 8);
  *(_DWORD *)(*((_DWORD *)v5 + 2) + 4) = v12;
  if ( *(_DWORD *)(v9 + 56) == -1 )
  {
    v10 = **(_DWORD **)(*(_DWORD *)(this + 256) + 8);
    *(_BYTE *)(v9 + 62) |= 8u;
    *(_DWORD *)(v9 + 56) = v10;
  }
  else
  {
    *(_DWORD *)(v9 + 60) ^= 0x80000u;
  }
  v11 = sub_681430(*(char **)(this + 256), v5);
  sub_66238F(v5, 1);
  return v11;
}
