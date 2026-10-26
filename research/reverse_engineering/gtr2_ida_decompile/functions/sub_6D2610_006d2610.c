int __usercall sub_6D2610@<eax>(int a1@<eax>)
{
  _DWORD *v2; // edi
  int v3; // eax
  int (__stdcall **v4)(int, int, int); // ecx
  int v5; // eax
  int (__stdcall **v6)(int, int, int); // edx
  int v7; // eax
  int (__stdcall **v8)(int, int, int); // ecx
  int v9; // eax
  int (__stdcall **v10)(int, int, int); // edx
  int v11; // eax
  int (__stdcall **v12)(int, int, int); // ecx
  int v13; // eax
  int (__stdcall **v14)(int, int, int); // edx
  int v15; // eax
  unsigned int *v16; // ecx
  int v17; // esi
  int v18; // ebx
  int v19; // edi
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int result; // eax
  int v30; // [esp+Ch] [ebp-5Ch]
  int v31; // [esp+10h] [ebp-58h]
  int v32; // [esp+14h] [ebp-54h]
  int v33; // [esp+18h] [ebp-50h]
  int v34; // [esp+1Ch] [ebp-4Ch]
  int v35; // [esp+20h] [ebp-48h]
  int v36; // [esp+24h] [ebp-44h]
  int v37; // [esp+28h] [ebp-40h]
  int v38; // [esp+2Ch] [ebp-3Ch]
  int v39; // [esp+30h] [ebp-38h]
  int v40; // [esp+34h] [ebp-34h]
  int v41; // [esp+38h] [ebp-30h]
  int v42; // [esp+3Ch] [ebp-2Ch]
  int v43; // [esp+40h] [ebp-28h]
  int v44; // [esp+44h] [ebp-24h]
  int v45; // [esp+48h] [ebp-20h]
  int v46; // [esp+4Ch] [ebp-1Ch]
  int v47; // [esp+50h] [ebp-18h]
  int v48; // [esp+54h] [ebp-14h]
  int v49; // [esp+58h] [ebp-10h]
  int v50; // [esp+5Ch] [ebp-Ch]
  int v51; // [esp+60h] [ebp-8h]
  int v52; // [esp+64h] [ebp-4h]

  v2 = *(_DWORD **)(a1 + 460);
  v3 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v4 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v2[6] = v3;
  v5 = (*v4)(a1, 1, 1024);
  v6 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v2[7] = v5;
  v2[8] = (*v6)(a1, 1, 1024);
  v7 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v8 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v2[9] = v7;
  v9 = (*v8)(a1, 1, 1024);
  v10 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v2[10] = v9;
  v2[11] = (*v10)(a1, 1, 1024);
  v11 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v12 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v2[12] = v11;
  v13 = (*v12)(a1, 1, 1024);
  v14 = *(int (__stdcall ***)(int, int, int))(a1 + 4);
  v2[13] = v13;
  v2[14] = (*v14)(a1, 1, 1024);
  v15 = (**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 1024);
  v16 = (unsigned int *)v2[7];
  v17 = 65153;
  v2[15] = v15;
  v45 = -4859105;
  v46 = -280481;
  v47 = -2184161;
  v48 = -5677025;
  v49 = -1465313;
  v50 = -587489;
  v51 = -1577633;
  v52 = -4939745;
  v18 = -4313057;
  v38 = 65153;
  v39 = 65153;
  v40 = 65153;
  v41 = 65153;
  v42 = 65153;
  v37 = v2[6] - (_DWORD)v16;
  v36 = v2[8] - (_DWORD)v16;
  v35 = v2[9] - (_DWORD)v16;
  v34 = v2[10] - (_DWORD)v16;
  v33 = v2[11] - (_DWORD)v16;
  v32 = v2[12] - (_DWORD)v16;
  v30 = v2[14] - (_DWORD)v16;
  v43 = 65153;
  v44 = 65153;
  v31 = v2[13] - (_DWORD)v16;
  v19 = v15 - (_DWORD)v16;
  do
  {
    if ( v17 <= 22337 )
      v20 = 22464 - v18 / 63;
    else
      v20 = v17;
    *(unsigned int *)((char *)v16 + v37) = v20;
    if ( v17 <= 22337 )
      v21 = 25728 - v52 / 63;
    else
      v21 = v44;
    *v16 = (unsigned int)(65793 * v21) >> 16;
    if ( v17 <= 22337 )
      v22 = 47232 - v51 / 63;
    else
      v22 = v43;
    *(unsigned int *)((char *)v16 + v36) = (unsigned int)(65793 * v22) >> 16;
    if ( v17 <= 22337 )
      v23 = 65280 - v50 / 63;
    else
      v23 = 65153;
    *(unsigned int *)((char *)v16 + v35) = (unsigned int)(65793 * v23) >> 16;
    if ( v17 <= 22337 )
      v24 = 60672 - v49 / 63;
    else
      v24 = v42;
    *(unsigned int *)((char *)v16 + v34) = (unsigned int)(65793 * v24) >> 16;
    if ( v17 <= 22337 )
      v25 = 29568 - v48 / 63;
    else
      v25 = v41;
    *(unsigned int *)((char *)v16 + v33) = (unsigned int)(65793 * v25) >> 16;
    if ( v17 <= 22337 )
      v26 = 39936 - v47 / 63;
    else
      v26 = v40;
    *(unsigned int *)((char *)v16 + v32) = (unsigned int)(65793 * v26) >> 16;
    *(unsigned int *)((char *)v16 + v31) = (unsigned int)(65793 * (v17 <= 22337 ? 65280 : 65153)) >> 16;
    if ( v17 <= 22337 )
      v27 = 63936 - v46 / 63;
    else
      v27 = v39;
    *(unsigned int *)((char *)v16 + v30) = (unsigned int)(65793 * v27) >> 16;
    if ( v17 <= 22337 )
      v28 = 32448 - v45 / 63;
    else
      v28 = v38;
    *(unsigned int *)((char *)v16 + v19) = (unsigned int)(65793 * v28) >> 16;
    v44 -= 206;
    v52 += 25728;
    v43 -= 94;
    v51 += 8217;
    v50 += 3060;
    v42 -= 24;
    v49 += 7632;
    v41 -= 186;
    v48 += 29568;
    v40 -= 132;
    v47 += 11376;
    v39 -= 7;
    v46 += 1461;
    v17 -= 223;
    result = v45 + 25308;
    v18 += 22464;
    ++v16;
    v38 -= 171;
    v45 += 25308;
  }
  while ( v17 >= 8288 );
  return result;
}
