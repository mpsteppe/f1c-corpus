// f1c  0x00586800  size=499
int __thiscall sub_586800(_DWORD *this, int j, int a3, char a4, int a5, int a6)
{
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // esi
  unsigned int v10; // edi
  unsigned __int16 *v11; // edx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // ebx
  _BYTE *v15; // eax
  char v16; // dl
  int v17; // eax
  int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // edi
  unsigned __int16 *v21; // edx
  int v22; // eax
  unsigned int v23; // ebx
  int v24; // ebp
  int v25; // ecx
  int v26; // eax
  unsigned int v27; // edi
  unsigned __int16 *v28; // edx
  int v29; // eax
  unsigned int v30; // ecx
  unsigned int v31; // ebx
  int v32; // ebp
  int v33; // edi
  int v34; // edx
  unsigned int v35; // ebx
  unsigned __int16 v36; // cx
  unsigned int v37; // edi
  int v38; // ebp
  _DWORD *v40; // [esp+10h] [ebp-10h]
  unsigned int v41; // [esp+14h] [ebp-Ch] BYREF
  int i; // [esp+18h] [ebp-8h]
  int v43; // [esp+1Ch] [ebp-4h]

  v7 = this[7];
  v8 = this[13];
  v9 = this + 5;
  v40 = this;
  v10 = *(unsigned __int16 *)(v7 + 4 * v8 + 2);
  v11 = (unsigned __int16 *)(v7 + 4 * v8);
  v12 = 0;
  v13 = 0;
  if ( (_WORD)v10 )
  {
    do
      v12 |= 1 << v13++;
    while ( v13 < v10 );
  }
  v14 = 0;
  v43 = j & v12;
  for ( i = *v11 + v10 - 1; v14 < v10; *v15 = v16 )
  {
    sub_585E80(i - v14, &v41, &j);
    v15 = (_BYTE *)(*v9 + v41);
    if ( ((1 << v14) & v43) != 0 )
      v16 = j | *v15;
    else
      v16 = ~(_BYTE)j & *v15;
    ++v14;
  }
  v17 = this[14];
  v18 = this[7];
  v19 = 0;
  v20 = *(unsigned __int16 *)(v18 + 4 * v17 + 2);
  v21 = (unsigned __int16 *)(v18 + 4 * v17);
  v22 = 0;
  if ( (_WORD)v20 )
  {
    do
      v22 |= 1 << v19++;
    while ( v19 < v20 );
  }
  v23 = 0;
  v24 = a3 & v22;
  for ( j = *v21 + v20 - 1; v23 < v20; ++v23 )
    sub_586F70(j - v23, ((1 << v23) & v24) != 0);
  v25 = v9[2];
  HIWORD(v27) = 0;
  v26 = v40[16];
  LOWORD(v27) = *(_WORD *)(v25 + 4 * v26 + 2);
  v28 = (unsigned __int16 *)(v25 + 4 * v26);
  v29 = 0;
  v30 = 0;
  if ( (_WORD)v27 )
  {
    do
      v29 |= 1 << v30++;
    while ( v30 < v27 );
  }
  v31 = 0;
  v32 = a5 & v29;
  for ( j = *v28 + v27 - 1; v31 < v27; ++v31 )
    sub_586F70(j - v31, ((1 << v31) & v32) != 0);
  j = a6;
  v33 = v40[17];
  sub_586F40(v33, &j);
  v34 = v9[2];
  v35 = 0;
  v36 = *(_WORD *)(v34 + 4 * v33);
  v37 = *(unsigned __int16 *)(v34 + 4 * v33 + 2);
  v38 = v36 + (unsigned __int16)v37 - 1;
  if ( (_WORD)v37 )
  {
    do
    {
      sub_586F70(v38 - v35, (j & (1 << v35)) != 0);
      ++v35;
    }
    while ( v35 < v37 );
  }
  return sub_586FA0(v40[15], a4 != 0);
}
