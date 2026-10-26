int __thiscall sub_4B06B0(_DWORD *this, int a2)
{
  const char *v3; // ecx
  bool v4; // zf
  char *v5; // eax
  char *v6; // edi
  char v7; // cl
  _DWORD *v8; // esi
  int v9; // edx
  int result; // eax
  int v11; // [esp+8h] [ebp-10Ch] BYREF
  int v12; // [esp+Ch] [ebp-108h] BYREF
  _BYTE v13[4]; // [esp+10h] [ebp-104h] BYREF
  char v14[256]; // [esp+14h] [ebp-100h] BYREF

  sub_578600(a2);
  v3 = (const char *)*this;
  v4 = *this == 0;
  v12 = 0;
  v11 = 0;
  if ( v4 )
    v3 = &byte_629120;
  strcpy(v14, v3);
  v5 = &v14[strlen(v14)];
  if ( v5 > v14 )
  {
    while ( *v5 != 46 )
    {
      if ( --v5 <= v14 )
        goto LABEL_8;
    }
    *v5 = 0;
  }
LABEL_8:
  v6 = &v14[strlen(v14) + 1];
  v7 = byte_608FDC;
  *(_DWORD *)--v6 = *(_DWORD *)dword_608FD8;
  v8 = this + 8;
  v6[4] = v7;
  if ( sub_592340((char)v14, &v12, &v11, this + 8, v13) )
  {
    sub_592340(a2, &v12, &v11, this + 8, v13);
    *v8 = 8;
  }
  else
  {
    sub_578600(v14);
  }
  v9 = v12;
  result = v11;
  *v8 = 8;
  this[5] = v9;
  this[6] = result;
  return result;
}
