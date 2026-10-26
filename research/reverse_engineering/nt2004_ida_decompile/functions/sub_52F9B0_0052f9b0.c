int __thiscall sub_52F9B0(int this, int a2, int a3)
{
  int v3; // esi
  int v4; // ebp
  int v6; // ecx
  int v7; // eax
  bool v8; // cc
  int v9; // edx
  int v10; // edx
  unsigned int v11; // eax
  char *v12; // esi
  char *v13; // edi
  int v15; // [esp+Ch] [ebp-8h]
  int v16; // [esp+10h] [ebp-4h]

  v3 = a3;
  v4 = 0;
  v15 = 0;
  if ( a3 > 0 )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(this + 9448);
      v7 = *(_DWORD *)(this + 9372);
      v8 = v6 < v7;
      v16 = 0;
      if ( v6 != v7 )
        goto LABEL_9;
      if ( v3 - v4 < v7 )
        break;
      if ( sub_52F570((_BYTE *)this, a2 + v4) )
      {
        printf("mpeg fail 1 %d\n", *(_DWORD *)(this + 9372));
        memset((void *)(a2 + v4), 0, *(_DWORD *)(this + 9372));
      }
      else
      {
        v15 += *(_DWORD *)(this + 9372);
      }
      v4 += *(_DWORD *)(this + 9372);
      ++*(_DWORD *)(this + 9444);
LABEL_17:
      if ( v4 >= v3 )
        goto LABEL_18;
    }
    v8 = v6 < v7;
LABEL_9:
    if ( !v8 )
    {
      v16 = sub_52F570((_BYTE *)this, this + 4676);
      v9 = *(_DWORD *)(this + 9444) + 1;
      *(_DWORD *)(this + 9448) = 0;
      *(_DWORD *)(this + 9444) = v9;
      if ( v16 )
      {
        printf("mpeg fail 2 %d\n", *(_DWORD *)(this + 9372));
        memset((void *)(this + 4676), 0, *(_DWORD *)(this + 9372));
      }
    }
    v10 = *(_DWORD *)(this + 9448);
    v11 = *(_DWORD *)(this + 9372) - v10;
    if ( (int)v11 > v3 - v4 )
      v11 = v3 - v4;
    v12 = (char *)(v10 + this + 4676);
    qmemcpy((void *)(a2 + v4), v12, 4 * (v11 >> 2));
    v13 = (char *)(a2 + v4 + 4 * (v11 >> 2));
    v4 += v11;
    qmemcpy(v13, &v12[4 * (v11 >> 2)], v11 & 3);
    *(_DWORD *)(this + 9448) += v11;
    if ( !v16 )
      v15 += v11;
    v3 = a3;
    goto LABEL_17;
  }
LABEL_18:
  *(_DWORD *)(this + 9396) = *(_DWORD *)(this + 9448) + *(_DWORD *)(this + 9356) * (*(_DWORD *)(this + 9444) - 1);
  return v15;
}
