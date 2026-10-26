// f1c  0x00586aa0  size=486
int __thiscall sub_586AA0(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // esi
  int v4; // ecx
  unsigned int v5; // edi
  unsigned __int16 *v6; // edx
  int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  _BYTE *v10; // eax
  char v11; // dl
  int v12; // eax
  int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // edi
  unsigned __int16 *v16; // eax
  int v17; // edx
  unsigned int v18; // ebx
  int v19; // eax
  int v20; // edx
  unsigned int v21; // ecx
  unsigned int v22; // edi
  unsigned __int16 *v23; // eax
  int v24; // edx
  unsigned int v25; // ebx
  int v26; // edi
  int v27; // eax
  unsigned int v28; // ebx
  unsigned __int16 v29; // cx
  unsigned int v30; // edi
  int result; // eax
  char v32; // [esp+13h] [ebp-Dh] BYREF
  unsigned int v33; // [esp+14h] [ebp-Ch] BYREF
  int i; // [esp+18h] [ebp-8h]
  int j; // [esp+1Ch] [ebp-4h]

  HIWORD(v5) = 0;
  v2 = this[13];
  v3 = this + 5;
  *this = 0;
  v4 = this[7];
  LOWORD(v5) = *(_WORD *)(v4 + 4 * v2 + 2);
  v6 = (unsigned __int16 *)(v4 + 4 * v2);
  v7 = 0;
  v8 = 0;
  if ( (_WORD)v5 )
  {
    do
      v7 |= 1 << v8++;
    while ( v8 < v5 );
  }
  v9 = 0;
  j = v7 & 1;
  for ( i = *v6 + v5 - 1; v9 < v5; *v10 = v11 )
  {
    sub_585E80(i - v9, &v33, &v32);
    v10 = (_BYTE *)(*v3 + v33);
    if ( ((1 << v9) & j) != 0 )
      v11 = v32 | *v10;
    else
      v11 = ~v32 & *v10;
    ++v9;
  }
  v12 = this[14];
  v13 = v3[2];
  v14 = 0;
  v15 = *(unsigned __int16 *)(v13 + 4 * v12 + 2);
  v16 = (unsigned __int16 *)(v13 + 4 * v12);
  v17 = 0;
  if ( (_WORD)v15 )
  {
    do
      v17 |= 1 << v14++;
    while ( v14 < v15 );
  }
  v18 = 0;
  for ( j = *v16 + v15 - 1; v18 < v15; ++v18 )
    sub_586F70(j - v18, 0);
  v19 = this[15];
  v20 = v3[2];
  v21 = 0;
  v22 = *(unsigned __int16 *)(v20 + 4 * v19 + 2);
  v23 = (unsigned __int16 *)(v20 + 4 * v19);
  v24 = 0;
  if ( (_WORD)v22 )
  {
    do
      v24 |= 1 << v21++;
    while ( v21 < v22 );
  }
  v25 = 0;
  for ( j = *v23 + v22 - 1; v25 < v22; ++v25 )
    sub_586F70(j - v25, 0);
  v26 = this[16];
  v33 = 0;
  sub_586F40(v26, &v33);
  v27 = v3[2];
  v28 = 0;
  v29 = *(_WORD *)(v27 + 4 * v26);
  v30 = *(unsigned __int16 *)(v27 + 4 * v26 + 2);
  j = v29 + (unsigned __int16)v30 - 1;
  if ( (_WORD)v30 )
  {
    do
    {
      sub_586F70(j - v28, ((1 << v28) & v33) != 0);
      ++v28;
    }
    while ( v28 < v30 );
  }
  sub_586FA0(this[17], 0);
  sub_587500(this + 2);
  result = 0;
  this[18] = 0;
  this[19] = 0;
  this[20] = 0;
  return result;
}
