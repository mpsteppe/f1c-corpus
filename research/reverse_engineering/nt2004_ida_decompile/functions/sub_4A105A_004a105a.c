int __usercall sub_4A105A@<eax>(int a1@<ecx>, _DWORD *a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v10; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h] BYREF

  *a2 -= a2;
  if ( !*(_BYTE *)(a1 + 308) || !*(_BYTE *)(a1 + 309) )
    return 0;
  sub_4AE870(&v11, &v10);
  v3 = v10;
  v4 = *(_DWORD *)(a1 + 300) - v10;
  if ( v4 > 10 )
  {
    v5 = *(_DWORD *)(a1 + 292) + 1;
LABEL_7:
    *(_DWORD *)(a1 + 292) = v5;
    goto LABEL_8;
  }
  if ( v4 < -10 )
  {
    v5 = *(_DWORD *)(a1 + 292) - 1;
    goto LABEL_7;
  }
LABEL_8:
  v6 = *(_DWORD *)(a1 + 292);
  if ( v6 >= 0 )
  {
    v7 = *(_DWORD *)(a1 + 288) - *(_DWORD *)(a1 + 304) / 2;
    if ( v6 > v7 )
      *(_DWORD *)(a1 + 292) = v7;
  }
  else
  {
    *(_DWORD *)(a1 + 292) = 0;
  }
  v8 = v11;
  *(_DWORD *)(a1 + 300) = v3;
  *(_DWORD *)(a1 + 296) = v8;
  return 0;
}
