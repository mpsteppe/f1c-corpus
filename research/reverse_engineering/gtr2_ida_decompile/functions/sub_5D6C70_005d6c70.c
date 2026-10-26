void __usercall sub_5D6C70(int a1@<ecx>, int a2@<esi>)
{
  int v3; // edi
  _DWORD *v4; // ebp
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  int v12; // ebp
  int v13; // edi
  _DWORD *v14; // eax
  _DWORD *v15; // ecx
  int v16; // ecx
  int v17; // edi
  int v18; // eax
  int v19; // esi
  _DWORD *v20; // eax
  bool v21; // cc
  int v22; // [esp-10h] [ebp-90h]
  int v23; // [esp-Ch] [ebp-8Ch]
  int v24; // [esp+0h] [ebp-80h]
  int v25; // [esp+0h] [ebp-80h]
  int v26; // [esp+4h] [ebp-7Ch]
  int v27; // [esp+8h] [ebp-78h]
  int *v28; // [esp+Ch] [ebp-74h]
  int v29; // [esp+10h] [ebp-70h]
  int v30; // [esp+14h] [ebp-6Ch]
  int v31; // [esp+18h] [ebp-68h]
  int v32; // [esp+1Ch] [ebp-64h]
  int v33; // [esp+20h] [ebp-60h]
  _DWORD *v34; // [esp+24h] [ebp-5Ch]
  _DWORD v35[21]; // [esp+2Ch] [ebp-54h] BYREF

  v3 = 0;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  sub_4F14D0(v24);
  sub_5A8D10(*(void **)(a1 + 20));
  *(_DWORD *)(a1 + 20) = 0;
  if ( *(_DWORD *)(a1 + 4) )
  {
    v4 = 0;
    v34 = 0;
    v35[0] = 0;
    v35[20] = 0;
    v5 = sub_5C2B80();
    v6 = 0;
    v29 = v5;
    v31 = *(_DWORD *)(*(_DWORD *)(a1 + 4) + 36);
    v26 = 0;
    if ( v31 > 0 )
    {
      v22 = a2;
      while ( 1 )
      {
        v30 = *(_DWORD *)(*(_DWORD *)(v5 + 12) + 8 * v6 + 4);
        v25 = 0;
        if ( v30 > 0 )
          break;
LABEL_21:
        v26 = ++v6;
        if ( v6 >= v31 )
          goto LABEL_22;
      }
      while ( 1 )
      {
        v7 = *(_DWORD *)(*(_DWORD *)(v5 + 12) + 8 * v6);
        v8 = *(_DWORD *)(v5 + 24);
        v9 = 3 * (v25 + v7);
        v10 = *(_DWORD *)(v8 + 4 * v9);
        v28 = (int *)(v8 + 4 * v9);
        v11 = 0;
        v27 = v10;
        if ( v3 > 0 )
        {
          while ( v4[v11] != v10 )
          {
            if ( ++v11 >= v3 )
              goto LABEL_11;
          }
          v12 = v11;
          if ( v11 != -1 )
            goto LABEL_20;
          v4 = v34;
        }
LABEL_11:
        v13 = v3 + 1;
        v32 = v13;
        if ( v33 < v13 )
        {
          sub_4F14D0(v22);
          v14 = sub_5A8CF0(v4, 4 * (v13 + 1), 2, 16, 2);
          v10 = v27;
          v34 = v14;
          v33 = v13 + 1;
          v4 = v14;
        }
        v15 = &v4[v13 - 1];
        if ( v15 )
          *v15 = v10;
        v16 = *(_DWORD *)(a1 + 16);
        v12 = v13 - 1;
        v17 = *v28;
        v18 = *(_DWORD *)(a1 + 12) + 1;
        v35[0] = 1065353216;
        memset(&v35[1], 0, 16);
        v35[5] = 1065353216;
        memset(&v35[6], 0, 16);
        v35[10] = 1065353216;
        memset(&v35[11], 0, 16);
        v35[15] = 1065353216;
        *(_DWORD *)(a1 + 12) = v18;
        if ( v16 < v18 )
        {
          v19 = v18 + 1;
          sub_4F14D0(v22);
          *(_DWORD *)(a1 + 20) = sub_5A8CF0(*(void **)(a1 + 20), 68 * v19, 2, 16, 2);
          *(_DWORD *)(a1 + 16) = v19;
        }
        v20 = (_DWORD *)(*(_DWORD *)(a1 + 20) + 68 * (*(_DWORD *)(a1 + 12) - 1));
        if ( v20 )
        {
          *v20 = v17;
          qmemcpy(v20 + 1, v35, 0x40u);
        }
        v3 = v32;
LABEL_20:
        v28[2] = v12;
        v4 = v34;
        v21 = v25 + 1 < v30;
        v5 = v29;
        ++v25;
        v6 = v26;
        if ( !v21 )
          goto LABEL_21;
      }
    }
LABEL_22:
    sub_4F14D0(3);
    sub_5A8D10(v4);
    v35[18] = -1;
    sub_4F14D0(v23);
    sub_5A8D10(0);
  }
}
