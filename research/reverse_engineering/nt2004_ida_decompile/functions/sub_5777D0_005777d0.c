int __thiscall sub_5777D0(int this, char *a2)
{
  int v3; // eax
  int result; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  unsigned __int8 v9; // [esp+Ch] [ebp-10h]
  const void *v10; // [esp+10h] [ebp-Ch]
  char v11; // [esp+14h] [ebp-8h]
  unsigned int v12; // [esp+18h] [ebp-4h]

  v3 = sub_576B10(a2);
  v11 = v3;
  if ( v3 > 255 )
    return sub_5753F0(*(_DWORD **)(this + 1044), (int)a2);
  v10 = (const void *)*((_DWORD *)a2 + 5);
  v9 = (*((_DWORD *)a2 + 9) >> 3) + ((*((_DWORD *)a2 + 9) & 7) != 0);
  v12 = (unsigned __int8)v3;
  v5 = *(_DWORD *)(*(_DWORD *)(this + 1044) + 128);
  if ( v9 + (unsigned __int8)v3 + sub_577920(this) >= v5 )
    sub_577940(0);
  *(_BYTE *)(*(_DWORD *)(this + 1024) + this) = v9;
  v6 = *(_DWORD *)(this + 1024) + 1;
  *(_DWORD *)(this + 1024) = v6;
  qmemcpy((void *)(v6 + this), v10, v9);
  v7 = v9 + *(_DWORD *)(this + 1024);
  *(_DWORD *)(this + 1024) = v7;
  *(_BYTE *)(v7 + this) = v11;
  ++*(_DWORD *)(this + 1024);
  qmemcpy((void *)(this + *(_DWORD *)(this + 1024)), (const void *)sub_576B20(a2), v12);
  v8 = *(_DWORD *)(this + 1032);
  *(_DWORD *)(this + 1024) += v12;
  if ( !v8 )
    *(_DWORD *)(this + 1036) = sub_576E70(a2);
  result = *(_DWORD *)(this + 1032) + 1;
  *(_DWORD *)(this + 1032) = result;
  return result;
}
