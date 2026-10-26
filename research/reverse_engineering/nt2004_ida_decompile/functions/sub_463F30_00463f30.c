char __thiscall sub_463F30(int *this, char *Source, char *a3)
{
  int v4; // ecx
  char *v5; // esi
  int v6; // ecx
  int v7; // esi
  _DWORD *v8; // ebx
  LPVOID *v9; // edi
  char v10; // al
  char *v11; // eax
  const char *v12; // edx
  char *v13; // ebx
  const char *v14; // ecx
  char ***v15; // esi
  char **v16; // eax
  char v17; // bl
  int v19[12]; // [esp-38h] [ebp-50h] BYREF
  char v20; // [esp+13h] [ebp-5h]
  int v21; // [esp+14h] [ebp-4h]

  v4 = *(_DWORD *)(*this + 6708);
  v20 = 0;
  v5 = (char *)sub_56A5B0(v4);
  v21 = (int)v5;
  strncpy(v5 + 8, Source, 0x1Fu);
  v5[39] = 0;
  v5[40] = 1;
  v6 = *(_DWORD *)(*this + 396);
  if ( v6 <= 0 )
  {
    v5[43] = dword_769998;
    Source[70] = dword_769998;
  }
  else
  {
    v5[43] = v6;
    Source[70] = *(_BYTE *)(*this + 396);
  }
  sub_569F30(Source, 92);
  qmemcpy((void *)(*this + 44), Source, 0x5Cu);
  sub_465200(a3);
  qmemcpy(v19, &unk_764D84, sizeof(v19));
  if ( sub_56A220(
         v19[0],
         v19[1],
         v19[2],
         v19[3],
         v19[4],
         v19[5],
         v19[6],
         v19[7],
         v19[8],
         v19[9],
         v19[10],
         v19[11],
         v21,
         a3) )
  {
    v17 = v20;
  }
  else
  {
    if ( sub_462D10(Source, 0) )
      *(_DWORD *)(*this + 6720) = 1;
    else
      *(_DWORD *)(*this + 6720) = 2;
    sub_45FDB0(*this);
    v7 = *(_DWORD *)(*this + 6724);
    v8 = (_DWORD *)(*this + 6724);
    while ( v7 )
    {
      v9 = (LPVOID *)v7;
      v10 = *(_BYTE *)(v7 + 8);
      v7 = *(_DWORD *)(v7 + 4);
      if ( v10 )
        sub_5BE8AE(*v9);
      sub_5BE8AE(v9);
    }
    *v8 = 0;
    v8[1] = 0;
    v8[2] = 0;
    v8[3] = 0;
    if ( !sub_4634F0(this) )
    {
      v11 = (char *)operator new(0x84u);
      v12 = dword_7665D8;
      v13 = v11;
      if ( !dword_7665D8 )
        v12 = &byte_629120;
      v14 = &v12[strlen(v12)];
      if ( v14 > v12 )
      {
        while ( *v14 != 92 )
        {
          if ( --v14 <= v12 )
            goto LABEL_20;
        }
        ++v14;
      }
LABEL_20:
      strncpy(v11, v14, 0x7Fu);
      v13[127] = 0;
      *((_DWORD *)v13 + 32) = sub_463B50(this);
      v15 = (char ***)(*this + 6724);
      v16 = (char **)operator new(0xCu);
      if ( v16 )
      {
        *v16 = v13;
        v16[1] = 0;
        *((_BYTE *)v16 + 8) = 1;
      }
      else
      {
        v16 = 0;
      }
      if ( *v15 )
      {
        v15[1][1] = (char *)v16;
      }
      else
      {
        *v15 = v16;
        v15[2] = v16;
      }
      v15[1] = v16;
      v15[3] = (char **)((char *)v15[3] + 1);
    }
    sub_45D700((_BYTE *)(*this + 30092));
    v17 = 1;
  }
  sub_56A5E0(*(_DWORD *)(*this + 6708), v21);
  return v17;
}
