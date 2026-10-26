int __usercall sub_6D8BD0@<eax>(int *a1@<esi>)
{
  int v1; // eax
  int *v2; // edx
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  _BYTE *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // ebx
  int *v13; // edx
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  unsigned int v19; // ebx
  int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // edx
  int v23; // eax
  bool v24; // zf
  int v25; // eax
  _DWORD *v26; // eax
  int *v27; // ebx
  int v28; // eax
  signed int v29; // edi
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // edx
  int v34; // eax
  _DWORD *v35; // ebx
  _DWORD *v36; // edi
  int v37; // eax
  int v38; // ecx
  _DWORD *v39; // eax
  int v40; // eax
  int v41; // edi
  int result; // eax
  int *v43; // ebx
  int v44; // eax
  int v45; // eax
  _BYTE v46[2560]; // [esp+8h] [ebp-A48h] BYREF
  _DWORD v47[10]; // [esp+A08h] [ebp-48h] BYREF
  unsigned int v48; // [esp+A30h] [ebp-20h]
  unsigned int v49; // [esp+A34h] [ebp-1Ch]
  signed int v50; // [esp+A38h] [ebp-18h]
  int v51; // [esp+A3Ch] [ebp-14h]
  _DWORD *v52; // [esp+A40h] [ebp-10h]
  _DWORD *v53; // [esp+A44h] [ebp-Ch]
  int *v54; // [esp+A48h] [ebp-8h]
  int v55; // [esp+A4Ch] [ebp-4h]

  if ( a1[42] <= 0 )
  {
    v1 = *a1;
    *(_DWORD *)(v1 + 20) = 19;
    *(_DWORD *)(v1 + 24) = 0;
    (*(void (__stdcall **)(int *))v1)(a1);
  }
  v2 = (int *)a1[43];
  v24 = v2[5] == 0;
  v54 = v2;
  if ( v24 && v2[6] == 63 )
  {
    v3 = a1[15];
    a1[59] = 0;
    if ( v3 <= 0 )
      goto LABEL_10;
    v4 = v3;
    v5 = 0;
    v6 = v47;
  }
  else
  {
    v7 = a1[15];
    a1[59] = 1;
    if ( v7 <= 0 )
      goto LABEL_10;
    v4 = ((unsigned int)byte_FFFFFF & v7) << 6;
    v5 = -1;
    v6 = v46;
  }
  memset32(v6, v5, v4);
LABEL_10:
  v8 = a1[42];
  v9 = 1;
  v55 = 1;
  if ( v8 >= 1 )
  {
    while ( 1 )
    {
      v10 = *v2;
      v53 = (_DWORD *)*v2;
      if ( (int)v53 <= 0 || v10 > 4 )
      {
        v11 = *a1;
        *(_DWORD *)(v11 + 20) = 26;
        *(_DWORD *)(v11 + 24) = v10;
        *(_DWORD *)(v11 + 28) = 4;
        (*(void (__stdcall **)(int *))v11)(a1);
      }
      v12 = 0;
      if ( (int)v53 <= 0 )
      {
        v13 = v54;
      }
      else
      {
        do
        {
          v13 = v54;
          v14 = v54[v12 + 1];
          if ( v14 < 0 || v14 >= a1[15] )
          {
            v15 = *a1;
            v16 = v55;
            *(_DWORD *)(v15 + 20) = 19;
            *(_DWORD *)(v15 + 24) = v16;
            (*(void (__stdcall **)(int *))v15)(a1);
            v13 = v54;
          }
          if ( v12 > 0 && v14 <= v13[v12] )
          {
            v17 = *a1;
            v18 = v55;
            *(_DWORD *)(v17 + 20) = 19;
            *(_DWORD *)(v17 + 24) = v18;
            (*(void (__stdcall **)(int *))v17)(a1);
            v13 = v54;
          }
          ++v12;
        }
        while ( v12 < (int)v53 );
        v9 = v55;
      }
      v24 = a1[59] == 0;
      v19 = v13[5];
      v20 = v13[6];
      v21 = v13[7];
      v22 = v13[8];
      v50 = v19;
      v51 = v20;
      v49 = v21;
      v48 = v22;
      if ( v24 )
      {
        if ( v19 || v20 != 63 || v21 || v22 )
        {
          v34 = *a1;
          *(_DWORD *)(v34 + 20) = 17;
          *(_DWORD *)(v34 + 24) = v9;
          (*(void (__stdcall **)(int *))v34)(a1);
        }
        if ( (int)v53 > 0 )
        {
          v35 = v54 + 1;
          v52 = v53;
          do
          {
            v36 = &v47[*v35];
            if ( *v36 )
            {
              v37 = *a1;
              v38 = v55;
              *(_DWORD *)(v37 + 20) = 19;
              *(_DWORD *)(v37 + 24) = v38;
              (*(void (__stdcall **)(int *))v37)(a1);
            }
            ++v35;
            v39 = (_DWORD *)((char *)v52 - 1);
            v24 = v52 == (_DWORD *)1;
            *v36 = 1;
            v52 = v39;
          }
          while ( !v24 );
          v9 = v55;
        }
      }
      else
      {
        if ( v19 >= 0x40 || v20 < (int)v19 || v20 >= 64 || v21 > 0xA || v22 > 0xA )
        {
          v23 = *a1;
          *(_DWORD *)(v23 + 20) = 17;
          *(_DWORD *)(v23 + 24) = v9;
          (*(void (__stdcall **)(int *))v23)(a1);
          v20 = v51;
        }
        if ( v19 )
          v24 = v53 == (_DWORD *)1;
        else
          v24 = v20 == 0;
        if ( !v24 )
        {
          v25 = *a1;
          *(_DWORD *)(v25 + 20) = 17;
          *(_DWORD *)(v25 + 24) = v9;
          (*(void (__stdcall **)(int *))v25)(a1);
        }
        v26 = v53;
        if ( (int)v53 > 0 )
        {
          v53 = v54 + 1;
          v52 = v26;
          while ( 1 )
          {
            v27 = (int *)&v46[256 * *v53];
            if ( v50 && *v27 < 0 )
            {
              v28 = *a1;
              *(_DWORD *)(v28 + 20) = 17;
              *(_DWORD *)(v28 + 24) = v9;
              (*(void (__stdcall **)(int *))v28)(a1);
            }
            v29 = v50;
            if ( v50 <= v51 )
              break;
LABEL_52:
            v9 = v55;
            v24 = v52 == (_DWORD *)1;
            ++v53;
            v52 = (_DWORD *)((char *)v52 - 1);
            if ( v24 )
              goto LABEL_65;
          }
          while ( 2 )
          {
            v30 = v27[v29];
            if ( v30 >= 0 )
            {
              if ( v49 != v30 || v48 != v49 - 1 )
              {
                v31 = *a1;
                v33 = v55;
                *(_DWORD *)(v31 + 20) = 17;
                *(_DWORD *)(v31 + 24) = v33;
LABEL_50:
                (*(void (__stdcall **)(int *))v31)(a1);
              }
            }
            else if ( v49 )
            {
              v31 = *a1;
              v32 = v55;
              *(_DWORD *)(v31 + 20) = 17;
              *(_DWORD *)(v31 + 24) = v32;
              goto LABEL_50;
            }
            v27[v29++] = v48;
            if ( v29 > v51 )
              goto LABEL_52;
            continue;
          }
        }
      }
LABEL_65:
      v40 = a1[42];
      ++v9;
      v54 += 9;
      v55 = v9;
      if ( v9 > v40 )
        break;
      v2 = v54;
    }
  }
  v41 = 0;
  result = a1[15];
  if ( a1[59] )
  {
    if ( result > 0 )
    {
      v43 = (int *)v46;
      do
      {
        if ( *v43 < 0 )
        {
          v44 = *a1;
          *(_DWORD *)(v44 + 20) = 45;
          (*(void (__stdcall **)(int *))v44)(a1);
        }
        result = a1[15];
        ++v41;
        v43 += 64;
      }
      while ( v41 < result );
    }
  }
  else if ( result > 0 )
  {
    do
    {
      if ( !v47[v41] )
      {
        v45 = *a1;
        *(_DWORD *)(v45 + 20) = 45;
        (*(void (__stdcall **)(int *))v45)(a1);
      }
      result = a1[15];
      ++v41;
    }
    while ( v41 < result );
  }
  return result;
}
