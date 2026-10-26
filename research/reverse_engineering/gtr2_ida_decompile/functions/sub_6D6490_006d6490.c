int __stdcall sub_6D6490(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int result; // eax
  _WORD *v9; // edi
  _DWORD *v10; // edx
  _WORD *v11; // eax
  int v12; // esi
  unsigned __int8 *v13; // ecx
  _WORD *v14; // eax
  __int16 v15; // bx
  __int16 v16; // bx
  __int16 v17; // bx
  __int16 v18; // bx
  __int16 v19; // bx
  unsigned __int8 *v20; // ecx
  __int16 v21; // bx
  __int16 v22; // bx
  __int16 v23; // bx
  __int16 v24; // bx
  __int16 v25; // bx
  unsigned __int8 *v26; // ecx
  __int16 v27; // bx
  __int16 v28; // bx
  __int16 v29; // bx
  __int16 v30; // bx
  __int16 v31; // bx
  unsigned __int8 *v32; // ecx
  __int16 v33; // bx
  __int16 v34; // bx
  __int16 v35; // bx
  __int16 v36; // bx
  __int16 v37; // bx
  __int16 *v38; // ebx
  _WORD *v39; // ecx
  char *v40; // edi
  int v41; // eax
  __int16 v42; // dx
  __int16 v43; // ax
  __int16 v44; // si
  __int16 v45; // si
  int v46; // eax
  __int16 v47; // ax
  __int16 v48; // dx
  __int16 v49; // ax
  __int16 v50; // si
  __int16 v51; // si
  int v52; // eax
  __int16 v53; // ax
  __int16 v54; // dx
  __int16 v55; // ax
  __int16 v56; // si
  __int16 v57; // si
  int v58; // eax
  __int16 v59; // ax
  __int16 v60; // dx
  __int16 v61; // ax
  __int16 v62; // si
  __int16 v63; // si
  int v64; // eax
  __int16 v65; // ax
  bool v66; // zf
  _WORD v67[64]; // [esp+0h] [ebp-84h] BYREF
  void (__stdcall *v68)(_WORD *); // [esp+80h] [ebp-4h]
  int v69; // [esp+8Ch] [ebp+8h]
  char *v70; // [esp+90h] [ebp+Ch]
  char *v71; // [esp+90h] [ebp+Ch]
  __int16 *v72; // [esp+94h] [ebp+10h]
  int v73; // [esp+98h] [ebp+14h]
  int v74; // [esp+9Ch] [ebp+18h]

  v7 = *(_DWORD *)(a1 + 368);
  v68 = *(void (__stdcall **)(_WORD *))(v7 + 8);
  result = *(_DWORD *)(v7 + 4 * *(_DWORD *)(a2 + 16) + 12);
  if ( a7 )
  {
    v74 = a3 + 4 * a5 + 8;
    v72 = (__int16 *)(result + 6);
    v9 = (_WORD *)(a4 + 2);
    v70 = (char *)v67 - a4;
    v73 = result - (_DWORD)v67;
    do
    {
      v10 = (_DWORD *)v74;
      v11 = v67;
      v12 = 2;
      do
      {
        v13 = (unsigned __int8 *)(a6 + *(v10 - 2));
        v14 = v11 + 6;
        *(v14 - 6) = *v13 - 128;
        v15 = *++v13;
        v14 += 5;
        *(v14 - 10) = v15 - 128;
        v16 = *++v13;
        v14 += 4;
        *(v14 - 13) = v16 - 128;
        v17 = *++v13;
        *(v14 - 12) = v17 - 128;
        v18 = *++v13;
        *(v14 - 11) = v18 - 128;
        v19 = *++v13;
        *(v14 - 10) = v19 - 128;
        *(v14 - 9) = v13[1] - 128;
        *(v14 - 8) = v13[2] - 128;
        v20 = (unsigned __int8 *)(a6 + *(v10 - 1));
        *(v14 - 7) = *v20 - 128;
        v21 = *++v20;
        *(v14 - 6) = v21 - 128;
        v22 = *++v20;
        *(v14 - 5) = v22 - 128;
        v23 = *++v20;
        *(v14 - 4) = v23 - 128;
        v24 = *++v20;
        *(v14 - 3) = v24 - 128;
        v25 = *++v20;
        *(v14 - 2) = v25 - 128;
        *(v14 - 1) = v20[1] - 128;
        *v14 = v20[2] - 128;
        v26 = (unsigned __int8 *)(a6 + *v10);
        v14 += 6;
        *(v14 - 5) = *v26 - 128;
        v27 = *++v26;
        v14 += 5;
        *(v14 - 9) = v27 - 128;
        v28 = *++v26;
        v14 += 5;
        *(v14 - 13) = v28 - 128;
        v29 = *++v26;
        *(v14 - 12) = v29 - 128;
        v30 = *++v26;
        *(v14 - 11) = v30 - 128;
        v31 = *++v26;
        *(v14 - 10) = v31 - 128;
        *(v14 - 9) = v26[1] - 128;
        *(v14 - 8) = v26[2] - 128;
        v32 = (unsigned __int8 *)(a6 + v10[1]);
        *(v14 - 7) = *v32 - 128;
        v33 = *++v32;
        *(v14 - 6) = v33 - 128;
        v34 = *++v32;
        *(v14 - 5) = v34 - 128;
        v35 = *++v32;
        *(v14 - 4) = v35 - 128;
        v36 = *++v32;
        *(v14 - 3) = v36 - 128;
        v37 = *++v32;
        *(v14 - 2) = v37 - 128;
        *(v14 - 1) = v32[1] - 128;
        *v14 = v32[2] - 128;
        v11 = v14 + 1;
        v10 += 4;
        --v12;
      }
      while ( v12 );
      v68(v67);
      v38 = v72;
      v39 = v9;
      v40 = v70;
      v41 = 0;
      v69 = 0;
      v71 = &v70[v73];
      do
      {
        v42 = *(v38 - 3);
        v43 = v67[v41];
        v44 = v42 >> 1;
        if ( v43 >= 0 )
        {
          v47 = v44 + v43;
          if ( v47 < v42 )
            LOWORD(v46) = 0;
          else
            LOWORD(v46) = v47 / v42;
        }
        else
        {
          v45 = v44 - v43;
          if ( v45 < v42 )
            LOWORD(v46) = 0;
          else
            v46 = -(v45 / v42);
        }
        *(v39 - 1) = v46;
        v48 = *(_WORD *)((char *)v39 + (_DWORD)v71);
        v49 = *(_WORD *)((char *)v39 + (_DWORD)v40);
        v50 = v48 >> 1;
        if ( v49 >= 0 )
        {
          v53 = v50 + v49;
          if ( v53 < v48 )
            LOWORD(v52) = 0;
          else
            LOWORD(v52) = v53 / v48;
        }
        else
        {
          v51 = v50 - v49;
          if ( v51 < v48 )
            LOWORD(v52) = 0;
          else
            v52 = -(v51 / v48);
        }
        v54 = *(v38 - 1);
        *v39 = v52;
        v55 = *(_WORD *)((char *)v39 + (_DWORD)v40 + 2);
        v56 = v54 >> 1;
        if ( v55 >= 0 )
        {
          v59 = v56 + v55;
          if ( v59 < v54 )
            LOWORD(v58) = 0;
          else
            LOWORD(v58) = v59 / v54;
        }
        else
        {
          v57 = v56 - v55;
          if ( v57 < v54 )
            LOWORD(v58) = 0;
          else
            v58 = -(v57 / v54);
        }
        v60 = *v38;
        v39[1] = v58;
        v61 = *(_WORD *)((char *)v39 + (_DWORD)v40 + 4);
        v62 = v60 >> 1;
        if ( v61 >= 0 )
        {
          v65 = v62 + v61;
          if ( v65 < v60 )
            LOWORD(v64) = 0;
          else
            LOWORD(v64) = v65 / v60;
        }
        else
        {
          v63 = v62 - v61;
          if ( v63 < v60 )
            LOWORD(v64) = 0;
          else
            v64 = -(v63 / v60);
        }
        v39[2] = v64;
        v41 = v69 + 4;
        v39 += 4;
        v38 += 4;
        v69 += 4;
      }
      while ( v69 < 64 );
      v70 = v40 - 128;
      v9 = v39;
      result = a7 - 1;
      v66 = a7 == 1;
      a6 += 8;
      --a7;
    }
    while ( !v66 );
  }
  return result;
}
