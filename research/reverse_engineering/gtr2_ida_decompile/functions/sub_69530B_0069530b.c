unsigned int __thiscall sub_69530B(_DWORD *this, char *a2, unsigned int a3, int a4)
{
  _DWORD *v4; // edi
  const char *v6; // edx
  const char *v7; // eax
  int v8; // eax
  int v9; // ebx
  const char *v10; // esi
  const char *v11; // esi
  unsigned int result; // eax
  int v13; // [esp-4h] [ebp-114h]
  char v14; // [esp+Ch] [ebp-104h] BYREF
  _BYTE v15[3]; // [esp+Dh] [ebp-103h] BYREF
  char v16; // [esp+10Bh] [ebp-5h]
  const char *v17; // [esp+10Ch] [ebp-4h]

  v4 = (_DWORD *)a4;
  v17 = &v14;
  if ( !a4 )
  {
    v17 = "void";
    goto LABEL_48;
  }
  if ( *(_DWORD *)(a4 + 4) == 1 )
  {
    v10 = "const ";
    if ( !sub_6950BD(this, (_DWORD *)a4) )
      v10 = WindowName;
    v13 = sub_6951CB(this, (_DWORD *)a4);
    sub_632041((int)&v14, 255, "%sstruct{%u}", v10, v13);
LABEL_47:
    v16 = 0;
    goto LABEL_48;
  }
  if ( *(_DWORD *)(a4 + 4) != 8 )
  {
    if ( *(_DWORD *)(a4 + 4) != 9 )
    {
      v17 = "unknown";
      goto LABEL_48;
    }
    v6 = "const ";
    if ( (*(_BYTE *)(a4 + 33) & 2) == 0 )
      v6 = WindowName;
    switch ( *(_DWORD *)(a4 + 20) )
    {
      case 0:
        v7 = "bool";
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
        v7 = (const char *)&off_7413EC;
        break;
      case 9:
      case 0xB:
        v7 = "float";
        break;
      case 0xA:
        v7 = "half";
        break;
      case 0xC:
        v7 = "double";
        break;
      case 0xD:
        v7 = (const char *)&dword_72D144;
        break;
      case 0xE:
        v7 = "string";
        break;
      case 0xF:
        v7 = "texture";
        break;
      case 0x10:
        v7 = "texture1D";
        break;
      case 0x11:
        v7 = "texture2D";
        break;
      case 0x12:
        v7 = "texture3D";
        break;
      case 0x13:
        v7 = "textureCUBE";
        break;
      case 0x14:
        v7 = "sampler";
        break;
      case 0x15:
        v7 = "sampler1D";
        break;
      case 0x16:
        v7 = "sampler2D";
        break;
      case 0x17:
        v7 = "sampler3D";
        break;
      case 0x18:
        v7 = "samplerCUBE";
        break;
      case 0x19:
        v7 = "pixelshader";
        break;
      case 0x1A:
        v7 = "vertexshader";
        break;
      case 0x1B:
        v7 = "pixelfragment";
        break;
      case 0x1C:
        v7 = "vertexfragment";
        break;
      case 0x1D:
        v7 = "stateblock";
        break;
      default:
        v7 = "unknown";
        break;
    }
    if ( *(_DWORD *)(a4 + 16) == 1 )
    {
      sub_632041((int)&v14, 255, "%s%s%u", v6, v7, *(_DWORD *)(a4 + 28));
    }
    else if ( *(_DWORD *)(a4 + 16) == 2 )
    {
      sub_632041((int)&v14, 255, "%s%s%ux%u", v6, v7, *(_DWORD *)(a4 + 24), *(_DWORD *)(a4 + 28));
    }
    else
    {
      sub_632041((int)&v14, 255, "%s%s", v6, v7);
    }
    goto LABEL_47;
  }
  v8 = a4;
  do
    v8 = *(_DWORD *)(v8 + 16);
  while ( *(_DWORD *)(v8 + 4) == 8 );
  v9 = sub_69530B(&v14, 255, v8);
  while ( v4[1] == 8 )
  {
    sub_632041((int)&v15[v9 - 1], 255 - v9, "[%u]", v4[5]);
    v16 = 0;
    v4 = (_DWORD *)v4[4];
    v9 = &v15[v9 + strlen(&v15[v9 - 1])] - v15;
  }
LABEL_48:
  v11 = v17;
  result = strlen(v17);
  if ( result > a3 )
    result = a3;
  qmemcpy(a2, v17, 4 * (result >> 2));
  qmemcpy(&a2[4 * (result >> 2)], &v11[4 * (result >> 2)], result & 3);
  a2[result] = 0;
  return result;
}
