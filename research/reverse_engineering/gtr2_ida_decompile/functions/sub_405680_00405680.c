_BYTE *__thiscall sub_405680(_DWORD *this, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ecx
  void *v7; // edx
  unsigned int v8; // ecx
  const void *v9; // esi
  _BYTE *result; // eax
  int v11; // [esp+0h] [ebp-24h] BYREF
  _DWORD *v12; // [esp+10h] [ebp-14h]
  int *v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+20h] [ebp-4h]
  void *v15; // [esp+2Ch] [ebp+8h]

  v3 = a2 | 0xF;
  v4 = this;
  v13 = &v11;
  v12 = this;
  if ( (a2 | 0xF) == 0xFFFFFFFF )
  {
    v3 = a2;
  }
  else
  {
    v5 = this[6];
    v6 = v5 >> 1;
    if ( v3 / 3 < v5 >> 1 && v5 <= -2 - v6 )
      v3 = v6 + v5;
  }
  v14 = 0;
  v7 = operator new(v3 + 1);
  v15 = v7;
  v8 = a3;
  if ( a3 )
  {
    if ( v4[6] < 0x10u )
      v9 = v4 + 1;
    else
      v9 = (const void *)v4[1];
    qmemcpy(v7, v9, a3);
    v4 = v12;
    v8 = a3;
  }
  if ( v4[6] >= 0x10u )
  {
    j__free((void *)v4[1]);
    v7 = v15;
    v8 = a3;
  }
  result = v4 + 1;
  *((_BYTE *)v4 + 4) = 0;
  v4[1] = v7;
  v4[6] = v3;
  v4[5] = v8;
  if ( v3 >= 0x10 )
    result = v7;
  result[v8] = 0;
  return result;
}
