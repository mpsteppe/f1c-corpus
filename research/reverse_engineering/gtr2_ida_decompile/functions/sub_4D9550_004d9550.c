int __thiscall sub_4D9550(_DWORD *this, int a2, __int32 a3)
{
  _DWORD *v3; // ebx
  int v4; // eax
  const CHAR *v5; // eax
  const CHAR *v6; // edi
  int v7; // esi
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  __int32 v11; // eax
  int v12; // edi
  int v13; // esi
  char v14; // bl
  _BYTE *v15; // edi
  char v16; // al
  int v18; // [esp-4h] [ebp-874h]
  const CHAR *v19; // [esp+0h] [ebp-870h]
  int v20; // [esp+4h] [ebp-86Ch]
  int v21; // [esp+Ch] [ebp-864h]
  int v22; // [esp+10h] [ebp-860h]
  void *Block[2]; // [esp+14h] [ebp-85Ch] BYREF
  int v24; // [esp+1Ch] [ebp-854h]
  _BYTE *v25; // [esp+20h] [ebp-850h] BYREF
  _BYTE *v26; // [esp+24h] [ebp-84Ch] BYREF
  int v27; // [esp+28h] [ebp-848h]
  int v28; // [esp+2Ch] [ebp-844h] BYREF
  int v29; // [esp+30h] [ebp-840h] BYREF
  _DWORD v30[2]; // [esp+34h] [ebp-83Ch] BYREF
  char v31[4]; // [esp+3Ch] [ebp-834h] BYREF
  const CHAR *v32; // [esp+40h] [ebp-830h] BYREF
  _BYTE v33[8]; // [esp+44h] [ebp-82Ch] BYREF
  _BYTE v34[2045]; // [esp+4Ch] [ebp-824h] BYREF
  __int16 v35; // [esp+849h] [ebp-27h]
  char v36; // [esp+84Bh] [ebp-25h]
  int v37; // [esp+868h] [ebp-8h]

  v3 = this;
  *(_DWORD *)v34 = this;
  if ( !a2 )
    return -1;
  if ( !a3 )
  {
    v4 = this[61];
    if ( v4 )
    {
      v5 = *(const CHAR **)(v4 + 64);
      if ( !v5 )
        v5 = WindowName;
      a3 = (__int32)v5;
    }
  }
  sub_4DF1B0(this[12], a3);
  *(_DWORD *)&v34[8] = 0;
  *(_DWORD *)&v34[12] = -1;
  sub_615860(a2);
  v37 = 0;
  v32 = WindowName;
  v6 = WindowName;
  v7 = sub_4CFCC0(v3, 2);
  if ( v7 <= 0 )
    v7 = v3[3] + v3[136];
  v8 = sub_4CFCC0(v3, 3);
  if ( v8 <= 0 )
    v8 = (*(int (__thiscall **)(_DWORD *))(*v3 + 4))(v3) - v3[136];
  v9 = v8 - v7;
  v27 = 1;
  v26 = &v34[4];
  v25 = v33;
  v10 = v3[12];
  *(_DWORD *)v34 = v9;
  v11 = sub_4E08C0(v10, WindowName, v33, &v34[4], 1, v28);
  HIBYTE(v28) = 1;
  if ( v30[0] > v9 )
  {
    while ( 1 )
    {
      memset(v34, 0, sizeof(v34));
      v35 = 0;
      v36 = 0;
      v12 = v29;
      sub_630FE0(v34, v29, 2047);
      v36 = 0;
      v13 = strlen(v34);
      sub_4E08C0(v3[12], v34, v30, &v32, 1, v24);
      if ( (int)v26 > v28 )
        break;
LABEL_21:
      if ( v13 <= 0 )
        goto LABEL_23;
      sub_4D93B0(a3, (int)&v28, 0, a3, 0, 0, 0, -1, -1, -1, -1);
LABEL_24:
      v15 = (_BYTE *)(strlen((const char *)&v28) + v12);
      if ( *v15 == 32 )
      {
        do
          v16 = *++v15;
        while ( v16 == 32 );
      }
      v11 = sub_4E08C0(v3[12], v15, Block, &v25, 1, v18);
      if ( v20 <= v21 )
      {
        v6 = v19;
        goto LABEL_28;
      }
    }
    while ( v13 > 0 )
    {
      v14 = 0;
      do
      {
        if ( v14 )
          break;
        if ( *((_BYTE *)&v30[1] + v13 + 3) == 32 || !HIBYTE(v24) )
          v14 = 1;
        *((_BYTE *)&v30[1] + v13 + 3) = 0;
        v13 = strlen(v31);
      }
      while ( v13 > 0 );
      sub_4E08C0(*(_DWORD *)(v27 + 48), v31, &v26, &v29, 1, v21);
      v12 = v22;
      v3 = Block[1];
      if ( (int)Block[0] <= v24 )
        goto LABEL_21;
    }
LABEL_23:
    HIBYTE(v21) = 0;
    goto LABEL_24;
  }
LABEL_28:
  if ( v6 )
    sub_4D93B0(v11, (int)v6, 0, a3, 0, 0, 0, -1, -1, -1, -1);
  sub_4D0B20(v3);
  if ( Block[0] )
    j_j__free(Block[0]);
  return 0;
}
