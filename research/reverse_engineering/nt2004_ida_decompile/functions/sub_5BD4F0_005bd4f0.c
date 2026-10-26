int __fastcall sub_5BD4F0(int a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 *v4; // esi
  int v5; // edi
  int v6; // ebp
  int v7; // eax
  int v9; // edi
  int v10; // eax
  int v11; // ecx
  int v12; // [esp+10h] [ebp-Ch]
  _DWORD v13[2]; // [esp+14h] [ebp-8h] BYREF
  int v14; // [esp+20h] [ebp+4h]

  v4 = a2 + 1;
  v5 = *a2;
  v6 = a3 - 1;
  v12 = v5;
  if ( *(_DWORD *)(a1 + 8) )
    sub_5BC8A0((void **)a1);
  v7 = sub_5BE100(0);
  *(_DWORD *)(a1 + 8) = v7;
  if ( !v7 )
    return 5;
  v14 = 0;
  if ( v5 <= 0 )
    return 0;
  while ( v6 >= 2 )
  {
    v9 = sub_5BC130((int)(v4 + 1), v6 - 1);
    if ( v9 == -1 )
      break;
    v13[1] = *v4;
    v10 = sub_5BDAD0(a1);
    v11 = *(_DWORD *)(a1 + 8);
    v13[0] = v10;
    sub_5BE1C0(v11, v13);
    v4 += v9 + 1;
    v6 += -1 - v9;
    if ( ++v14 >= v12 )
      return 0;
  }
  return 4;
}
