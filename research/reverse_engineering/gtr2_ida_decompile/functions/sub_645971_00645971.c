int __userpurge sub_645971@<eax>(
        int a1@<edi>,
        int a2,
        const void *a3,
        int *a4,
        int a5,
        const void *a6,
        int *a7,
        int a8,
        int a9)
{
  int v9; // esi
  int v10; // ebx
  int v11; // edx
  int v12; // esi
  int v13; // ecx
  int v14; // eax
  int v15; // esi
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // esi
  int v22[10]; // [esp+4h] [ebp-C8h] BYREF
  _DWORD v23[11]; // [esp+2Ch] [ebp-A0h] BYREF
  _BYTE v24[20]; // [esp+58h] [ebp-74h] BYREF
  _BYTE v25[12]; // [esp+6Ch] [ebp-60h] BYREF
  int v26; // [esp+78h] [ebp-54h]
  int v27; // [esp+84h] [ebp-48h]
  int v28; // [esp+88h] [ebp-44h]
  _BYTE v29[12]; // [esp+8Ch] [ebp-40h] BYREF
  int v30; // [esp+98h] [ebp-34h]
  int v31; // [esp+A4h] [ebp-28h]
  int v32; // [esp+A8h] [ebp-24h]
  int v33; // [esp+ACh] [ebp-20h] BYREF
  int v34; // [esp+B0h] [ebp-1Ch]
  int v35; // [esp+B4h] [ebp-18h]
  int v36; // [esp+B8h] [ebp-14h]
  int v37; // [esp+BCh] [ebp-10h] BYREF
  int v38; // [esp+C0h] [ebp-Ch]
  int v39; // [esp+C4h] [ebp-8h]
  int v40; // [esp+C8h] [ebp-4h]

  sub_64E466(v24);
  if ( a2 )
  {
    v10 = a5;
    if ( !a5 )
    {
      v9 = -2005530516;
      goto LABEL_36;
    }
    (*(void (__stdcall **)(int, _BYTE *))(*(_DWORD *)a2 + 48))(a2, v25);
    (*(void (__stdcall **)(int, _BYTE *))(*(_DWORD *)v10 + 48))(v10, v29);
    if ( (unsigned __int16)a8 == 5 || a9 || a3 != a6 && (!a3 || !a6 || memcmp(a3, a6, 0x400u)) )
      goto LABEL_26;
    if ( a4 )
    {
      v37 = *a4;
      v38 = a4[1];
      v39 = a4[2];
      v40 = a4[3];
      v11 = v39;
      v12 = v40;
    }
    else
    {
      v11 = v27;
      v12 = v28;
      v37 = 0;
      v38 = 0;
      v39 = v27;
      v40 = v28;
    }
    if ( a7 )
    {
      v33 = *a7;
      v34 = a7[1];
      v35 = a7[2];
      v36 = a7[3];
      v13 = v36;
      v14 = v35;
      v12 = v40;
    }
    else
    {
      v13 = v32;
      v33 = 0;
      v34 = 0;
      v14 = v31;
      v35 = v31;
      v36 = v32;
    }
    if ( v11 - v37 != v14 - v33 || v12 - v38 != v13 - v34 )
    {
LABEL_26:
      v17 = 1;
      if ( a2 == v10 )
        v17 = 65537;
      v18 = sub_64E610(v22, v10, a6, a7, 0, v17);
      if ( v18 < 0 || (v18 = sub_6447D4(a2, (int)a3, (int)a4, v22[0], v22[1], v22[2], (int)a6, v23, a8, a9), v18 < 0) )
      {
        v9 = v18;
        goto LABEL_36;
      }
      if ( !v30 )
      {
        if ( v26 )
        {
          (*(void (__stdcall **)(int, int *))(*(_DWORD *)v10 + 12))(v10, &a2);
          v19 = (*(int (__stdcall **)(int))(*(_DWORD *)a2 + 12))(a2);
          (*(void (__stdcall **)(int))(*(_DWORD *)a2 + 8))(a2);
          if ( v19 )
          {
            v9 = -2005530520;
            goto LABEL_36;
          }
        }
      }
LABEL_35:
      v9 = 0;
      goto LABEL_36;
    }
    (*(void (__stdcall **)(int, int *, int))(*(_DWORD *)v10 + 12))(v10, &a5, a1);
    sub_5AF533(1);
    v15 = -2147467259;
    if ( !v26 )
    {
      if ( v30 )
      {
        if ( v30 != 2 )
          goto LABEL_25;
        v16 = (*(int (__stdcall **)(int, int, int *, int, int *))(*(_DWORD *)a5 + 120))(a5, v10, &v33, a2, &v37);
      }
      else
      {
        v16 = (*(int (__stdcall **)(int, int, int *, int, int *, _DWORD))(*(_DWORD *)a5 + 136))(
                a5,
                v10,
                &v33,
                a2,
                &v37,
                0);
      }
      v15 = v16;
    }
LABEL_25:
    sub_5AF533(0);
    (*(void (__cdecl **)(int))(*(_DWORD *)a5 + 8))(a5);
    if ( v15 >= 0 )
      goto LABEL_35;
    goto LABEL_26;
  }
  v9 = -2005530516;
LABEL_36:
  sub_64E60B(v24);
  return v9;
}
