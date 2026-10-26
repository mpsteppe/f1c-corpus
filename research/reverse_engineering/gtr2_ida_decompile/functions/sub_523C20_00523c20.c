bool __thiscall sub_523C20(_DWORD *this, int a2)
{
  const char *v3; // ecx
  bool v4; // zf
  const char *v5; // eax
  bool v6; // bl
  int v8; // [esp+8h] [ebp-16Ch] BYREF
  _BYTE v9[92]; // [esp+Ch] [ebp-168h] BYREF
  char v10[256]; // [esp+68h] [ebp-10Ch] BYREF
  int v11; // [esp+170h] [ebp-4h]

  sub_613B30(v9);
  v11 = 0;
  if ( !(unsigned __int8)sub_614460(a2, 0) || 0.0 == sub_520EB0((_DWORD *)this[6], COERCE_FLOAT(v9)) )
  {
    v11 = -1;
    sub_614140(v9);
    return 0;
  }
  else
  {
    sub_613CE0(&v8, 4);
    sub_613CE0(v10, v8);
    v3 = dword_B6F68C;
    v4 = dword_B6F68C == 0;
    v10[v8] = 0;
    if ( v4 )
      v3 = WindowName;
    v5 = &v3[strlen(v3)];
    if ( v5 > v3 )
    {
      while ( *v5 != 92 )
      {
        if ( --v5 <= v3 )
          goto LABEL_10;
      }
      ++v5;
    }
LABEL_10:
    v6 = strcmp(v10, v5) == 0;
    v11 = -1;
    sub_614140(v9);
    return v6;
  }
}
