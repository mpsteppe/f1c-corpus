int __thiscall sub_59CA30(void *this, int a2, char *buf, int len)
{
  int v4; // ecx
  int v5; // ebp
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int i; // ecx
  unsigned __int16 v10; // cx
  int v12; // edi
  char v13; // bl
  int v14; // eax
  int v15; // [esp-18h] [ebp-12Ch]
  int v16; // [esp-14h] [ebp-128h]
  int v17; // [esp-10h] [ebp-124h]
  int v18; // [esp-Ch] [ebp-120h]
  int v19; // [esp-8h] [ebp-11Ch]
  int v20; // [esp+Ch] [ebp-108h]
  char Buffer[256]; // [esp+14h] [ebp-100h] BYREF

  v4 = *(unsigned __int16 *)(a2 + 133188);
  v5 = 0;
  v6 = 0;
  v20 = v4;
  if ( *(_WORD *)(a2 + 133188) )
  {
    do
    {
      v7 = 256;
      if ( v4 <= 256 )
        v7 = v4;
      if ( v7 <= *(unsigned __int16 *)(a2 + 133188) )
      {
        v8 = *(_DWORD *)(a2 + 133184);
        for ( i = 0; i < v7; ++i )
        {
          Buffer[i] = *(_BYTE *)(v8 + a2 + 2112);
          v8 = (v8 + 1) % 0x20000;
        }
        v6 = sub_59C960(this, a2, Buffer, v7);
        if ( v6 <= 0 )
          goto LABEL_14;
        v20 -= v6;
        v10 = *(_WORD *)(a2 + 133188);
        if ( v6 <= v10 )
        {
          *(_WORD *)(a2 + 133188) = v10 - v6;
          *(_DWORD *)(a2 + 133184) = (v6 + *(_DWORD *)(a2 + 133184)) % 0x20000;
        }
        v5 += v6;
        if ( v6 < v7 )
        {
LABEL_14:
          v4 = v20;
          break;
        }
        v4 = v20;
      }
    }
    while ( v4 > 0 );
  }
  if ( !buf )
    return v5;
  v12 = 0;
  v13 = 0;
  if ( v6 == -1 || !v4 && (v12 = sub_59C960(this, a2, buf, len), v12 == -1) )
    v13 = 1;
  if ( v12 < len )
  {
    if ( !(unsigned __int8)sub_59C460() )
    {
      v19 = *(unsigned __int16 *)(a2 + 18);
      v18 = *(unsigned __int8 *)(a2 + 23);
      v17 = *(unsigned __int8 *)(a2 + 22);
      v16 = *(unsigned __int8 *)(a2 + 21);
      v15 = *(unsigned __int8 *)(a2 + 20);
      Buffer[0] = 0;
      sprintf(Buffer, "Out of outgoing buffer room for %d.%d.%d.%d:%d", v15, v16, v17, v18, v19);
      v14 = sub_5A3CE0(this);
      (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v14 + 24))(v14, Buffer, 2);
      nullsub_7(this);
      goto LABEL_25;
    }
    v12 = len;
  }
  if ( v13 )
  {
LABEL_25:
    *(_BYTE *)(a2 + 40) = 1;
    *(_DWORD *)(a2 + 36) = 0;
  }
  return v12;
}
