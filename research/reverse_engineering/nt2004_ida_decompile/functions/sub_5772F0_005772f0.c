char __thiscall sub_5772F0(int this, char *a2, int *a3)
{
  unsigned __int16 v4; // ax
  char *v5; // esi
  char *v6; // ebx
  unsigned int v7; // eax
  char *v8; // esi
  char v9; // dl
  unsigned int v10; // ecx
  char *v11; // edi
  char *v12; // ebx
  unsigned int v14; // [esp+Ch] [ebp-8h] BYREF
  char *v15; // [esp+10h] [ebp-4h] BYREF

  v4 = sub_5772E0((_DWORD *)this);
  if ( v4 > *a3 )
    return 0;
  v5 = a2;
  v15 = 0;
  *(_WORD *)a2 = v4;
  v6 = a2 + 2;
  v14 = *a3 - 2;
  if ( (unsigned __int8)sub_577610(&v15, &v14) )
  {
    v7 = v14;
    v8 = v15;
    v9 = v14;
    v10 = v14 >> 2;
    qmemcpy(v6, v15, 4 * (v14 >> 2));
    v11 = &v6[4 * v10];
    v6 += v7;
    qmemcpy(v11, &v8[4 * v10], v9 & 3);
    v5 = a2;
  }
  *(_DWORD *)v6 = *(_DWORD *)(this + 16);
  v12 = v6 + 4;
  *(_DWORD *)v12 = *(_DWORD *)(this + 20);
  v12 += 4;
  *v12 = *(_BYTE *)(this + 24);
  *a3 = v12 - v5 + 1;
  return 1;
}
