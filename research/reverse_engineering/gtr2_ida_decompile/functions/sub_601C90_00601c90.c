// bad sp value at call has been detected, the output may be wrong!
int __thiscall sub_601C90(_DWORD *this, int a2, int a3)
{
  int v3; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // eax
  int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  _DWORD *v20; // ebx
  int v21; // eax
  int v22; // eax
  int v23; // ebx
  int *v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // eax
  int v28; // edx
  BOOL v29; // ebx
  unsigned int v30; // eax
  int v31; // eax
  _DWORD *v32; // eax
  int v33; // [esp+174h] [ebp-6ECh]
  int v34[5]; // [esp+188h] [ebp-6D8h] BYREF
  int v35[4]; // [esp+19Ch] [ebp-6C4h] BYREF
  char v36[4]; // [esp+1ACh] [ebp-6B4h] BYREF
  int v37[5]; // [esp+1B0h] [ebp-6B0h] BYREF
  int v38[5]; // [esp+1C4h] [ebp-69Ch] BYREF
  int v39[5]; // [esp+1D8h] [ebp-688h] BYREF
  int v40[5]; // [esp+1ECh] [ebp-674h] BYREF
  int v41[5]; // [esp+200h] [ebp-660h] BYREF
  int v42[5]; // [esp+214h] [ebp-64Ch] BYREF
  int v43[5]; // [esp+228h] [ebp-638h] BYREF
  int v44[5]; // [esp+23Ch] [ebp-624h] BYREF
  int v45[5]; // [esp+250h] [ebp-610h] BYREF
  int v46[4]; // [esp+264h] [ebp-5FCh] BYREF
  int v47; // [esp+274h] [ebp-5ECh]
  int v48; // [esp+278h] [ebp-5E8h] BYREF
  int v49; // [esp+27Ch] [ebp-5E4h]
  int v50; // [esp+280h] [ebp-5E0h]
  int v51; // [esp+284h] [ebp-5DCh]
  char *p_i; // [esp+288h] [ebp-5D8h]
  int *v53; // [esp+28Ch] [ebp-5D4h] BYREF
  int v54; // [esp+29Ch] [ebp-5C4h]
  char ArgList[4]; // [esp+2A0h] [ebp-5C0h] BYREF
  int v56; // [esp+2A4h] [ebp-5BCh] BYREF
  int i; // [esp+2A8h] [ebp-5B8h] BYREF
  unsigned int v58; // [esp+2ACh] [ebp-5B4h] BYREF
  unsigned int v59; // [esp+2B0h] [ebp-5B0h]
  int v60; // [esp+2B4h] [ebp-5ACh]
  int v61; // [esp+2B8h] [ebp-5A8h]
  int v62; // [esp+2BCh] [ebp-5A4h]
  int v63; // [esp+2C0h] [ebp-5A0h]
  _DWORD v64[7]; // [esp+2C4h] [ebp-59Ch]
  int v65; // [esp+2E0h] [ebp-580h]
  _BYTE v66[28]; // [esp+2E4h] [ebp-57Ch] BYREF
  int v67; // [esp+300h] [ebp-560h]
  char v68[1064]; // [esp+414h] [ebp-44Ch] BYREF
  int v69; // [esp+83Ch] [ebp-24h]

  v3 = *(_DWORD *)(a2 + 268);
  this[2] = (*(int (__stdcall **)(_DWORD, int, _DWORD, char *))(*(_DWORD *)this[2386] + 20))(this[2386], v3, 0, v68);
  if ( v69 == 4170 )
    (*(void (__thiscall **)(_DWORD *, int, int, int, int))(*this + 132))(this, -1, -1, 1024, 768);
  v5 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(*(_DWORD *)this[2386] + 36))(
         this[2386],
         v3,
         1,
         23,
         23,
         0);
  this[2] = v5;
  if ( !v5 )
    *(_DWORD *)(a2 + 260) |= 0x4000000u;
  v6 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(*(_DWORD *)this[2386] + 36))(
         this[2386],
         v3,
         1,
         24,
         25,
         0);
  this[2] = v6;
  if ( !v6 )
    *(_DWORD *)(a2 + 260) |= 0x8000000u;
  v7 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(*(_DWORD *)this[2386] + 36))(
         this[2386],
         v3,
         1,
         24,
         24,
         0);
  this[2] = v7;
  if ( !v7 )
    *(_DWORD *)(a2 + 260) |= 0x10000000u;
  v8 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(*(_DWORD *)this[2386] + 36))(
         this[2386],
         v3,
         1,
         20,
         20,
         0);
  this[2] = v8;
  if ( !v8 )
    *(_DWORD *)(a2 + 260) |= 0x20000000u;
  v9 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(*(_DWORD *)this[2386] + 36))(
         this[2386],
         v3,
         1,
         22,
         22,
         0);
  this[2] = v9;
  if ( !v9 )
    *(_DWORD *)(a2 + 260) |= 0x80000000;
  v10 = (*(int (__stdcall **)(_DWORD, int, int, int, int, _DWORD))(*(_DWORD *)this[2386] + 36))(
          this[2386],
          v3,
          1,
          22,
          21,
          0);
  this[2] = v10;
  if ( !v10 )
    *(_DWORD *)(a2 + 260) |= 0x40000000u;
  v11 = (*(int (__stdcall **)(_DWORD, int, int, _BYTE *))(*(_DWORD *)this[2386] + 56))(this[2386], v3, 1, v66);
  this[2] = v11;
  if ( v11 )
    return -1;
  v13 = v67;
  v14 = *(_DWORD *)(a2 + 260);
  if ( (v67 & 0x10000) != 0 )
    v15 = (unsigned int)&byte_800000 | v14;
  else
    v15 = v14 & 0xFF7FFFFF;
  *(_DWORD *)(a2 + 260) = v15;
  if ( (v13 & 0x100000) != 0 )
    v16 = (unsigned int)&dword_1000000 | v15;
  else
    v16 = v15 & 0xFEFFFFFF;
  *(_DWORD *)(a2 + 260) = v16;
  if ( (v13 & 0x80000) != 0 )
    v17 = v16 | 2;
  else
    v17 = v16 & 0xFFFFFFFD;
  *(_DWORD *)(a2 + 260) = v17;
  v18 = *(_DWORD *)(a2 + 260);
  if ( (v66[20] & 1) != 0 )
    v19 = v18 | 8;
  else
    v19 = v18 & 0xFFFFFFF7;
  v20 = this + 1216;
  p_i = (char *)(this + 1216);
  v51 = 1;
  v50 = 0;
  v49 = 23;
  *(_DWORD *)(a2 + 260) = v19;
  v21 = this[2386];
  v48 = 1;
  v47 = v3;
  this[1216] = 0;
  if ( !(*(int (__stdcall **)(int, int, int, int, int, int, char *, int *))(*(_DWORD *)v21 + 44))(
          v21,
          v47,
          v48,
          v49,
          v50,
          v51,
          p_i,
          v53)
    || !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, _DWORD *))(*(_DWORD *)this[2386] + 44))(
          this[2386],
          v3,
          1,
          22,
          0,
          1,
          this + 1216)
    || !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, _DWORD *))(*(_DWORD *)this[2386] + 44))(
          this[2386],
          v3,
          1,
          21,
          0,
          1,
          this + 1216) )
  {
    switch ( *v20 )
    {
      case 1:
        goto LABEL_40;
      case 2:
        goto LABEL_39;
      case 3:
        goto LABEL_38;
      case 4:
        goto LABEL_37;
      case 5:
        goto LABEL_36;
      case 6:
        goto LABEL_35;
      case 7:
        goto LABEL_34;
      case 8:
        *(_DWORD *)(a2 + 264) |= (unsigned int)&byte_800000;
LABEL_34:
        *(_DWORD *)(a2 + 264) |= 0x400000u;
LABEL_35:
        *(_DWORD *)(a2 + 264) |= 0x200000u;
LABEL_36:
        *(_DWORD *)(a2 + 264) |= 0x100000u;
LABEL_37:
        *(_DWORD *)(a2 + 264) |= 0x80000u;
LABEL_38:
        *(_DWORD *)(a2 + 264) |= 0x40000u;
LABEL_39:
        *(_DWORD *)(a2 + 264) |= 0x20000u;
LABEL_40:
        *(_DWORD *)(a2 + 264) |= 0x10000u;
        break;
      default:
        break;
    }
  }
  *(_DWORD *)ArgList = 0;
  sub_6019C0(v3, a2, 2, 1, ArgList);
  sub_6019C0(v3, a2, 3, 4, &v53);
  sub_6019C0(v3, a2, 4, 2, &v48);
  sub_6019C0(v3, a2, 5, 8, v46);
  sub_6019C0(v3, a2, 6, 16, v45);
  sub_6019C0(v3, a2, 7, 32, v44);
  sub_6019C0(v3, a2, 8, 64, v43);
  sub_6019C0(v3, a2, 9, 128, v42);
  sub_6019C0(v3, a2, 10, 256, v41);
  sub_6019C0(v3, a2, 11, 512, v40);
  sub_6019C0(v3, a2, 12, 1024, v39);
  sub_6019C0(v3, a2, 13, 2048, v38);
  sub_6019C0(v3, a2, 14, 4096, v37);
  sub_6019C0(v3, a2, 15, 0x2000, v35);
  sub_6019C0(v3, a2, 16, 0x4000, v34);
  if ( *v20 < v33 )
    *(_BYTE *)(a2 + 266) = 0;
  else
    *(_DWORD *)(a2 + 264) &= 0xFFFF8000;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  v22 = (*(int (__cdecl **)(_DWORD, int, char *))(*(_DWORD *)this[2386] + 32))(this[2386], v3, v36);
  this[2] = v22;
  if ( v22 )
  {
    p_i = "Could not get desktop display mode";
LABEL_46:
    sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, p_i, (char)v53);
    return -1;
  }
  p_i = ArgList;
  if ( v65 == 22 )
    (*(void (__thiscall **)(_DWORD *, int, int *, char *))(*this + 172))(this, 21, &v56, p_i);
  else
    (*(void (__thiscall **)(_DWORD *, int, int *, char *))(*this + 172))(this, v65, &v56, p_i);
  v64[0] = 24;
  v64[1] = 23;
  v64[2] = 21;
  v64[3] = 22;
  for ( i = 0; i < 4; ++i )
  {
    v23 = v64[i];
    v24 = (int *)this[2386];
    v25 = *v24;
    v63 = v23;
    v62 = (*(int (__stdcall **)(int *, int, int))(v25 + 24))(v24, v3, v23);
    if ( v62 > 0 )
    {
      v54 = 0;
      while ( 1 )
      {
        v26 = (*(int (__stdcall **)(_DWORD, int, int, int, unsigned int *))(*(_DWORD *)this[2386] + 28))(
                this[2386],
                v3,
                v23,
                v54,
                &v58);
        this[2] = v26;
        if ( !v26 )
        {
          v27 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int *))(*(_DWORD *)this[2386] + 36))(
                  this[2386],
                  v3,
                  1,
                  v65,
                  v61,
                  1,
                  v53);
          v28 = *this;
          this[2] = v27;
          v29 = v27 == 0;
          i = 0;
          v53 = &v56;
          p_i = (char *)&i;
          if ( v62 == 22 )
            v51 = 21;
          else
            v51 = v62;
          (*(void (__thiscall **)(_DWORD *, int, char *))(v28 + 172))(this, v51, p_i);
          if ( v56 >= 16 && v58 >= this[2259] && v59 >= this[2260] )
          {
            v30 = this[2261];
            if ( v58 <= v30 && v59 <= v30 && !sub_5FB180((_DWORD *)a2, v58, v59, *(int *)ArgList, v60) )
            {
              if ( v29 )
              {
                v31 = sub_5FB0E0((_DWORD *)a2, v58, v59, *(int *)ArgList, v60);
                v32 = (_DWORD *)sub_5FB0A0(v31);
                *v32 |= 1u;
              }
            }
          }
        }
        if ( ++v54 >= v62 )
          break;
        v23 = v63;
      }
    }
  }
  if ( sub_5FB020((_DWORD *)a2, 0) <= 0 )
  {
    p_i = "No video modes found for this driver";
    goto LABEL_46;
  }
  return 0;
}
