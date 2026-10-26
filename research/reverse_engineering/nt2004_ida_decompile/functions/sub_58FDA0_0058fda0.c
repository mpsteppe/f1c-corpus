char __cdecl sub_58FDA0(int a1, int a2, int a3, _BYTE *a4)
{
  int v4; // ebp
  int v5; // ecx
  int v6; // edx
  unsigned __int8 *v7; // esi
  char v8; // di
  int v9; // eax
  int v10; // eax
  char result; // al
  char v12; // [esp+12h] [ebp-12h]
  char v13; // [esp+13h] [ebp-11h]
  int v14; // [esp+14h] [ebp-10h]
  unsigned int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h] BYREF
  int v17; // [esp+20h] [ebp-4h]
  char v18; // [esp+2Ch] [ebp+8h]

  v13 = 0;
  v12 = 0;
  sub_58D640(a1, &v16);
  v4 = 1;
  v5 = *(_BYTE *)(a2 + 7) & 0xF;
  v6 = 2 * *(unsigned __int8 *)(a2 + 6) + 3;
  v17 = v5;
  v15 = (v6 & 0xFFFFFFFC) + a2 + 12;
  do
  {
    if ( v5 <= 0 )
      goto LABEL_18;
    v7 = (unsigned __int8 *)v15;
    v8 = 7;
    v14 = v5;
    do
    {
      v9 = v7[1];
      v18 = 0;
      if ( v4 == 20 )
      {
        if ( v7[1] )
          goto LABEL_16;
      }
      else
      {
        if ( v9 != v4 )
          goto LABEL_16;
        v9 = *(_DWORD *)(a3 + 4 * v9);
      }
      if ( !dword_7FFA04 )
      {
LABEL_14:
        v12 |= 1 << v8;
        goto LABEL_15;
      }
      v10 = dword_7FFA04(a1, *v7, v9, v16);
      if ( v10 )
      {
        if ( v10 <= 0 )
          goto LABEL_14;
        v18 = 1 << v8;
      }
      else
      {
        v18 = 0;
      }
LABEL_15:
      v13 |= v18;
LABEL_16:
      v7 += 3;
      --v8;
      --v14;
    }
    while ( v14 );
    v5 = v17;
LABEL_18:
    ++v4;
  }
  while ( v4 <= 20 );
  result = v13;
  *a4 = v12;
  return result;
}
