// f1c  0x0051db31  size=208
_WORD *__usercall sub_51DB31@<eax>(int a1@<eax>, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // eax
  unsigned __int8 *v6; // edx
  _DWORD *v7; // ecx
  int v8; // ebx
  _WORD *result; // eax
  int v10; // edi
  _BYTE v11[256]; // [esp+Ch] [ebp-188h] BYREF
  _BYTE v12[128]; // [esp+10Ch] [ebp-88h] BYREF
  int v13; // [esp+18Ch] [ebp-8h]
  int v14; // [esp+190h] [ebp-4h]
  int v15; // [esp+19Ch] [ebp+8h]
  int v16; // [esp+1A0h] [ebp+Ch]
  int v17; // [esp+1A0h] [ebp+Ch]
  int v18; // [esp+1A4h] [ebp+10h]
  int v19; // [esp+1A4h] [ebp+10h]

  v18 = a4 >> 2;
  v16 = a3 >> 2;
  v14 = *(_DWORD *)(*(_DWORD *)(a2 + 420) + 24);
  v4 = a1 >> 3;
  v13 = 32 * v18 + 4;
  v5 = sub_51D897(a2, 32 * (a1 >> 3) + 2, 32 * v16 + 4, v13, (int)v11);
  sub_51DA17(a2, 32 * v16 + 4, 32 * v4 + 2, v13, v5, (int)v11, v12);
  v6 = v12;
  v15 = 2 * (4 * v18 + (v4 << 8));
  v7 = (_DWORD *)(v14 + 16 * v16);
  v17 = 4;
  do
  {
    v8 = v15;
    v19 = 8;
    do
    {
      result = (_WORD *)(v8 + *v7);
      v10 = 4;
      do
      {
        *result++ = *v6++ + 1;
        --v10;
      }
      while ( v10 );
      v8 += 64;
      --v19;
    }
    while ( v19 );
    ++v7;
    --v17;
  }
  while ( v17 );
  return result;
}
