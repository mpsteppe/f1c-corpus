int __thiscall sub_54335F(_DWORD *this, _DWORD *a2, _DWORD *a3, int a4, int *a5, int a6, int a7)
{
  int result; // eax
  unsigned int v8; // ebx
  unsigned int v9; // eax
  _DWORD *v10; // edi
  _DWORD *v11; // esi
  _DWORD *v12; // edi
  int v13; // ebx
  unsigned int v14; // eax
  bool v15; // zf
  unsigned int v16; // edx
  unsigned int v17; // eax
  unsigned int v18; // esi
  unsigned int v19; // ecx
  int v20; // edx
  int v21; // edx
  unsigned int v22; // edx
  unsigned int v23; // edx
  _DWORD *v24; // eax
  int v25; // [esp+Ch] [ebp-60h] BYREF
  unsigned int v26; // [esp+14h] [ebp-58h]
  int v27; // [esp+18h] [ebp-54h]
  unsigned int v28; // [esp+24h] [ebp-48h]
  unsigned int v29; // [esp+28h] [ebp-44h]
  unsigned int v30; // [esp+2Ch] [ebp-40h] BYREF
  unsigned int v31; // [esp+30h] [ebp-3Ch]
  unsigned int v32; // [esp+34h] [ebp-38h]
  unsigned int v33; // [esp+38h] [ebp-34h]
  int v34; // [esp+3Ch] [ebp-30h]
  int v35; // [esp+40h] [ebp-2Ch]
  int v36; // [esp+44h] [ebp-28h]
  int v37; // [esp+48h] [ebp-24h]
  _DWORD v38[2]; // [esp+4Ch] [ebp-20h] BYREF
  _DWORD *v39; // [esp+54h] [ebp-18h]
  int v40; // [esp+58h] [ebp-14h] BYREF
  _DWORD *v41; // [esp+5Ch] [ebp-10h]
  int v42; // [esp+60h] [ebp-Ch] BYREF
  BOOL v43; // [esp+64h] [ebp-8h]
  int v44; // [esp+68h] [ebp-4h]
  int v45; // [esp+80h] [ebp+14h]

  v39 = this;
  sub_5432D5(this);
  (*(void (__stdcall **)(_DWORD *, int *))(*a3 + 32))(a3, &v25);
  if ( a5 )
  {
    v34 = *a5;
    v35 = a5[1];
    v36 = a5[2];
    v37 = a5[3];
    if ( v34 < 0 || v36 > v28 || v34 > v36 || v35 < 0 || v37 > v29 || v35 > v37 )
      return -2005530516;
    if ( v34 || v36 != v28 || v35 || (v45 = 0, v37 != v29) )
      v45 = 1;
    v43 = (a7 & 1) == 0 && !v45;
  }
  else
  {
    v36 = v28;
    v37 = v29;
    v34 = 0;
    v35 = 0;
    v45 = 0;
    v43 = (a7 & 1) == 0;
  }
  v44 = a7 & 0x10000;
  if ( (a7 & 0x10000) == 0 )
  {
    if ( v27 || (v26 & 0x200) != 0 )
      goto LABEL_38;
    sub_53DCB1(1);
    if ( (*(int (__stdcall **)(_DWORD *, void *, int *))(*a3 + 28))(a3, &unk_5F2A5C, &v40) < 0 )
    {
      v26 = a3[4];
      v44 = ((v26 >> 26) & 1) == 0;
    }
    else
    {
      v44 = 1;
      if ( v40 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v40 + 8))(v40);
        v40 = 0;
      }
    }
    sub_53DCB1(0);
    if ( !v44 )
    {
LABEL_38:
      v41 = a3;
      goto LABEL_39;
    }
  }
  if ( v25 == 827611204 || v25 == 844388420 || v25 == 861165636 || v25 == 877942852 || v25 == 894720068 )
  {
    v8 = (v28 + 3) & 0xFFFFFFFC;
    v9 = (v29 + 3) & 0xFFFFFFFC;
  }
  else
  {
    v8 = v28;
    v9 = v29;
  }
  v10 = v39;
  v41 = (_DWORD *)v9;
  v11 = v39 + 3;
  (*(void (__stdcall **)(_DWORD *, _DWORD *))(*a3 + 12))(a3, v39 + 3);
  v12 = v10 + 2;
  result = (*(int (__stdcall **)(_DWORD, unsigned int, _DWORD *, int, _DWORD *))(*(_DWORD *)*v11 + 108))(
             *v11,
             v8,
             v41,
             v25,
             v12);
  if ( result >= 0 )
  {
    if ( v43
      || (result = (*(int (__stdcall **)(_DWORD, _DWORD *, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*v11 + 112))(
                     *v11,
                     a3,
                     0,
                     0,
                     *v12,
                     0),
          result >= 0) )
    {
      v41 = (_DWORD *)*v12;
LABEL_39:
      v13 = 16 * (a7 & 1 | 0x80);
      if ( v43 && !v44 && (v26 & 0x200) != 0 )
      {
        if ( (a7 & 0x20000) != 0 )
        {
          v13 |= 0x2000u;
          goto LABEL_84;
        }
        sub_53DCB1(1);
        if ( (*(int (__stdcall **)(_DWORD *, void *, int *))(*a3 + 28))(a3, &unk_5F2A4C, &v42) >= 0 )
        {
          if ( (*(int (__stdcall **)(int))(*(_DWORD *)v42 + 52))(v42) == 1 )
          {
            v13 |= 0x2000u;
            v45 = 0;
          }
          if ( v42 )
          {
            (*(void (__stdcall **)(int))(*(_DWORD *)v42 + 8))(v42);
            v42 = 0;
          }
        }
        sub_53DCB1(0);
      }
      if ( !v45 )
        goto LABEL_84;
      if ( v25 != 827611204 && v25 != 844388420 )
      {
        if ( v25 == 844715353 )
        {
LABEL_59:
          v14 = (v36 + 1) & 0xFFFFFFFE;
          v30 = v34 & 0xFFFFFFFE;
          v32 = v14;
          v31 = v35;
          v33 = v37;
          if ( v14 > v28 )
          {
            v14 = v28;
            v32 = v28;
          }
          if ( (v34 & 0xFFFFFFFE) != 0 || v14 != v28 || v35 )
            goto LABEL_75;
          v15 = v37 == v29;
          goto LABEL_74;
        }
        if ( v25 != 861165636 && v25 != 877942852 && v25 != 894720068 )
        {
          if ( v25 != 1498831189 )
          {
            v30 = v34;
            v31 = v35;
            v32 = v36;
            v33 = v37;
LABEL_75:
            result = (*(int (__stdcall **)(_DWORD *, _DWORD *, unsigned int *, int))(*v41 + 36))(v41, v38, &v30, v13);
            if ( result < 0 )
              return result;
            v34 -= v30;
            v36 -= v30;
            v35 -= v31;
            v37 -= v31;
            goto LABEL_77;
          }
          goto LABEL_59;
        }
      }
      v16 = v34 & 0xFFFFFFFC;
      v17 = (v36 + 3) & 0xFFFFFFFC;
      v18 = v35 & 0xFFFFFFFC;
      v19 = (v37 + 3) & 0xFFFFFFFC;
      v30 = v34 & 0xFFFFFFFC;
      v32 = v17;
      v31 = v35 & 0xFFFFFFFC;
      v33 = v19;
      if ( v44 )
      {
        if ( v16 || v17 != ((v28 + 3) & 0xFFFFFFFC) || v18 || v19 != ((v29 + 3) & 0xFFFFFFFC) )
          goto LABEL_75;
        goto LABEL_84;
      }
      if ( v17 > v28 )
      {
        v17 = v28;
        v32 = v28;
      }
      if ( v19 > v29 )
      {
        v19 = v29;
        v33 = v29;
      }
      if ( v16 || v17 != v28 || v18 )
        goto LABEL_75;
      v15 = v19 == v29;
LABEL_74:
      if ( !v15 )
        goto LABEL_75;
LABEL_84:
      result = (*(int (__stdcall **)(_DWORD *, _DWORD *, _DWORD, int))(*v41 + 36))(v41, v38, 0, v13);
      if ( result < 0 )
        return result;
LABEL_77:
      v20 = v38[1];
      a2[3] = 0;
      a2[4] = 0;
      a2[5] = 0;
      a2[8] = 0;
      a2[14] = 0;
      *a2 = v20;
      a2[1] = v25;
      v21 = v38[0];
      a2[10] = v34;
      a2[15] = 1;
      a2[16] = 1;
      a2[2] = v21;
      v22 = v28;
      a2[11] = v35;
      a2[17] = a6;
      a2[6] = v22;
      v23 = v29;
      a2[12] = v36;
      a2[18] = a4;
      a2[7] = v23;
      a2[9] = 1;
      v24 = v39;
      a2[13] = v37;
      v24[1] = a3;
      *v24 = a7;
      return 0;
    }
  }
  return result;
}
