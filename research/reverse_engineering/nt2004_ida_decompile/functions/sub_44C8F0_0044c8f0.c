int __thiscall sub_44C8F0(int this, float a2, int Buffer)
{
  int v3; // edi
  int v5; // ebx
  int v6; // ebp
  float v7; // eax
  int v8; // ebp
  _DWORD *v9; // ecx
  int v11; // ecx
  int i; // ebp
  __int16 v13; // ax
  float v14; // edx
  float v15; // edx
  float v16; // [esp-8h] [ebp-44h]
  char v17; // [esp+12h] [ebp-2Ah] BYREF
  char v18; // [esp+13h] [ebp-29h] BYREF
  float v19; // [esp+14h] [ebp-28h] BYREF
  int v20; // [esp+18h] [ebp-24h]
  float v21; // [esp+1Ch] [ebp-20h]
  float v22[6]; // [esp+20h] [ebp-1Ch] BYREF
  float v23; // [esp+38h] [ebp-4h]

  v3 = Buffer;
  sub_57A3A0((void *)this, 4u);
  sub_57A3A0((void *)(this + 4), 4u);
  v5 = LODWORD(a2);
  v6 = 0;
  v7 = a2;
  if ( a2 == 0.0 )
  {
LABEL_8:
    LOBYTE(Buffer) = *(_BYTE *)(this + 8);
    sub_57A3A0(&Buffer, 1u);
    *(_WORD *)(this + 10) = -1;
    *(_DWORD *)(this + 12) = *(_DWORD *)(v3 + 36) + 92 * *(_DWORD *)(v3 + 28);
    *(_DWORD *)(v3 + 28) += v6;
    if ( v5 )
    {
      v8 = 0;
      do
      {
        v9 = (_DWORD *)(v8 + *(_DWORD *)(this + 12));
        v8 += 92;
        sub_44C310(v9, v5, v3);
        v5 = *(_DWORD *)(v5 + 28);
      }
      while ( v5 );
    }
    return 0;
  }
  do
  {
    v7 = *(float *)(LODWORD(v7) + 28);
    ++v6;
  }
  while ( v7 != 0.0 );
  if ( v6 < 3 )
  {
    if ( v6 == 1 )
    {
      *(_WORD *)(this + 8) = -1;
    }
    else if ( v6 == 2 )
    {
      *(_WORD *)(this + 8) = -2;
    }
    goto LABEL_8;
  }
  if ( v6 <= 100 )
    v11 = v6 <= 10 ? 15 : 6;
  else
    v11 = 3;
  Buffer = 1;
  if ( 14 / v11 >= 1 )
    Buffer = 14 / v11;
  v20 = -1;
  v21 = 3.4028235e38;
  for ( i = v6 % Buffer; i < 14; i += Buffer )
  {
    sub_44C890(i, &v19, &a2);
    sub_44C710(v22, v5, *(float **)(v3 + 52), v19, a2, 0);
    if ( v23 < (double)v21 )
    {
      v21 = v23;
      v20 = i;
    }
  }
  sub_44C890(v20, &v19, &a2);
  sub_44C710(v22, v5, *(float **)(v3 + 52), v19, a2, 1);
  v13 = v20;
  if ( v20 > 7 )
  {
    *(_WORD *)(this + 8) = 1;
    *(_WORD *)(this + 10) = 14 - v13;
  }
  else
  {
    *(_WORD *)(this + 8) = 0;
    *(_WORD *)(this + 10) = v13;
  }
  v17 = *(_BYTE *)(this + 8);
  sub_57A3A0(&v17, 1u);
  v18 = *(_BYTE *)(this + 10);
  sub_57A3A0(&v18, 1u);
  v14 = v22[1];
  *(_DWORD *)(this + 12) = *(_DWORD *)(v3 + 48) + 16 * *(_DWORD *)(v3 + 40);
  *(_DWORD *)(v3 + 40) += 2;
  **(float **)(this + 12) = v14;
  v15 = v22[0];
  *(float *)(*(_DWORD *)(this + 12) + 4) = v22[2];
  if ( sub_44C8F0(v15, v3) )
    return -1;
  *(float *)(*(_DWORD *)(this + 12) + 16) = v22[4];
  v16 = v22[3];
  *(float *)(*(_DWORD *)(this + 12) + 20) = v22[5];
  return -(sub_44C8F0(v16, v3) != 0);
}
