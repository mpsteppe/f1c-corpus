int __thiscall sub_4C6330(_DWORD *this, const char *a2)
{
  _DWORD *v2; // ebx
  int v3; // ebp
  int i; // esi
  int *v5; // eax
  _DWORD *v6; // ecx
  int v7; // ebp
  int v8; // edx
  int v9; // edx
  _DWORD *v10; // eax
  _DWORD *v11; // esi
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  _DWORD **v15; // ecx
  int v16; // eax
  _DWORD **v17; // edx
  int v18; // eax
  int v19; // edx
  int v20; // ebp
  _DWORD **v21; // edi
  _DWORD **v22; // eax
  _DWORD **v23; // esi
  _DWORD **v24; // ebp
  _DWORD **v25; // eax
  _DWORD **v26; // eax
  _DWORD *j; // edx
  int result; // eax
  int v29; // [esp-4h] [ebp-3D4h]
  int v30; // [esp+10h] [ebp-3C0h]
  _DWORD **v31; // [esp+10h] [ebp-3C0h]
  int v32; // [esp+14h] [ebp-3BCh] BYREF
  int v33; // [esp+18h] [ebp-3B8h] BYREF
  int v34; // [esp+1Ch] [ebp-3B4h] BYREF
  _DWORD *v35; // [esp+20h] [ebp-3B0h]
  char v36[8]; // [esp+24h] [ebp-3ACh] BYREF
  char v37[8]; // [esp+2Ch] [ebp-3A4h] BYREF
  char v38[8]; // [esp+34h] [ebp-39Ch] BYREF
  int v39; // [esp+3Ch] [ebp-394h] BYREF
  _BYTE v40[253]; // [esp+40h] [ebp-390h] BYREF
  __int16 v41; // [esp+13Dh] [ebp-293h]
  char v42; // [esp+13Fh] [ebp-291h]
  _DWORD v43[50]; // [esp+140h] [ebp-290h] BYREF
  _DWORD v44[50]; // [esp+208h] [ebp-1C8h] BYREF
  _BYTE v45[256]; // [esp+2D0h] [ebp-100h] BYREF

  v2 = this;
  v35 = this;
  v32 = 0;
  sub_4C62C0(this);
  if ( !a2 || !strcmp(a2, byte_5EA438) || (v3 = 0, dword_7D0398) && dword_7D0410 != 5 )
  {
    sub_566650(byte_5EA438);
    v7 = 0;
    if ( dword_8AC488 > 0 )
    {
      v8 = 0;
      v33 = 0;
      do
      {
        v9 = dword_8AC490 + v8;
        if ( v9 )
        {
          v40[0] = byte_5EA438[0];
          memset(&v40[1], 0, 0xFCu);
          v41 = 0;
          v42 = 0;
          sub_4C58A0((int)v40, 256, (int)aFilterProperti, v9 + 260);
          v10 = (_DWORD *)sub_587C03(16);
          if ( v10 )
          {
            v11 = sub_4C5C80(v10, v7, (int)v40);
            if ( v11 )
            {
              v12 = sub_587C03(12);
              if ( v12 )
              {
                *(_DWORD *)v12 = v11;
                *(_DWORD *)(v12 + 4) = 0;
                *(_BYTE *)(v12 + 8) = 1;
              }
              else
              {
                v12 = 0;
              }
              if ( v2[2] )
              {
                *(_DWORD *)(v2[3] + 4) = v12;
              }
              else
              {
                v2[2] = v12;
                v2[4] = v12;
              }
              v13 = v2[5];
              v2[3] = v12;
              v14 = v32 + 1;
              v2[5] = v13 + 1;
              v32 = v14;
            }
          }
        }
        ++v7;
        v8 = v33 + 396;
        v33 += 396;
      }
      while ( v7 < dword_8AC488 );
    }
  }
  else
  {
    sub_566650(a2);
    strcpy(v36, " ,\t\n");
    v39 = dword_5D30C0;
    strcpy(v37, "AND:");
    v32 = 0;
    v34 = 0;
    v33 = 0;
    strcpy(v38, "NOT:");
    v30 = 0;
    sub_587DD0(v45, a2, 255);
    memset(v44, 0, sizeof(v44));
    memset(v43, 0, sizeof(v43));
    v45[255] = 0;
    for ( i = sub_5897CA(v45, v36); i; i = sub_5897CA(0, v36) )
    {
      if ( sub_588410(i, v37) )
      {
        if ( sub_588410(i, &v39) )
        {
          if ( sub_588410(i, v38) )
          {
            if ( v30 )
            {
              if ( v30 == 1 )
              {
                v5 = &v34;
                v6 = &v44[v34];
              }
              else
              {
                v5 = &v33;
                v6 = &v40[4 * v33];
              }
            }
            else
            {
              v5 = &v32;
              v6 = &v43[v3];
            }
            if ( *v5 < 49 )
            {
              ++*v5;
              v3 = v32;
              *v6 = i;
            }
          }
          else
          {
            v30 = 2;
          }
        }
        else
        {
          v30 = 1;
        }
      }
      else
      {
        v30 = 0;
      }
    }
    sub_4C5E50(v2, v43, v3);
    sub_4C5FD0(v2, v44, v34);
    v32 = sub_4C6150(v2, v40, v33);
  }
  v15 = (_DWORD **)v2[2];
  v16 = 0;
  v17 = v15;
  if ( v15 )
  {
    do
    {
      v17 = (_DWORD **)v17[1];
      ++v16;
    }
    while ( v17 );
    if ( v16 >= 2 )
    {
      v18 = v16 / 2 - 1;
      v19 = v2[2];
      if ( v18 > 0 )
      {
        do
        {
          --v18;
          v19 = *(_DWORD *)(v19 + 4);
        }
        while ( v18 );
      }
      v20 = *(_DWORD *)(v19 + 4);
      v29 = v2[2];
      *(_DWORD *)(v19 + 4) = 0;
      v21 = (_DWORD **)sub_4C6810(v29);
      v22 = (_DWORD **)sub_4C6810(v20);
      v23 = v22;
      if ( v21 )
      {
        if ( v22 )
        {
          if ( sub_4C5D30(*v21, *v22) )
          {
            v31 = v21;
            v24 = v21;
            v21 = (_DWORD **)v21[1];
          }
          else
          {
            v31 = v23;
            v24 = v23;
            v23 = (_DWORD **)v23[1];
          }
          if ( v21 )
          {
            while ( v23 )
            {
              if ( sub_4C5D30(*v21, *v23) )
              {
                v25 = v21;
                v21 = (_DWORD **)v21[1];
              }
              else
              {
                v25 = v23;
                v23 = (_DWORD **)v23[1];
              }
              v24[1] = v25;
              v24 = v25;
              if ( !v21 )
                goto LABEL_50;
            }
            v2 = v35;
            v24[1] = v21;
          }
          else
          {
LABEL_50:
            v2 = v35;
            if ( v23 )
              v24[1] = v23;
            else
              v24[1] = 0;
          }
        }
        else
        {
          v31 = v21;
        }
      }
      else
      {
        v31 = v22;
      }
      v15 = v31;
    }
  }
  v2[2] = v15;
  v26 = v15;
  if ( v15 )
  {
    for ( j = v15[1]; j; j = (_DWORD *)j[1] )
      v26 = (_DWORD **)j;
  }
  v2[3] = v26;
  result = v32;
  v2[4] = v15;
  v2[4] = v2[2];
  v2[6] = 0;
  return result;
}
