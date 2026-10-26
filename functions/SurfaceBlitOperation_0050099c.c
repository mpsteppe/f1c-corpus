int __stdcall sub_50099C(int a1, const void *a2, int *a3, int a4, const void *a5, int *a6, int a7, int a8)
{
  int v8; // esi
  int v9; // ebx
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v17[10]; // [esp+4h] [ebp-44h] BYREF
  _DWORD v18[9]; // [esp+2Ch] [ebp-1Ch] BYREF
  _BYTE v19[24]; // [esp+50h] [ebp+8h] BYREF
  int v20; // [esp+68h] [ebp+20h]
  int v21; // [esp+6Ch] [ebp+24h]
  _BYTE v22[16]; // [esp+70h] [ebp+28h] BYREF
  int v23; // [esp+80h] [ebp+38h] BYREF
  int v24; // [esp+84h] [ebp+3Ch]
  int v25; // [esp+88h] [ebp+40h]
  int v26; // [esp+8Ch] [ebp+44h]
  int v27; // [esp+90h] [ebp+48h] BYREF
  int v28; // [esp+94h] [ebp+4Ch]
  int v29; // [esp+98h] [ebp+50h]
  int v30; // [esp+9Ch] [ebp+54h]

  ZeroInit4Ints_64bf(v22);
  if ( a1 )
  {
    v9 = a4;
    if ( a4 )
    {
      if ( (unsigned __int16)a7 != 5 && !a8 && (a2 == a5 || a2 && a5 && !memcmp(a2, a5, 0x400u)) )
      {
        if ( a3 )
        {
          v27 = *a3;
          v28 = a3[1];
          v29 = a3[2];
          v30 = a3[3];
          v10 = v29;
        }
        else
        {
          (*(void (__stdcall **)(int, _BYTE *))(*(_DWORD *)a1 + 32))(a1, v19);
          v10 = v20;
          v27 = 0;
          v28 = 0;
          v29 = v20;
          v30 = v21;
        }
        if ( a6 )
        {
          v23 = *a6;
          v24 = a6[1];
          v25 = a6[2];
          v26 = a6[3];
          v11 = v26;
          v12 = v25;
        }
        else
        {
          (*(void (__stdcall **)(int, _BYTE *))(*(_DWORD *)v9 + 32))(v9, v19);
          v12 = v20;
          v11 = v21;
          v23 = 0;
          v24 = 0;
          v10 = v29;
          v25 = v20;
          v26 = v21;
        }
        if ( v10 - v27 == v12 - v23 && v30 - v28 == v11 - v24 )
        {
          (*(void (__stdcall **)(int, int *))(*(_DWORD *)v9 + 12))(v9, &a4);
          sub_500EAC(1);
          v13 = (*(int (__stdcall **)(int, int, int *, int, int, int *))(*(_DWORD *)a4 + 112))(
                  a4,
                  v9,
                  &v23,
                  1,
                  a1,
                  &v27);
          sub_500EAC(0);
          (*(void (__stdcall **)(int))(*(_DWORD *)a4 + 8))(a4);
          if ( v13 >= 0 )
            goto LABEL_25;
        }
      }
      v14 = 1;
      if ( a1 == v9 )
        v14 = 65537;
      v15 = D3DTextureSurfaceLockCopy(v17, v9, a5, a6, 0, v14);
      if ( v15 >= 0
        && (v15 = NetworkPacketSendReceive(a1, (int)a2, (int)a3, v17[0], v17[1], v17[2], (int)a5, v18, a7, a8), v15 >= 0) )
      {
LABEL_25:
        v8 = 0;
      }
      else
      {
        v8 = v15;
      }
    }
    else
    {
      v8 = -2005530516;
    }
  }
  else
  {
    v8 = -2005530516;
  }
  j_RenderResourceTeardown(v22);
  return v8;
}
