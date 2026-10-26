char __thiscall sub_4BA1F0(_DWORD *this)
{
  bool v2; // bl
  int *v3; // esi
  char *v4; // edi
  int v5; // edx
  int v6; // eax
  char v7; // cl
  const CHAR *v8; // eax
  char *v9; // eax
  int v10; // eax
  char *v11; // eax
  char result; // al
  int v13; // eax
  int v14; // eax
  int v15; // edi
  _DWORD *v16; // ecx
  float v17; // edx
  float v18; // [esp+4h] [ebp-444h] BYREF
  LPVOID v19[2]; // [esp+8h] [ebp-440h] BYREF
  _BYTE v20[28]; // [esp+10h] [ebp-438h] BYREF
  _BYTE v21[28]; // [esp+2Ch] [ebp-41Ch] BYREF
  _BYTE v22[1024]; // [esp+48h] [ebp-400h] BYREF

  if ( *this == 2 )
  {
    v2 = 0;
    if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_22, 5513) )
      sub_4D7AA0(&unk_8AD25C, aLoadingVcrFile);
    v3 = this + 2;
    v4 = *(char **)(this[2] + 3988);
    if ( !v4 )
      v4 = byte_5EA438;
    sub_5668B0(v21);
    if ( !(unsigned __int8)sub_566B20(v4, 0) )
      goto LABEL_24;
    if ( sub_423A00(byte_5EC4C0, aPreppingReplay, byte_5EC4CC) )
    {
      v6 = 0;
      do
      {
        v7 = aPreppingReplay[v6];
        byte_5EC4CC[v6++] = v7;
      }
      while ( v7 );
    }
    sub_4A0E70((int)&unk_7CE24D, v5, byte_5EC4CC);
    Sleep(0xFAu);
    v19[0] = (LPVOID)sub_587C03(128);
    *(_BYTE *)v19[0] = 0;
    v19[1] = (LPVOID)128;
    sub_4B9830((int)v19);
    v8 = (const CHAR *)v19[0];
    if ( !v19[0] )
      v8 = byte_5EA438;
    sub_568540(v8);
    sub_5668B0(v20);
    v9 = (char *)v19[0];
    if ( !v19[0] )
      v9 = byte_5EA438;
    if ( (unsigned __int8)sub_566940(v9, 0, 0, 1) )
    {
      while ( 1 )
      {
        v10 = sub_566C00(v22, 1024);
        if ( v10 <= 0 )
          break;
        sub_566BD0(v22, v10);
      }
      sub_566B90(v20);
      sub_566B90(v21);
      v11 = (char *)v19[0];
      if ( !v19[0] )
        v11 = byte_5EA438;
      v2 = sub_4B97D0(this + 2, (int)v11, 0);
      if ( v2 )
      {
        sub_4B9810((_DWORD **)this + 2);
        *this = 2;
        sub_4B9DA0(this + 2, 5);
      }
    }
    sub_5668D0(v20);
    if ( v19[0] )
      sub_587BCF(v19[0]);
    if ( v2 )
    {
      v13 = sub_4B9820(this + 2);
      sub_42BBD0(v13);
      v14 = sub_4B9820(this + 2);
      sub_42BC40(v14);
      v15 = *v3;
      v16 = (_DWORD *)*v3;
      v18 = 0.0;
      sub_4B87A0(v16, &v18, v19);
      v17 = v18;
      *(float *)(v15 + 3900) = v18;
      sub_4B86E0(*v3, v17);
      return sub_5668D0(v21);
    }
    else
    {
LABEL_24:
      *this = 0;
      return sub_5668D0(v21);
    }
  }
  else
  {
    result = sub_404F10(&dword_5EA43C);
    *this = !result && ((result = dword_7D0038, dword_7D0038) || (result = dword_7D005C, dword_7D005C));
  }
  return result;
}
