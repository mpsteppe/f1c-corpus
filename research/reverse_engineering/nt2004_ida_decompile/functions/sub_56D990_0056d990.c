int __thiscall sub_56D990(void *this, int a2, char *a3, int len)
{
  int v4; // ebx
  int v5; // ebp
  int v6; // eax
  int v7; // edi
  int v8; // eax
  int i; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // ebp
  int v13; // eax
  char *v14; // ebx
  int v15; // ecx
  char v16; // dl
  char *v18; // eax
  int v19; // eax
  int v20; // [esp-14h] [ebp-1B8h]
  int v21; // [esp-10h] [ebp-1B4h]
  int v22; // [esp-Ch] [ebp-1B0h]
  int v23; // [esp-8h] [ebp-1ACh]
  int v24; // [esp-4h] [ebp-1A8h]
  char v25; // [esp+13h] [ebp-191h]
  char Buffer[128]; // [esp+18h] [ebp-18Ch] BYREF
  char buf[256]; // [esp+98h] [ebp-10Ch] BYREF
  int v29; // [esp+1A0h] [ebp-4h]

  v4 = 0;
  v5 = *(unsigned __int16 *)(a2 + 18492);
  v6 = 0;
  if ( (_WORD)v5 )
  {
    do
    {
      v7 = 256;
      if ( v5 <= 256 )
        v7 = v5;
      if ( v7 <= *(unsigned __int16 *)(a2 + 18492) )
      {
        v8 = *(__int16 *)(a2 + 18490);
        for ( i = 0; i < v7; ++i )
        {
          buf[i] = *(_BYTE *)(v8 + a2 + 2106);
          v8 = (v8 + 1) % 0x4000;
        }
        v6 = sub_56D860(this, (char *)a2, buf, v7);
        if ( v6 <= 0 )
          break;
        v5 -= v6;
        if ( v6 <= *(unsigned __int16 *)(a2 + 18492) )
        {
          *(_WORD *)(a2 + 18492) -= v6;
          *(_WORD *)(a2 + 18490) = (v6 + *(__int16 *)(a2 + 18490)) % 0x4000;
        }
        v4 += v6;
        if ( v6 < v7 )
          break;
      }
    }
    while ( v5 > 0 );
  }
  if ( a3 )
  {
    v4 = 0;
    v25 = 0;
    if ( v6 == -1 || !v5 && (v4 = sub_56D860(this, (char *)a2, a3, len), v4 == -1) )
      v25 = 1;
    if ( v4 < len )
    {
      v10 = len - v4;
      v11 = *(unsigned __int16 *)(a2 + 18492);
      if ( (unsigned __int16)v11 + len - v4 > 0x4000 )
      {
        v18 = sub_56B280((char *)a2);
        Buffer[0] = 0;
        v24 = *((unsigned __int16 *)v18 + 1);
        v23 = (unsigned __int8)v18[7];
        v22 = (unsigned __int8)v18[6];
        v21 = (unsigned __int8)v18[5];
        v20 = (unsigned __int8)v18[4];
        v29 = 0;
        sprintf(Buffer, "Out of outgoing buffer room for %d.%d.%d.%d:%d", v20, v21, v22, v23, v24);
        v19 = sub_575D30(this);
        (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v19 + 24))(v19, Buffer, 2);
        nullsub_6(this);
        goto LABEL_24;
      }
      v12 = v11 + *(__int16 *)(a2 + 18490);
      v13 = 0;
      if ( v10 > 0 )
      {
        v14 = &a3[v4];
        do
        {
          v15 = (v13 + v12) % 0x4000;
          v16 = v14[v13++];
          *(_BYTE *)(v15 + a2 + 2106) = v16;
        }
        while ( v13 < v10 );
      }
      *(_WORD *)(a2 + 18492) += v10;
      v4 = len;
    }
    if ( v25 )
LABEL_24:
      *(_BYTE *)(a2 + 40) = 1;
  }
  return v4;
}
