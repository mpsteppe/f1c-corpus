int __userpurge sub_64514D@<eax>(int *a1@<ebx>, int a2, void (__stdcall *a3)(char *, float *, float *, int), int a4)
{
  int v4; // esi
  int v5; // eax
  int v6; // ebx
  void *v7; // eax
  void *v8; // esi
  int v9; // eax
  int v10; // eax
  int v11; // esi
  double v12; // st7
  int v13; // eax
  int v14; // esi
  double v15; // st7
  char *v16; // ebx
  char *v17; // ebx
  int v18; // ebx
  int v19; // ebx
  int v20; // eax
  int v21; // esi
  double v22; // st7
  char *v23; // ebx
  int v24; // ebx
  int v25; // eax
  int v26; // esi
  double v27; // st7
  char *v28; // ebx
  int v29; // ebx
  int v30; // eax
  int v31; // esi
  double v32; // st7
  char *v33; // ebx
  int v34; // ebx
  int v35; // eax
  int v36; // esi
  double v37; // st7
  char *v38; // ebx
  int v39; // ebx
  _BYTE v42[24]; // [esp+8h] [ebp-E8h] BYREF
  int v43; // [esp+20h] [ebp-D0h]
  _BYTE v44[24]; // [esp+28h] [ebp-C8h] BYREF
  int v45; // [esp+40h] [ebp-B0h]
  _BYTE v46[84]; // [esp+48h] [ebp-A8h] BYREF
  _BYTE v47[20]; // [esp+9Ch] [ebp-54h] BYREF
  unsigned int v48; // [esp+B0h] [ebp-40h]
  float v49; // [esp+B4h] [ebp-3Ch]
  float v50; // [esp+B8h] [ebp-38h] BYREF
  float v51; // [esp+BCh] [ebp-34h]
  float v52; // [esp+C0h] [ebp-30h]
  float v53; // [esp+C4h] [ebp-2Ch] BYREF
  float v54; // [esp+C8h] [ebp-28h]
  float v55; // [esp+CCh] [ebp-24h]
  int v56; // [esp+D0h] [ebp-20h]
  float v57; // [esp+D4h] [ebp-1Ch]
  float v58; // [esp+D8h] [ebp-18h]
  void *Block; // [esp+DCh] [ebp-14h]
  int v60; // [esp+E0h] [ebp-10h]
  int v61; // [esp+E4h] [ebp-Ch]
  int v62; // [esp+E8h] [ebp-8h] BYREF
  int v63; // [esp+ECh] [ebp-4h]

  v62 = 0;
  sub_64E466(v47);
  if ( a2 && a3 )
  {
    v48 = (*(int (__stdcall **)(int))(*(_DWORD *)a2 + 52))(a2);
    v5 = (*(int (__stdcall **)(int, _DWORD, _BYTE *))(*(_DWORD *)a2 + 68))(a2, 0, v42);
    if ( v5 >= 0 )
    {
      v6 = v43;
      v7 = operator new(16 * v43);
      v8 = v7;
      if ( v7 )
      {
        sub_41D1B0((int)v7, 16, v6, (int)sub_681563);
        Block = v8;
      }
      else
      {
        Block = 0;
      }
      if ( Block )
      {
        v56 = 0;
        if ( v48 )
        {
          while ( 1 )
          {
            v4 = (*(int (__stdcall **)(int, _DWORD, int, int *))(*(_DWORD *)a2 + 72))(a2, 0, v56, &v62);
            if ( v4 < 0 )
              break;
            v4 = (*(int (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)a2 + 68))(a2, v56, v44);
            if ( v4 < 0 )
              break;
            v9 = v56 ? sub_64E610(v46, v62, 0, 0, 0, 0) : sub_64E610(v46, v62, 0, 0, 0, 0x20000);
            v4 = v9;
            if ( v9 < 0 )
              break;
            v10 = sub_659124(v46);
            v11 = v10;
            if ( !v10 )
              goto LABEL_84;
            sub_64FE1D(v10);
            v12 = 1.0;
            v60 = v45;
            v61 = 0;
            v58 = 1.0 / (double)(unsigned int)v45;
            v50 = 0.0;
            v49 = v58 + v58;
            v51 = v49;
            v52 = v49;
            if ( v45 > 0 )
            {
              while ( 1 )
              {
                v17 = (char *)Block;
                v63 = 0;
                v57 = v12 - ((double)v61 + (double)v61 + v12) * v58;
                while ( 1 )
                {
                  v54 = v57;
                  v55 = v12 - ((double)v63 + (double)v63 + v12) * v58;
                  v53 = 1.0;
                  a3(v17, &v53, &v50, a4);
                  v17 += 16;
                  if ( ++v63 >= v60 )
                    break;
                  v12 = 1.0;
                }
                v18 = v61;
                (*(void (__thiscall **)(int, int, _DWORD, void *))(*(_DWORD *)v11 + 8))(v11, v61, 0, Block);
                v61 = v18 + 1;
                if ( v18 + 1 >= v60 )
                  break;
                v12 = 1.0;
              }
            }
            (**(void (__thiscall ***)(int, int, int *))v11)(v11, 1, a1);
            if ( v62 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v62 + 8))(v62);
              v62 = 0;
            }
            v4 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)a2 + 72))(a2, 1, v56);
            if ( v4 < 0 )
              break;
            v4 = sub_64E610(v46, v62, 0, 0, 0, 0);
            if ( v4 < 0 )
              break;
            v13 = sub_659124(v46);
            v14 = v13;
            if ( !v13 )
              goto LABEL_84;
            sub_64FE1D(v13);
            v50 = 0.0;
            v61 = 0;
            v51 = v49;
            v52 = v49;
            if ( v60 > 0 )
            {
              do
              {
                v15 = 1.0;
                v16 = (char *)Block;
                v63 = 0;
                v57 = 1.0 - ((double)v61 + (double)v61 + 1.0) * v58;
                while ( 1 )
                {
                  v54 = v57;
                  v53 = -1.0;
                  v55 = ((double)v63 + (double)v63 + v15) * v58 - v15;
                  a3(v16, &v53, &v50, a4);
                  v16 += 16;
                  if ( ++v63 >= v60 )
                    break;
                  v15 = 1.0;
                }
                v19 = v61;
                (*(void (__thiscall **)(int, int, _DWORD, void *))(*(_DWORD *)v14 + 8))(v14, v61, 0, Block);
                v61 = v19 + 1;
              }
              while ( v19 + 1 < v60 );
            }
            (**(void (__thiscall ***)(int, int, int *))v14)(v14, 1, &v62);
            if ( v62 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v62 + 8))(v62);
              v62 = 0;
            }
            v4 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)a2 + 72))(a2, 2, v56);
            if ( v4 < 0 )
              break;
            v4 = sub_64E610(v46, v62, 0, 0, 0, 0);
            if ( v4 < 0 )
              break;
            v20 = sub_659124(v46);
            v21 = v20;
            if ( !v20 )
              goto LABEL_84;
            sub_64FE1D(v20);
            v50 = v49;
            v61 = 0;
            v51 = 0.0;
            v52 = v49;
            if ( v60 > 0 )
            {
              do
              {
                v22 = 1.0;
                v23 = (char *)Block;
                v63 = 0;
                v57 = ((double)v61 + (double)v61 + 1.0) * v58 - 1.0;
                while ( 1 )
                {
                  v54 = 1.0;
                  v55 = v57;
                  v53 = ((double)v63 + (double)v63 + v22) * v58 - v22;
                  a3(v23, &v53, &v50, a4);
                  v23 += 16;
                  if ( ++v63 >= v60 )
                    break;
                  v22 = 1.0;
                }
                v24 = v61;
                (*(void (__thiscall **)(int, int, _DWORD, void *))(*(_DWORD *)v21 + 8))(v21, v61, 0, Block);
                v61 = v24 + 1;
              }
              while ( v24 + 1 < v60 );
            }
            (**(void (__thiscall ***)(int, int, int *))v21)(v21, 1, &v62);
            if ( v62 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v62 + 8))(v62);
              v62 = 0;
            }
            v4 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)a2 + 72))(a2, 3, v56);
            if ( v4 < 0 )
              break;
            v4 = sub_64E610(v46, v62, 0, 0, 0, 0);
            if ( v4 < 0 )
              break;
            v25 = sub_659124(v46);
            v26 = v25;
            if ( !v25 )
              goto LABEL_84;
            sub_64FE1D(v25);
            v50 = v49;
            v61 = 0;
            v51 = 0.0;
            v52 = v49;
            if ( v60 > 0 )
            {
              do
              {
                v27 = 1.0;
                v28 = (char *)Block;
                v63 = 0;
                v57 = 1.0 - ((double)v61 + (double)v61 + 1.0) * v58;
                while ( 1 )
                {
                  v55 = v57;
                  v54 = -1.0;
                  v53 = ((double)v63 + (double)v63 + v27) * v58 - v27;
                  a3(v28, &v53, &v50, a4);
                  v28 += 16;
                  if ( ++v63 >= v60 )
                    break;
                  v27 = 1.0;
                }
                v29 = v61;
                (*(void (__thiscall **)(int, int, _DWORD, void *))(*(_DWORD *)v26 + 8))(v26, v61, 0, Block);
                v61 = v29 + 1;
              }
              while ( v29 + 1 < v60 );
            }
            (**(void (__thiscall ***)(int, int, int *))v26)(v26, 1, &v62);
            if ( v62 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v62 + 8))(v62);
              v62 = 0;
            }
            v4 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)a2 + 72))(a2, 4, v56);
            if ( v4 < 0 )
              break;
            v4 = sub_64E610(v46, v62, 0, 0, 0, 0);
            if ( v4 < 0 )
              break;
            v30 = sub_659124(v46);
            v31 = v30;
            if ( !v30 )
              goto LABEL_84;
            sub_64FE1D(v30);
            v50 = v49;
            v51 = v49;
            v61 = 0;
            v52 = 0.0;
            if ( v60 > 0 )
            {
              do
              {
                v32 = 1.0;
                v33 = (char *)Block;
                v63 = 0;
                v57 = 1.0 - ((double)v61 + (double)v61 + 1.0) * v58;
                while ( 1 )
                {
                  v55 = 1.0;
                  v54 = v57;
                  v53 = ((double)v63 + (double)v63 + v32) * v58 - v32;
                  a3(v33, &v53, &v50, a4);
                  v33 += 16;
                  if ( ++v63 >= v60 )
                    break;
                  v32 = 1.0;
                }
                v34 = v61;
                (*(void (__thiscall **)(int, int, _DWORD, void *))(*(_DWORD *)v31 + 8))(v31, v61, 0, Block);
                v61 = v34 + 1;
              }
              while ( v34 + 1 < v60 );
            }
            (**(void (__thiscall ***)(int, int, int *))v31)(v31, 1, &v62);
            if ( v62 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v62 + 8))(v62);
              v62 = 0;
            }
            a1 = &v62;
            v4 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)a2 + 72))(a2, 5, v56);
            if ( v4 < 0 )
              break;
            v4 = sub_64E610(v46, v62, 0, 0, 0, 0);
            if ( v4 < 0 )
              break;
            v35 = sub_659124(v46);
            v36 = v35;
            if ( !v35 )
            {
LABEL_84:
              v4 = -2005530516;
              break;
            }
            sub_64FE1D(v35);
            v50 = v49;
            v51 = v49;
            v61 = 0;
            v52 = 0.0;
            if ( v60 > 0 )
            {
              do
              {
                v37 = 1.0;
                v38 = (char *)Block;
                v63 = 0;
                v57 = 1.0 - ((double)v61 + (double)v61 + 1.0) * v58;
                while ( 1 )
                {
                  v54 = v57;
                  v55 = -1.0;
                  v53 = v37 - ((double)v63 + (double)v63 + v37) * v58;
                  a3(v38, &v53, &v50, a4);
                  v38 += 16;
                  if ( ++v63 >= v60 )
                    break;
                  v37 = 1.0;
                }
                v39 = v61;
                (*(void (__thiscall **)(int, int, _DWORD, void *))(*(_DWORD *)v36 + 8))(v36, v61, 0, Block);
                v61 = v39 + 1;
              }
              while ( v39 + 1 < v60 );
            }
            (**(void (__thiscall ***)(int, int))v36)(v36, 1);
            if ( v62 )
            {
              (*(void (__stdcall **)(int))(*(_DWORD *)v62 + 8))(v62);
              v62 = 0;
            }
            if ( ++v56 >= v48 )
              goto LABEL_79;
          }
        }
        else
        {
LABEL_79:
          v4 = 0;
        }
      }
      else
      {
        v4 = -2147024882;
      }
      if ( v62 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v62 + 8))(v62);
        v62 = 0;
      }
      j__free(Block);
    }
    else
    {
      v4 = v5;
    }
  }
  else
  {
    v4 = -2005530516;
  }
  sub_64E60B(v47);
  return v4;
}
