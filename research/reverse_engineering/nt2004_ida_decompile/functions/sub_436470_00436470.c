int __thiscall sub_436470(const char **this, int a2)
{
  size_t v2; // eax
  int v3; // edi
  int result; // eax
  signed int v6; // ebx
  int v7; // ebp
  char *v8; // eax
  char **v9; // edi
  char *v10; // eax
  char *v11; // ecx
  char *v12; // eax
  CHAR *v13; // edi
  CHAR *v14; // eax
  CHAR *v15; // eax
  signed int v16; // [esp+Ch] [ebp-108h]
  int v17; // [esp+10h] [ebp-104h]
  char Source[128]; // [esp+14h] [ebp-100h] BYREF
  char Destination[128]; // [esp+94h] [ebp-80h] BYREF

  v2 = NumOfElements;
  v3 = a2;
  if ( a2 < 0 || a2 >= (int)NumOfElements )
    v3 = 0;
  else
    v2 = a2 + 1;
  v16 = v2;
  result = sub_436630(Source, 128);
  v6 = v3;
  v17 = v3;
  if ( v3 < v16 )
  {
    while ( 1 )
    {
      v7 = dword_75AAD0[v6];
      if ( !*(_DWORD *)(v7 + 16584) )
        break;
      strncpy((char *)(v7 + 25120), Source, 0x7Fu);
      *(_BYTE *)(v7 + 25247) = 0;
LABEL_27:
      result = v16;
      v17 = ++v6;
      if ( v6 >= v16 )
        return result;
    }
    sub_435B70(this, (int)&unk_7663E0);
    v8 = (char *)*this;
    if ( !*this )
      v8 = &byte_629120;
    sub_57AF60(v8);
    v9 = (char **)(this + 4);
    if ( !sub_436740(Destination, 128) )
    {
      sub_578600(Destination);
      v10 = (char *)*this;
      if ( !*this )
        v10 = &byte_629120;
      v11 = *v9;
      if ( !*v9 )
        v11 = &byte_629120;
      if ( (unsigned __int8)sub_57B530(v11, v10) )
        goto LABEL_20;
      v12 = *v9;
      if ( !*v9 )
        v12 = &byte_629120;
      sub_436AB0(v12);
    }
    sub_578600(&byte_629120);
LABEL_20:
    v13 = *v9;
    if ( !v13 )
      v13 = &byte_629120;
    sub_578600(v13);
    v14 = (CHAR *)*this;
    if ( !*this )
      v14 = &byte_629120;
    strncpy((char *)(v7 + 25120), v14, 0x7Fu);
    *(_BYTE *)(v7 + 25247) = 0;
    v15 = (CHAR *)*this;
    if ( !*this )
      v15 = &byte_629120;
    sub_436C00((char)v15, 0);
    v6 = v17;
    goto LABEL_27;
  }
  return result;
}
